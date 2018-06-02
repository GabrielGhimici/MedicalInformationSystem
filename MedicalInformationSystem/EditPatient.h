#pragma once

#include <winsock2.h>
#include <iostream>
#include "Doctor.h"
#include "Patient.h"
#include "MainView.h"

namespace MedicalInformationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class EditPatient : public System::Windows::Forms::Form
	{
	public:
		EditPatient(void);
		EditPatient(SOCKET sock);
		EditPatient(SOCKET sock, Doctor *doctor, std::string patientId, MainView ^parent);

	protected:
		~EditPatient();
	private: 
		System::Windows::Forms::Label^  LoggedAs;
	private: 
		System::Windows::Forms::Label^  Title;
	private: 
		System::Windows::Forms::Label^  PatientLabel;
	private: 
		System::Windows::Forms::Label^  ObsLabel;
	private: 
		System::Windows::Forms::Label^  GenderLabel;
	private: 
		System::Windows::Forms::Label^  BirthdayLabel;
	private: 
		System::Windows::Forms::Label^  SurnameLabel;
	private: 
		System::Windows::Forms::Label^  NameLabel;
	private: 
		System::Windows::Forms::Button^  SaveButt;
	private: 
		System::Windows::Forms::Button^  BackButt;
	private: 
		System::Windows::Forms::TextBox^  PName;
	private: 
		System::Windows::Forms::TextBox^  PGender;
	private: 
		System::Windows::Forms::TextBox^  PBirthday;
	private: 
		System::Windows::Forms::TextBox^  PSurname;
	private: System::Windows::Forms::TextBox^  PObservations;
	private:
		MainView ^parent;
	private:
		SOCKET sock;
	private:
		Doctor *currentDoctor;
	private:
		System::String ^patientId;
	private:
		Patient *currentPatient;
	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void);
	private: 
		System::Void SaveButt_Click(System::Object^  sender, System::EventArgs^  e);
	private: 
		System::Void BackButt_Click(System::Object^  sender, System::EventArgs^  e);
	private: 
		System::Void EditPatient_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
