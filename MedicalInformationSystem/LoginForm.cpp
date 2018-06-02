#include "LoginForm.h"
#include "MainView.h"
#include "Tokenizer.h"

MedicalInformationSystem::LoginForm::LoginForm(void)
{
	InitializeComponent();
	MedicalInformationSystem::LoginForm::MinimizeBox = false;
	MedicalInformationSystem::LoginForm::MaximizeBox = false;
}

MedicalInformationSystem::LoginForm::LoginForm(SOCKET sock)
{
	InitializeComponent();
	MedicalInformationSystem::LoginForm::sock = sock;
	MedicalInformationSystem::LoginForm::MinimizeBox = false;
	MedicalInformationSystem::LoginForm::MaximizeBox = false;
}

MedicalInformationSystem::LoginForm::~LoginForm()
{
	if (components)
	{
		delete components;
	}
}

void MedicalInformationSystem::LoginForm::InitializeComponent(void)
{
	this->TitleLabel = (gcnew System::Windows::Forms::Label());
	this->Username = (gcnew System::Windows::Forms::TextBox());
	this->Password = (gcnew System::Windows::Forms::TextBox());
	this->UsernameLabel = (gcnew System::Windows::Forms::Label());
	this->PasswordLabel = (gcnew System::Windows::Forms::Label());
	this->LoginButton = (gcnew System::Windows::Forms::Button());
	this->ErrorLabel = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// TitleLabel
	// 
	this->TitleLabel->AutoSize = true;
	this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->TitleLabel->Location = System::Drawing::Point(77, 29);
	this->TitleLabel->Name = L"TitleLabel";
	this->TitleLabel->Size = System::Drawing::Size(115, 22);
	this->TitleLabel->TabIndex = 0;
	this->TitleLabel->Text = L"Autentificare";
	// 
	// Username
	// 
	this->Username->Location = System::Drawing::Point(88, 84);
	this->Username->Name = L"Username";
	this->Username->Size = System::Drawing::Size(177, 20);
	this->Username->TabIndex = 1;
	// 
	// Password
	// 
	this->Password->Location = System::Drawing::Point(88, 110);
	this->Password->Name = L"Password";
	this->Password->PasswordChar = '*';
	this->Password->Size = System::Drawing::Size(177, 20);
	this->Password->TabIndex = 2;
	// 
	// UsernameLabel
	// 
	this->UsernameLabel->AutoSize = true;
	this->UsernameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->UsernameLabel->Location = System::Drawing::Point(15, 85);
	this->UsernameLabel->Name = L"UsernameLabel";
	this->UsernameLabel->Size = System::Drawing::Size(71, 16);
	this->UsernameLabel->TabIndex = 3;
	this->UsernameLabel->Text = L"Username:";
	// 
	// PasswordLabel
	// 
	this->PasswordLabel->AutoSize = true;
	this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PasswordLabel->Location = System::Drawing::Point(37, 111);
	this->PasswordLabel->Name = L"PasswordLabel";
	this->PasswordLabel->Size = System::Drawing::Size(49, 16);
	this->PasswordLabel->TabIndex = 4;
	this->PasswordLabel->Text = L"Parola:";
	// 
	// LoginButton
	// 
	this->LoginButton->Location = System::Drawing::Point(75, 164);
	this->LoginButton->Name = L"LoginButton";
	this->LoginButton->Size = System::Drawing::Size(134, 42);
	this->LoginButton->TabIndex = 5;
	this->LoginButton->Text = L"Autentificare";
	this->LoginButton->UseVisualStyleBackColor = true;
	this->LoginButton->Click += gcnew System::EventHandler(this, &LoginForm::LoginButton_Click);
	// 
	// ErrorLabel
	// 
	this->ErrorLabel->AutoEllipsis = true;
	this->ErrorLabel->AutoSize = true;
	this->ErrorLabel->Location = System::Drawing::Point(24, 211);
	this->ErrorLabel->MaximumSize = System::Drawing::Size(232, 0);
	this->ErrorLabel->MinimumSize = System::Drawing::Size(232, 0);
	this->ErrorLabel->Name = L"ErrorLabel";
	this->ErrorLabel->Size = System::Drawing::Size(232, 13);
	this->ErrorLabel->TabIndex = 6;
	this->ErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	this->ErrorLabel->Visible = false;
	// 
	// LoginForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(284, 261);
	this->Controls->Add(this->ErrorLabel);
	this->Controls->Add(this->LoginButton);
	this->Controls->Add(this->PasswordLabel);
	this->Controls->Add(this->UsernameLabel);
	this->Controls->Add(this->Password);
	this->Controls->Add(this->Username);
	this->Controls->Add(this->TitleLabel);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->Name = L"LoginForm";
	this->ShowIcon = false;
	this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"Autentificare";
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void MedicalInformationSystem::LoginForm::LoginButton_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String ^stringToSend = "LOGIN>Username~" + this->Username->Text + "#Password~" + this->Password->Text;
	char buffer[100000], bufferRecv[5000];
	sprintf(buffer, "%s", stringToSend);
	send(this->sock, buffer, 100000, 0);
	recv(this->sock, bufferRecv, 5000, 0);
	System::String ^errorText = gcnew System::String(bufferRecv);
	std::string checkErrorString = msclr::interop::marshal_as<std::string>(errorText);
	std::vector<std::string> errTokens = MedicalInformationSystem::Tokenizer::tokenize(checkErrorString, '>');
	if (errTokens[0] == "OK") {
		this->Hide();
		MedicalInformationSystem::MainView mainView(
			this->sock, 
			new MedicalInformationSystem::Doctor(
				errTokens[1], 
				msclr::interop::marshal_as<std::string>(this->Username->Text), 
				msclr::interop::marshal_as<std::string>(this->Password->Text), 
				{}
			)
		);
		mainView.ShowDialog();
	}
	else {
		this->Username->Text = L"";
		this->Password->Text = L"";
		this->ErrorLabel->Visible = true;
		System::String ^errorMessage = gcnew System::String(errTokens[1].c_str());
		this->ErrorLabel->Text = errorMessage;
	}
}
