#include "Patient.h"

MedicalInformationSystem::Patient::Patient() {}

MedicalInformationSystem::Patient::Patient(std::string id, std::string name, std::string surname, std::string birthday, std::string gender, std::string observations) {
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->birthday = birthday;
	this->gender = gender;
	this->observations = observations;
}

MedicalInformationSystem::Patient::Patient(const Patient &patient) {
	this->id = patient.id;
	this->name = patient.name;
	this->surname = patient.surname;
	this->birthday = patient.birthday;
	this->gender = patient.gender;
	this->observations = patient.observations;
}

MedicalInformationSystem::Patient::~Patient() {}

void MedicalInformationSystem::Patient::setId(std::string id) {
	this->id = id;
}

std::string MedicalInformationSystem::Patient::getId() {
	return this->id;
}

void MedicalInformationSystem::Patient::setName(std::string name) {
	this->name = name;
}

std::string MedicalInformationSystem::Patient::getName() {
	return this->name;
}

void MedicalInformationSystem::Patient::setSurname(std::string surname) {
	this->surname = surname;
}

std::string MedicalInformationSystem::Patient::getSurname() {
	return this->surname;
}
void MedicalInformationSystem::Patient::setBirthday(std::string birthday) {
	this->birthday = birthday;
}
std::string MedicalInformationSystem::Patient::getBirthday() {
	return this->birthday;
}
void MedicalInformationSystem::Patient::setGender(std::string gender) {
	this->gender = gender;
}
std::string MedicalInformationSystem::Patient::getGender() {
	return this->gender;
}
void MedicalInformationSystem::Patient::setObservations(std::string observations) {
	this->observations = observations;
}

std::string MedicalInformationSystem::Patient::getObservations() {
	return this->observations;
}

std::string MedicalInformationSystem::Patient::toString() {
	const std::string id = "Id&" + this->id;
	const std::string name = "Name&" + this->name;
	const std::string surname = "Surname&" + this->surname;
	const std::string birthday = "Birthday&" + this->birthday;
	const std::string gender = "Gender&" + this->gender;
	const std::string observations = "Observations&" + this->observations;
	return id + "`" + name + "`" + surname + "`" + birthday + "`" + gender + "`" + observations;
}

void MedicalInformationSystem::Patient::fromString(std::string patientData) {
	std::vector<std::string> patientTokens = MedicalInformationSystem::Tokenizer::tokenize(patientData, '`');
	if (patientTokens.size() < 6) {
		System::Diagnostics::Debug::WriteLine("Imposible to populate patient");
		return;
	}
	this->id = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[0], '&')[1];
	this->name = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[1], '&')[1];
	this->surname = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[2], '&')[1];
	this->birthday = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[3], '&')[1];
	this->gender = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[4], '&')[1];
	this->observations = MedicalInformationSystem::Tokenizer::tokenize(patientTokens[5], '&')[1];
}