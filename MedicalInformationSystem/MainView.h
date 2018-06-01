#pragma once

#include <winsock2.h>
#include <iostream>
#include "Doctor.h"

namespace MedicalInformationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainView : public System::Windows::Forms::Form
	{
	public:
		MainView(void);
		MainView(SOCKET sock);
		MainView(SOCKET sock, Doctor *newDoctor);
	protected:
		~MainView();
	private: 
		System::Windows::Forms::Label^  Title;
	private: 
		System::Windows::Forms::Label^  LoggedAs;
	private: 
		System::Windows::Forms::Panel^  MainContent;
	private: 
		System::Windows::Forms::Button^  PrevButt;
	private: 
		System::Windows::Forms::Button^  EditButt;
	private: 
		System::Windows::Forms::Button^  NextButt;
	private: 
		System::Windows::Forms::Label^  NameLabel;
	private: 
		System::Windows::Forms::Label^  SurnameLabel;
	private: 
		System::Windows::Forms::Label^  GenderLabel;
	private: 
		System::Windows::Forms::Label^  BirthdayLabel;
	private: 
		System::Windows::Forms::Label^  ObsLabel;
	private: 
		System::Windows::Forms::Label^  PSurname;
	private: 
		System::Windows::Forms::Label^  PName;
	private: 
		System::Windows::Forms::Label^  PObservations;
	private: 
		System::Windows::Forms::Label^  PGender;
	private: 
		System::Windows::Forms::Label^  PBirthday;
	private:
		SOCKET sock;
	private:
		Doctor *currentDoctor;
	private:
		int patientIndex;
	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void);
	private: 
		System::Void MainView_Load(System::Object^  sender, System::EventArgs^  e);
	private: 
		System::Void NextButt_Click(System::Object^  sender, System::EventArgs^  e);
	private: 
		System::Void PrevButt_Click(System::Object^  sender, System::EventArgs^  e);
	private:
		System::Void EditButt_Click(System::Object^  sender, System::EventArgs^  e);
	private:
		System::Void setupPatientView();
};
}
