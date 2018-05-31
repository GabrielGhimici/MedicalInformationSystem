#include "Doctor.h"

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