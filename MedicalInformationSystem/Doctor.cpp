#include "Doctor.h"

MedicalInformationSystem::Doctor::Doctor() {}

MedicalInformationSystem::Doctor::Doctor(std::string id, std::string username, std::string password, std::vector<Patient> patients) {
	this->id = id;
	this->username = username;
	this->password = password;
	this->patients = patients;
}

MedicalInformationSystem::Doctor::Doctor(const Doctor &doctor) {
	this->id = doctor.id;
	this->username = doctor.username;
	this->password = doctor.password;
	this->patients = doctor.patients;
}

MedicalInformationSystem::Doctor::~Doctor() {}

void MedicalInformationSystem::Doctor::setId(std::string id) {
	this->id = id;
}

std::string MedicalInformationSystem::Doctor::getId() {
	return this->id;
}

void MedicalInformationSystem::Doctor::setUsername(std::string username) {
	this->username = username;
}

std::string MedicalInformationSystem::Doctor::getUsername() {
	return this->username;
}

void MedicalInformationSystem::Doctor::setPassword(std::string password) {
	this->password = password;
}

std::string MedicalInformationSystem::Doctor::getPassword() {
	return this->password;
}

void MedicalInformationSystem::Doctor::setPatients(std::vector<Patient> patients) {
	this->patients = patients;
}

std::vector<MedicalInformationSystem::Patient> MedicalInformationSystem::Doctor::getPatients() {
	return this->patients;
}

std::string MedicalInformationSystem::Doctor::toString() {
	const std::string id = "Id~" + this->id;
	const std::string username = "Username~" + this->username;
	const std::string password = "Password~" + this->password;
	std::string patients = "Patients~";
	for (MedicalInformationSystem::Patient p : this->patients) {
		patients += p.toString();
		patients += '^';
	}
	patients = patients.substr(0, patients.length() - 1);
	return id + "#" + username + "#" + password + "#" + patients;
}