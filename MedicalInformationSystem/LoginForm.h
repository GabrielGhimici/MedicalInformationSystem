#pragma once

#include <winsock2.h>
#include <iostream>

namespace MedicalInformationSystem {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void);
		LoginForm(SOCKET);
	protected:
		~LoginForm();
	private: 
		System::Windows::Forms::Label^  TitleLabel;
	private: 
		System::Windows::Forms::TextBox^  Username;
	private: 
		System::Windows::Forms::TextBox^  Password;
	private: 
		System::Windows::Forms::Label^  UsernameLabel;
	private: 
		System::Windows::Forms::Label^  PasswordLabel;
	private: 
		System::Windows::Forms::Button^  LoginButton;
	private: 
		System::Windows::Forms::Label^  ErrorLabel;
	private:
		SOCKET sock;
	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void);
	private: 
		System::Void LoginButton_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
