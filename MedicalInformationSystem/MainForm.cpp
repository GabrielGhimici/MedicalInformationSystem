#include "MainForm.h"
#include "LoginForm.h"
#include "Doctor.h"
#include "Patient.h"
#include "Tokenizer.h"

using namespace System;

[STAThread]
int main(array<System::String^>^ args) {
	WSADATA wsaData;
	int iResult;
	sockaddr_in addr;
	SOCKET sock, client;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(2222);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult)
	{
		System::Windows::Forms::MessageBox::Show(
			"Conexiunea bazata pe websocketi nu a putut fi creata. Va rugam incercati din nou!",
			"WSA startup failed",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information
		);
		return 0;
	}


	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sock == INVALID_SOCKET)
	{
		System::Windows::Forms::MessageBox::Show(
			"Conexiunea bazata pe websocketi nu a putut fi creata. Va rugam incercati din nou!",
			"Invalid socket",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information
		);
		return 0;
	}

	iResult = connect(sock, (SOCKADDR*)&addr, sizeof(sockaddr_in));

	if (iResult)
	{
		System::Windows::Forms::MessageBox::Show(
			"Conexiunea cu server-ul nu a putut fi realizata. Va rugam incercati din nou!",
			"Connect failed " + WSAGetLastError(),
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information
		);
		return 0;
	}

	char ptr[100000];
	for (int i = 0; i<3; i++)
	{
		sprintf(ptr, "Testing Connection - Heartbeat %d", i);
		send(sock, ptr, sizeof(ptr), 0);
		Sleep(500);
	}

	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	MedicalInformationSystem::MainForm form(sock);
	System::Windows::Forms::Application::Run(%form);
	closesocket(sock);
}

MedicalInformationSystem::MainForm::MainForm(void)
{
	InitializeComponent();
	MedicalInformationSystem::MainForm::MinimizeBox = false;
	MedicalInformationSystem::MainForm::MaximizeBox = false;
}

MedicalInformationSystem::MainForm::MainForm(SOCKET sock)
{
	InitializeComponent();
	MedicalInformationSystem::MainForm::sock = sock;
	MedicalInformationSystem::MainForm::MinimizeBox = false;
	MedicalInformationSystem::MainForm::MaximizeBox = false;
}

MedicalInformationSystem::MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
}

void MedicalInformationSystem::MainForm::InitializeComponent(void)
{
	this->Title = (gcnew System::Windows::Forms::Label());
	this->Information = (gcnew System::Windows::Forms::Label());
	this->GoToApp = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// Title
	// 
	this->Title->AutoEllipsis = true;
	this->Title->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Title->Location = System::Drawing::Point(16, 11);
	this->Title->Name = L"Title";
	this->Title->Size = System::Drawing::Size(250, 59);
	this->Title->TabIndex = 0;
	this->Title->Text = L"Medical Information System";
	this->Title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
	// 
	// Information
	// 
	this->Information->AutoEllipsis = true;
	this->Information->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Information->Location = System::Drawing::Point(18, 79);
	this->Information->Name = L"Information";
	this->Information->Size = System::Drawing::Size(248, 75);
	this->Information->TabIndex = 1;
	this->Information->Text = L"Aceasta aplicatie permite utilizatorilor, medici de profesie, sa vizualizeze si s"
		L"a noteze diverse observatii referitoare la stare de sanatate a pacientilor.";
	this->Information->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// GoToApp
	// 
	this->GoToApp->Location = System::Drawing::Point(68, 178);
	this->GoToApp->Name = L"GoToApp";
	this->GoToApp->Size = System::Drawing::Size(140, 44);
	this->GoToApp->TabIndex = 2;
	this->GoToApp->Text = L"Mergi la aplicatie";
	this->GoToApp->UseVisualStyleBackColor = true;
	this->GoToApp->Click += gcnew System::EventHandler(this, &MainForm::GoToApp_Click);
	// 
	// MainForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(284, 261);
	this->Controls->Add(this->GoToApp);
	this->Controls->Add(this->Information);
	this->Controls->Add(this->Title);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->Name = L"MainForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"MainWindow";
	this->ResumeLayout(false);
}

System::Void MedicalInformationSystem::MainForm::GoToApp_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	MedicalInformationSystem::LoginForm loginForm(this->sock);
	loginForm.ShowDialog();
	this->Close();
}