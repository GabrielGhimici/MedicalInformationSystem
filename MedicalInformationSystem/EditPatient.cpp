#include "EditPatient.h"
#include "MainView.h"

MedicalInformationSystem::EditPatient::EditPatient(void)
{
	InitializeComponent();
}

MedicalInformationSystem::EditPatient::~EditPatient()
{
	if (components)
	{
		delete components;
	}
}

void MedicalInformationSystem::EditPatient::InitializeComponent(void)
{
	this->LoggedAs = (gcnew System::Windows::Forms::Label());
	this->Title = (gcnew System::Windows::Forms::Label());
	this->PatientLabel = (gcnew System::Windows::Forms::Label());
	this->ObsLabel = (gcnew System::Windows::Forms::Label());
	this->GenderLabel = (gcnew System::Windows::Forms::Label());
	this->BirthdayLabel = (gcnew System::Windows::Forms::Label());
	this->SurnameLabel = (gcnew System::Windows::Forms::Label());
	this->NameLabel = (gcnew System::Windows::Forms::Label());
	this->SaveButt = (gcnew System::Windows::Forms::Button());
	this->BackButt = (gcnew System::Windows::Forms::Button());
	this->PName = (gcnew System::Windows::Forms::TextBox());
	this->PGender = (gcnew System::Windows::Forms::TextBox());
	this->PBirthday = (gcnew System::Windows::Forms::TextBox());
	this->PSurname = (gcnew System::Windows::Forms::TextBox());
	this->PObsevations = (gcnew System::Windows::Forms::TextBox());
	this->SuspendLayout();
	// 
	// LoggedAs
	// 
	this->LoggedAs->AutoSize = true;
	this->LoggedAs->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->LoggedAs->Location = System::Drawing::Point(490, 36);
	this->LoggedAs->Name = L"LoggedAs";
	this->LoggedAs->Size = System::Drawing::Size(133, 22);
	this->LoggedAs->TabIndex = 3;
	this->LoggedAs->Text = L"Autentificat ca:";
	// 
	// Title
	// 
	this->Title->AutoSize = true;
	this->Title->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Title->Location = System::Drawing::Point(12, 20);
	this->Title->Name = L"Title";
	this->Title->Size = System::Drawing::Size(299, 42);
	this->Title->TabIndex = 2;
	this->Title->Text = L"Editare informatii ";
	// 
	// PatientLabel
	// 
	this->PatientLabel->AutoSize = true;
	this->PatientLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PatientLabel->Location = System::Drawing::Point(15, 62);
	this->PatientLabel->Name = L"PatientLabel";
	this->PatientLabel->Size = System::Drawing::Size(83, 22);
	this->PatientLabel->TabIndex = 4;
	this->PatientLabel->Text = L"Pacient: ";
	// 
	// ObsLabel
	// 
	this->ObsLabel->AutoSize = true;
	this->ObsLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->ObsLabel->Location = System::Drawing::Point(34, 227);
	this->ObsLabel->Name = L"ObsLabel";
	this->ObsLabel->Size = System::Drawing::Size(100, 22);
	this->ObsLabel->TabIndex = 5;
	this->ObsLabel->Text = L"Observatii:";
	// 
	// GenderLabel
	// 
	this->GenderLabel->AutoSize = true;
	this->GenderLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->GenderLabel->Location = System::Drawing::Point(86, 197);
	this->GenderLabel->Name = L"GenderLabel";
	this->GenderLabel->Size = System::Drawing::Size(48, 22);
	this->GenderLabel->TabIndex = 6;
	this->GenderLabel->Text = L"Sex:";
	// 
	// BirthdayLabel
	// 
	this->BirthdayLabel->AutoSize = true;
	this->BirthdayLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->BirthdayLabel->Location = System::Drawing::Point(15, 166);
	this->BirthdayLabel->Name = L"BirthdayLabel";
	this->BirthdayLabel->Size = System::Drawing::Size(119, 22);
	this->BirthdayLabel->TabIndex = 7;
	this->BirthdayLabel->Text = L"Data nasterii:";
	// 
	// SurnameLabel
	// 
	this->SurnameLabel->AutoSize = true;
	this->SurnameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->SurnameLabel->Location = System::Drawing::Point(42, 134);
	this->SurnameLabel->Name = L"SurnameLabel";
	this->SurnameLabel->Size = System::Drawing::Size(92, 22);
	this->SurnameLabel->TabIndex = 8;
	this->SurnameLabel->Text = L"Prenume:";
	// 
	// NameLabel
	// 
	this->NameLabel->AutoSize = true;
	this->NameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->NameLabel->Location = System::Drawing::Point(69, 102);
	this->NameLabel->Name = L"NameLabel";
	this->NameLabel->Size = System::Drawing::Size(65, 22);
	this->NameLabel->TabIndex = 9;
	this->NameLabel->Text = L"Nume:";
	// 
	// SaveButt
	// 
	this->SaveButt->Location = System::Drawing::Point(431, 489);
	this->SaveButt->Name = L"SaveButt";
	this->SaveButt->Size = System::Drawing::Size(208, 39);
	this->SaveButt->TabIndex = 10;
	this->SaveButt->Text = L"Salvare Informatii";
	this->SaveButt->UseVisualStyleBackColor = true;
	this->SaveButt->Click += gcnew System::EventHandler(this, &EditPatient::SaveButt_Click);
	// 
	// BackButt
	// 
	this->BackButt->Location = System::Drawing::Point(119, 489);
	this->BackButt->Name = L"BackButt";
	this->BackButt->Size = System::Drawing::Size(208, 39);
	this->BackButt->TabIndex = 11;
	this->BackButt->Text = L"Inapoi la pacienti";
	this->BackButt->UseVisualStyleBackColor = true;
	this->BackButt->Click += gcnew System::EventHandler(this, &EditPatient::BackButt_Click);
	// 
	// PName
	// 
	this->PName->Location = System::Drawing::Point(140, 106);
	this->PName->Name = L"PName";
	this->PName->Size = System::Drawing::Size(577, 20);
	this->PName->TabIndex = 12;
	// 
	// PGender
	// 
	this->PGender->Location = System::Drawing::Point(140, 201);
	this->PGender->Name = L"PGender";
	this->PGender->Size = System::Drawing::Size(577, 20);
	this->PGender->TabIndex = 14;
	// 
	// PBirthday
	// 
	this->PBirthday->Location = System::Drawing::Point(140, 170);
	this->PBirthday->Name = L"PBirthday";
	this->PBirthday->Size = System::Drawing::Size(577, 20);
	this->PBirthday->TabIndex = 15;
	// 
	// PSurname
	// 
	this->PSurname->Location = System::Drawing::Point(140, 138);
	this->PSurname->Name = L"PSurname";
	this->PSurname->Size = System::Drawing::Size(577, 20);
	this->PSurname->TabIndex = 16;
	// 
	// PObsevations
	// 
	this->PObsevations->AcceptsReturn = true;
	this->PObsevations->Location = System::Drawing::Point(140, 231);
	this->PObsevations->Multiline = true;
	this->PObsevations->Name = L"PObsevations";
	this->PObsevations->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
	this->PObsevations->Size = System::Drawing::Size(577, 239);
	this->PObsevations->TabIndex = 17;
	// 
	// EditPatient
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(784, 561);
	this->Controls->Add(this->PObsevations);
	this->Controls->Add(this->PSurname);
	this->Controls->Add(this->PBirthday);
	this->Controls->Add(this->PGender);
	this->Controls->Add(this->PName);
	this->Controls->Add(this->BackButt);
	this->Controls->Add(this->SaveButt);
	this->Controls->Add(this->NameLabel);
	this->Controls->Add(this->SurnameLabel);
	this->Controls->Add(this->BirthdayLabel);
	this->Controls->Add(this->GenderLabel);
	this->Controls->Add(this->ObsLabel);
	this->Controls->Add(this->PatientLabel);
	this->Controls->Add(this->LoggedAs);
	this->Controls->Add(this->Title);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"EditPatient";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"EditPatient";
	this->ResumeLayout(false);
	this->PerformLayout();
}

System::Void MedicalInformationSystem::EditPatient::SaveButt_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	MedicalInformationSystem::MainView mainView;
	mainView.ShowDialog();
}

System::Void MedicalInformationSystem::EditPatient::BackButt_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MedicalInformationSystem::MainView mainView;
	mainView.ShowDialog();
}