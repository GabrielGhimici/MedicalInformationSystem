#pragma once
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

namespace MedicalInformationSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);
		MainForm(SOCKET sock);
	protected:
		~MainForm();
	private: 
		System::Windows::Forms::Label^  Title;
	private: 
		System::Windows::Forms::Label^  Information;
	private: 
		System::Windows::Forms::Button^  GoToApp;
	private:
		SOCKET sock;
	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void);
	private: 
		System::Void GoToApp_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
