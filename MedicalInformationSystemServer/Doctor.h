#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <vector>

namespace MedicalInformationSystemServer {
	class Doctor
	{
	public:
		Doctor();
		Doctor(std::string id, std::string username, std::string password, std::vector<std::string> patients);
		Doctor(const Doctor&);
		~Doctor();
	private:
		std::string id;
		std::string username;
		std::string password;
		std::vector<std::string> patients;
	public:
		void fromString(std::string docString);
		void setId(std::string id);
		std::string getId();
		void setUsername(std::string username);
		std::string getUsername();
		void setPassword(std::string password);
		std::string getPassword();
		void setPatients(std::vector<std::string> patients);
		std::vector<std::string> getPatients();
		std::string toString();
	};
}

#endif