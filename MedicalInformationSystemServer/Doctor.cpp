#include "Doctor.h"
#include "Tokenizer.h"
#include "Patient.h"

MedicalInformationSystemServer::Doctor::Doctor() {}

MedicalInformationSystemServer::Doctor::Doctor(std::string id, std::string username, std::string password, std::vector<std::string> patients) {
	this->id = id;
	this->username = username;
	this->password = password;
	this->patients = patients;
}

MedicalInformationSystemServer::Doctor::Doctor(const Doctor &doctor) {
	this->id = doctor.id;
	this->username = doctor.username;
	this->password = doctor.password;
	this->patients = doctor.patients;
}

MedicalInformationSystemServer::Doctor::~Doctor() {}

void MedicalInformationSystemServer::Doctor::setId(std::string id) {
	this->id = id;
}

std::string MedicalInformationSystemServer::Doctor::getId() {
	return this->id;
}

void MedicalInformationSystemServer::Doctor::setUsername(std::string username) {
	this->username = username;
}

std::string MedicalInformationSystemServer::Doctor::getUsername() {
	return this->username;
}

void MedicalInformationSystemServer::Doctor::setPassword(std::string password) {
	this->password = password;
}

std::string MedicalInformationSystemServer::Doctor::getPassword() {
	return this->password;
}

void MedicalInformationSystemServer::Doctor::setPatients(std::vector<std::string> patients) {
	this->patients = patients;
}

std::vector<std::string> MedicalInformationSystemServer::Doctor::getPatients() {
	return this->patients;
}

std::string MedicalInformationSystemServer::Doctor::toString() {
	const std::string id = "Id~" + this->id;
	const std::string username = "Username~" + this->username;
	const std::string password = "Password~" + this->password;
	std::string patients = "Patients~";
	for (std::string p : this->patients) {
		patients += p;
		patients += '^';
	}
	patients = patients.substr(0, patients.length() - 1);
	return id + "#" + username + "#" + password + "#" + patients;
}

void MedicalInformationSystemServer::Doctor::fromString(std::string docString) {
	std::vector<std::string> doctorTokens = MedicalInformationSystemServer::Tokenizer::tokenize(docString, '#');
	if (doctorTokens.size() < 4) {
		std::cout << ">>> Imposible to populate doctor..." << std::endl;
		return;
	}
	this->id = MedicalInformationSystemServer::Tokenizer::tokenize(doctorTokens[0], '~')[1];
	this->username = MedicalInformationSystemServer::Tokenizer::tokenize(doctorTokens[1], '~')[1];
	this->password = MedicalInformationSystemServer::Tokenizer::tokenize(doctorTokens[2], '~')[1];
	this->patients = {};
	std::vector<std::string> patientsInfo = MedicalInformationSystemServer::Tokenizer::tokenize(doctorTokens[3], '~');
	for (std::string s : patientsInfo) {
		MedicalInformationSystemServer::Patient *p = new MedicalInformationSystemServer::Patient();
		p->fromString(s);
		this->patients.push_back(p->getId());
	}
}
