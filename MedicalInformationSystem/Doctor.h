#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <vector>
#include "Patient.h"

namespace MedicalInformationSystem {
	class Doctor
	{
	public:
		Doctor();
		Doctor(std::string id, std::string username, std::string password, std::vector<Patient> patients);
		Doctor(const Doctor&);
		~Doctor();
	private:
		std::string id;
		std::string username;
		std::string password;
		std::vector<Patient> patients;
	public:
		void setId(std::string id);
		std::string getId();
		void setUsername(std::string username);
		std::string getUsername();
		void setPassword(std::string password);
		std::string getPassword();
		void setPatients(std::vector<Patient> patients);
		std::vector<Patient> getPatients();
		std::string toString();
	};
}

#endif