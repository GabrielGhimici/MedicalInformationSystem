#include "Patient.h"

MedicalInformationSystemServer::Patient::Patient() {}

MedicalInformationSystemServer::Patient::Patient(std::string name, std::string surname, std::string birthday, std::string gender, std::string observations) {
	this->name = name;
	this->surname = surname;
	this->birthday = birthday;
	this->gender = gender;
	this->observations = observations;
}

MedicalInformationSystemServer::Patient::Patient(const Patient &patient) {
	this->name = patient.name;
	this->surname = patient.surname;
	this->birthday = patient.birthday;
	this->gender = patient.gender;
	this->observations = patient.observations;
}

MedicalInformationSystemServer::Patient::~Patient() {}

void MedicalInformationSystemServer::Patient::setName(std::string name) {
	this->name = name;
}

std::string MedicalInformationSystemServer::Patient::getName() {
	return this->name;
}

void MedicalInformationSystemServer::Patient::setSurname(std::string surname) {
	this->surname = surname;
}

std::string MedicalInformationSystemServer::Patient::getSurname() {
	return this->surname;
}
void MedicalInformationSystemServer::Patient::setBirthday(std::string birthday) {
	this->birthday = birthday;
}
std::string MedicalInformationSystemServer::Patient::getBirthday() {
	return this->birthday;
}
void MedicalInformationSystemServer::Patient::setGender(std::string gender) {
	this->gender = gender;
}
std::string MedicalInformationSystemServer::Patient::getGender() {
	return this->gender;
}
void MedicalInformationSystemServer::Patient::setObservations(std::string observations) {
	this->observations = observations;
}

std::string MedicalInformationSystemServer::Patient::getObservations() {
	return this->observations;
}

std::string MedicalInformationSystemServer::Patient::toString() {
	const std::string name = "Name%" + this->name;
	const std::string surname = "Surname%" + this->surname;
	const std::string birthday = "Birthday%" + this->birthday;
	const std::string gender = "Gender%" + this->gender;
	const std::string observations = "Observaions%" + this->observations;
	return name + "`" + surname + "`" + birthday + "`" + gender + "`" + observations;
}