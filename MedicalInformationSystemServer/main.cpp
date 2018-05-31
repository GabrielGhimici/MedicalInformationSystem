#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <process.h>
#include "Doctor.h"
#include "Patient.h"
#include "Tokenizer.h"
#pragma comment(lib, "ws2_32.lib" )

#include "Tokenizer.h"

std::vector<MedicalInformationSystemServer::Doctor> doctors;
std::map<std::string, MedicalInformationSystemServer::Patient> patients;

unsigned int __stdcall  ServClient(void *data);
int processDoctors(std::vector<std::string> ids);
int processPatients(std::vector<std::string> ids);
int processInitialFile();

enum InternalMessages {UNDEFINED_MESSAGE, LOGIN_MESSAGE, GET_INITIAL_DATA};

inline std::string ToString(InternalMessages message)
{
	switch (message)
	{
	case LOGIN_MESSAGE:   
		return "LOGIN";
	case GET_INITIAL_DATA:
		return "GET_INITIAL_DATA";
	default:      
		return "[UM]";
	}
}

inline InternalMessages FromString(std::string str)
{
	if (str == "LOGIN") return LOGIN_MESSAGE;
	if (str == "GET_INITIAL_DATA") return GET_INITIAL_DATA;
	return UNDEFINED_MESSAGE;
}

int main(int argc, char* argv[])
{

	WSADATA wsaData;
	int iResult;
	sockaddr_in address;
	SOCKET sock, client;

	address.sin_family = AF_INET;
	address.sin_port = htons(2222);
	address.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult)
	{
		std::cout << "WSA startup failed" << std::endl;
		return 0;
	}
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		std::cout << "Invalid socket" << std::endl;
		system("pause");
		return 0;
	}
	iResult = bind(sock, (sockaddr*)&address, sizeof(sockaddr_in));
	if (iResult)
	{
		std::cout << "Bind failed " << GetLastError() << std::endl;
		system("pause");
		return 0;
	}
	iResult = listen(sock, SOMAXCONN);
	if (iResult)
	{
		std::cout << "iResult failed " << GetLastError() << std::endl;
		system("pause");
		return 0;
	}

	std::cout << "Server started!" << std::endl;
	std::cout << "Listenind on: 127.0.0.1:2222" << std::endl;

	if (processInitialFile() == -1) {
		std::cout << "Unable to setup initial data" << std::endl;
		system("pause");
		return 0;
	}

	while (client = accept(sock, 0, 0))
	{
		if (client == INVALID_SOCKET)
		{
			std::cout << "Invalid client socket " << GetLastError() << std::endl;
			continue;
		}
		_beginthreadex(0, 0, ServClient, (void*)&client, 0, 0);
	}
	return 0;
}

unsigned int __stdcall ServClient(void *data)
{
	SOCKET* client = (SOCKET*)data;
	SOCKET Client = *client;
	std::cout << "Client connected " << GetCurrentThreadId() << std::endl;
	char chunk[5000];
	std::vector<std::string> doctorProperties(2, "");
	std::vector<std::vector<std::string>> doctorDetails(2, {"",""});
	bool doctorExists;
	std::string doctorId;
	std::vector<std::string> patientIdList;
	std::string patientsInformation;
	while (recv(Client, chunk, 5000, 0))
	{
		std::string message(chunk);
		std::vector<std::string> messageTokens = MedicalInformationSystemServer::Tokenizer::tokenize(message, '>');
		switch (FromString(messageTokens[0]))
		{
		case UNDEFINED_MESSAGE:
			std::cout << chunk << std::endl;
			break;
		case LOGIN_MESSAGE:
			std::cout << ">>> Login as " << messageTokens[1].c_str() << std::endl;
			doctorProperties = MedicalInformationSystemServer::Tokenizer::tokenize(messageTokens[1], '#');
			for (int i = 0; i < doctorProperties.size(); i++) {
				doctorDetails[i] = MedicalInformationSystemServer::Tokenizer::tokenize(doctorProperties[i], '~');
			}
			doctorExists = false;
			doctorId = "";
			for (MedicalInformationSystemServer::Doctor d : doctors) {
				if (d.getUsername() == doctorDetails[0][1] && d.getPassword() == doctorDetails[1][1]) {
					doctorExists = true;
					doctorId = d.getId();
					break;
				}
			}
			char logingResponse[5000];
			if (doctorExists == true) {
				sprintf(logingResponse, "%s>%s", "OK", doctorId.c_str());
				std::cout << ">>> Response send... OK" << std::endl;
				send(Client, logingResponse, 5000, 0);
			}
			else {
				sprintf(logingResponse, "Login informations are invalid!");
				std::cout << ">>> Response send... NOT_OK" << std::endl;
				send(Client, logingResponse, 5000, 0);
			}
			break;
		case GET_INITIAL_DATA:
			std::cout << ">>> Get initial info for: " << messageTokens[1].c_str() << std::endl;
			for (MedicalInformationSystemServer::Doctor d : doctors) {
				if (d.getId() == messageTokens[1]) {
					patientIdList = d.getPatients();
					break;
				}
			}
			patientsInformation = "";
			for (std::string id : patientIdList) {
				patientsInformation = patientsInformation + patients[id].toString();
				patientsInformation = patientsInformation + "~";
			}
			patientsInformation = patientsInformation.substr(0, patientsInformation.length() - 1);
			char infoResponse[5000];
			sprintf(infoResponse, "%s", patientsInformation.c_str());
			std::cout << ">>> Response send... PATIENT INFO" << std::endl;
			send(Client, infoResponse, 5000, 0);
			break;
		default:
			break;
		}
	}
	return 0;
}

int processInitialFile() {
	std::ifstream infile("../resources/initialFile.txt");
	if (infile) {
		std::string doctors;
		std::string patients;
		std::getline(infile, doctors);
		std::getline(infile, patients);
		if (doctors.length() == 0 || patients.length() == 0) {
			std::cout << ">>> Problem with retrieving initial doctors or patients data..." << std::endl;
			return -1;
		}
		std::cout << ">>> Initial data loaded sucessfully..." << std::endl;
		if (processDoctors(MedicalInformationSystemServer::Tokenizer::tokenize(doctors, '%')) == -1) {
			std::cout << ">>> Problem with setting up doctor informations..." << std::endl;
			return -1;
		}
		std::cout << ">>> Doctor informations loaded sucessfully..." << std::endl;
		if (processPatients(MedicalInformationSystemServer::Tokenizer::tokenize(patients, '~')) == -1) {
			std::cout << ">>> Problem with setting up patients informations..." << std::endl;
			return -1;
		}
		std::cout << ">>> Patients informations loaded sucessfully..." << std::endl;
	}
	else {
		return -1;
	}
	return 0;
}

int processDoctors(std::vector<std::string> ids) {
	const std::string basePath = "../resources/doctor/";
	for (std::string id : ids) {
		std::ifstream doc(basePath + id + ".txt");
		if (doc) {
			std::string username;
			std::string password;
			std::string patients;
			std::getline(doc, username);
			std::getline(doc, password);
			std::getline(doc, patients);
			if (username.length() == 0 || password.length() == 0 || patients.length() == 0) {
				std::cout << ">>> One(more) information(s) for a doctor is(are) incomplete..." << std::endl;
				return -1;
			}
			doctors.push_back(MedicalInformationSystemServer::Doctor(id, username, password, MedicalInformationSystemServer::Tokenizer::tokenize(patients, '%')));
		}
		else
		{
			return -1;
		}
	}
	/*
	for (MedicalInformationSystemServer::Doctor d : doctors) {
		std::cout << d.toString() << std::endl;
	}
	*/
	return 0;
}

int processPatients(std::vector<std::string> ids) {
	const std::string basePath = "../resources/patient/";
	for (std::string id : ids) {
		std::ifstream pat(basePath + id + ".txt");
		if (pat) {
			std::string name;
			std::string surname;
			std::string birthday;
			std::string gender;
			std::string observations;
			std::getline(pat, name);
			std::getline(pat, surname);
			std::getline(pat, birthday);
			std::getline(pat, gender);
			std::getline(pat, observations);
			if (name.length() == 0 || surname.length() == 0 || birthday.length() == 0 || gender.length() == 0 || observations.length() == 0) {
				std::cout << ">>> One(more) information(s) for a patient is(are) incomplete..." << std::endl;
				return -1;
			}
			patients[id] = MedicalInformationSystemServer::Patient(id, name, surname, birthday, gender, observations);
		}
		else
		{
			return -1;
		}
	}
	/*
	for (const std::pair<std::string, MedicalInformationSystemServer::Patient> pair : patients) {
		MedicalInformationSystemServer::Patient p = pair.second;
		std::cout << pair.first << ": " << p.toString() << '\n';
	}
	*/
	return 0;
}