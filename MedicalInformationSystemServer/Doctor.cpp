#include "Doctor.h"

MedicalInformationSystemServer::Doctor::Doctor() {}

MedicalInformationSystemServer::Doctor::Doctor(std::string username, std::string password, std::vector<Patient> patients) {
	this->username = username;
	this->password = password;
	this->patients = patients;
}

MedicalInformationSystemServer::Doctor::Doctor(const Doctor &doctor) {
	this->username = doctor.username;
	this->password = doctor.password;
	this->patients = doctor.patients;
}

MedicalInformationSystemServer::Doctor::~Doctor() {}

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

void MedicalInformationSystemServer::Doctor::setPatients(std::vector<Patient> patients) {
	this->patients = patients;
}

std::vector<MedicalInformationSystemServer::Patient> MedicalInformationSystemServer::Doctor::getPatients() {
	return this->patients;
}

std::string MedicalInformationSystemServer::Doctor::toString() {
	const std::string username = "Username~" + this->username;
	const std::string password = "Password~" + this->password;
	std::string patients = "Patients~";
	for (MedicalInformationSystemServer::Patient p : this->patients) {
		patients += p.toString();
		patients += '^';
	}
	patients = patients.substr(0, patients.length() - 1);
	return username + "#" + password + "#" + patients;
}