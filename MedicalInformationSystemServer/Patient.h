#ifndef PATIENT_H
#define PARIENT_H
#pragma once

#include <iostream>

namespace MedicalInformationSystemServer {
	class Patient
	{
	public:
		Patient();
		Patient(std::string id, std::string name, std::string surname, std::string birthday, std::string gender, std::string observations);
		Patient(const Patient&);
		~Patient();
	private:
		std::string id;
		std::string name;
		std::string surname;
		std::string birthday;
		std::string gender;
		std::string observations;
	public:
		void setId(std::string id);
		std::string getId();
		void setName(std::string name);
		std::string getName();
		void setSurname(std::string surname);
		std::string getSurname();
		void setBirthday(std::string birthday);
		std::string getBirthday();
		void setGender(std::string gender);
		std::string getGender();
		void setObservations(std::string observations);
		std::string getObservations();
		std::string toString();
		void fromString(std::string patientData);
	};
}
#endif