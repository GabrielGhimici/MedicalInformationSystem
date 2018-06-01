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

void MedicalInformationSystem::Doctor::fromString(std::string docString) {
	std::vector<std::string> doctorTokens = MedicalInformationSystem::Tokenizer::tokenize(docString, '#');
	if (doctorTokens.size() < 4) {
		System::Diagnostics::Debug::WriteLine("Imposible to populate doctor");
		return;
	}
	this->id = MedicalInformationSystem::Tokenizer::tokenize(doctorTokens[0], '~')[1];
	this->username = MedicalInformationSystem::Tokenizer::tokenize(doctorTokens[1], '~')[1];
	this->password = MedicalInformationSystem::Tokenizer::tokenize(doctorTokens[2], '~')[1];
	this->patients = {};
	std::vector<std::string> patientsInfo = MedicalInformationSystem::Tokenizer::tokenize(doctorTokens[3], '~');
	for(std::string s: patientsInfo) {
		MedicalInformationSystem::Patient p = MedicalInformationSystem::Patient();
		p.fromString(s);
		this->patients.push_back(p);
	}
}