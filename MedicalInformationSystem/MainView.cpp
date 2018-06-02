#include "MainView.h"
#include "EditPatient.h"

MedicalInformationSystem::MainView::MainView(void)
{
	InitializeComponent();
	MedicalInformationSystem::MainView::patientIndex = 0;
	MedicalInformationSystem::MainView::MinimizeBox = false;
	MedicalInformationSystem::MainView::MaximizeBox = false;
}

MedicalInformationSystem::MainView::MainView(SOCKET sock)
{
	InitializeComponent();
	MedicalInformationSystem::MainView::patientIndex = 0;
	MedicalInformationSystem::MainView::sock = sock;
	MedicalInformationSystem::MainView::MinimizeBox = false;
	MedicalInformationSystem::MainView::MaximizeBox = false;
}

MedicalInformationSystem::MainView::MainView(SOCKET sock, MedicalInformationSystem::Doctor *newDoctor)
{
	InitializeComponent();
	MedicalInformationSystem::MainView::patientIndex = 0;
	MedicalInformationSystem::MainView::sock = sock;
	MedicalInformationSystem::MainView::currentDoctor = newDoctor;
	MedicalInformationSystem::MainView::MinimizeBox = false;
	MedicalInformationSystem::MainView::MaximizeBox = false;
}

MedicalInformationSystem::MainView::~MainView()
{
	if (components)
	{
		delete components;
	}
}

void MedicalInformationSystem::MainView::InitializeComponent(void)
{
	this->Title = (gcnew System::Windows::Forms::Label());
	this->LoggedAs = (gcnew System::Windows::Forms::Label());
	this->MainContent = (gcnew System::Windows::Forms::Panel());
	this->PObservations = (gcnew System::Windows::Forms::Label());
	this->PGender = (gcnew System::Windows::Forms::Label());
	this->PBirthday = (gcnew System::Windows::Forms::Label());
	this->PSurname = (gcnew System::Windows::Forms::Label());
	this->PName = (gcnew System::Windows::Forms::Label());
	this->ObsLabel = (gcnew System::Windows::Forms::Label());
	this->GenderLabel = (gcnew System::Windows::Forms::Label());
	this->BirthdayLabel = (gcnew System::Windows::Forms::Label());
	this->SurnameLabel = (gcnew System::Windows::Forms::Label());
	this->NameLabel = (gcnew System::Windows::Forms::Label());
	this->PrevButt = (gcnew System::Windows::Forms::Button());
	this->EditButt = (gcnew System::Windows::Forms::Button());
	this->NextButt = (gcnew System::Windows::Forms::Button());
	this->MainContent->SuspendLayout();
	this->SuspendLayout();
	// 
	// Title
	// 
	this->Title->AutoSize = true;
	this->Title->Font = (gcnew System::Drawing::Font(L"Arial", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Title->Location = System::Drawing::Point(12, 21);
	this->Title->Name = L"Title";
	this->Title->Size = System::Drawing::Size(251, 42);
	this->Title->TabIndex = 0;
	this->Title->Text = L"Detalii pacienti";
	// 
	// LoggedAs
	// 
	this->LoggedAs->AutoSize = true;
	this->LoggedAs->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->LoggedAs->Location = System::Drawing::Point(490, 37);
	this->LoggedAs->Name = L"LoggedAs";
	this->LoggedAs->Size = System::Drawing::Size(133, 22);
	this->LoggedAs->TabIndex = 1;
	this->LoggedAs->Text = L"Autentificat ca:";
	// 
	// MainContent
	// 
	this->MainContent->AutoScroll = true;
	this->MainContent->Controls->Add(this->PObservations);
	this->MainContent->Controls->Add(this->PGender);
	this->MainContent->Controls->Add(this->PBirthday);
	this->MainContent->Controls->Add(this->PSurname);
	this->MainContent->Controls->Add(this->PName);
	this->MainContent->Controls->Add(this->ObsLabel);
	this->MainContent->Controls->Add(this->GenderLabel);
	this->MainContent->Controls->Add(this->BirthdayLabel);
	this->MainContent->Controls->Add(this->SurnameLabel);
	this->MainContent->Controls->Add(this->NameLabel);
	this->MainContent->Location = System::Drawing::Point(0, 79);
	this->MainContent->Name = L"MainContent";
	this->MainContent->Size = System::Drawing::Size(784, 418);
	this->MainContent->TabIndex = 2;
	// 
	// PObservations
	// 
	this->PObservations->AutoEllipsis = true;
	this->PObservations->AutoSize = true;
	this->PObservations->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PObservations->Location = System::Drawing::Point(19, 167);
	this->PObservations->MaximumSize = System::Drawing::Size(740, 0);
	this->PObservations->MinimumSize = System::Drawing::Size(740, 0);
	this->PObservations->Name = L"PObservations";
	this->PObservations->Size = System::Drawing::Size(740, 24);
	this->PObservations->TabIndex = 9;
	this->PObservations->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	// 
	// PGender
	// 
	this->PGender->AutoSize = true;
	this->PGender->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PGender->Location = System::Drawing::Point(73, 104);
	this->PGender->Name = L"PGender";
	this->PGender->Size = System::Drawing::Size(0, 24);
	this->PGender->TabIndex = 8;
	// 
	// PBirthday
	// 
	this->PBirthday->AutoSize = true;
	this->PBirthday->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PBirthday->Location = System::Drawing::Point(157, 73);
	this->PBirthday->Name = L"PBirthday";
	this->PBirthday->Size = System::Drawing::Size(0, 24);
	this->PBirthday->TabIndex = 7;
	// 
	// PSurname
	// 
	this->PSurname->AutoSize = true;
	this->PSurname->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PSurname->Location = System::Drawing::Point(127, 43);
	this->PSurname->Name = L"PSurname";
	this->PSurname->Size = System::Drawing::Size(0, 24);
	this->PSurname->TabIndex = 6;
	// 
	// PName
	// 
	this->PName->AutoSize = true;
	this->PName->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->PName->Location = System::Drawing::Point(88, 13);
	this->PName->Name = L"PName";
	this->PName->Size = System::Drawing::Size(0, 24);
	this->PName->TabIndex = 5;
	// 
	// ObsLabel
	// 
	this->ObsLabel->AutoSize = true;
	this->ObsLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->ObsLabel->Location = System::Drawing::Point(15, 132);
	this->ObsLabel->Name = L"ObsLabel";
	this->ObsLabel->Size = System::Drawing::Size(112, 24);
	this->ObsLabel->TabIndex = 4;
	this->ObsLabel->Text = L"Observatii:";
	// 
	// GenderLabel
	// 
	this->GenderLabel->AutoSize = true;
	this->GenderLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->GenderLabel->Location = System::Drawing::Point(15, 104);
	this->GenderLabel->Name = L"GenderLabel";
	this->GenderLabel->Size = System::Drawing::Size(52, 24);
	this->GenderLabel->TabIndex = 3;
	this->GenderLabel->Text = L"Sex:";
	// 
	// BirthdayLabel
	// 
	this->BirthdayLabel->AutoSize = true;
	this->BirthdayLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->BirthdayLabel->Location = System::Drawing::Point(15, 73);
	this->BirthdayLabel->Name = L"BirthdayLabel";
	this->BirthdayLabel->Size = System::Drawing::Size(136, 24);
	this->BirthdayLabel->TabIndex = 2;
	this->BirthdayLabel->Text = L"Data nasterii:";
	// 
	// SurnameLabel
	// 
	this->SurnameLabel->AutoSize = true;
	this->SurnameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->SurnameLabel->Location = System::Drawing::Point(13, 43);
	this->SurnameLabel->Name = L"SurnameLabel";
	this->SurnameLabel->Size = System::Drawing::Size(105, 24);
	this->SurnameLabel->TabIndex = 1;
	this->SurnameLabel->Text = L"Prenume: ";
	// 
	// NameLabel
	// 
	this->NameLabel->AutoSize = true;
	this->NameLabel->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->NameLabel->Location = System::Drawing::Point(13, 13);
	this->NameLabel->Name = L"NameLabel";
	this->NameLabel->Size = System::Drawing::Size(75, 24);
	this->NameLabel->TabIndex = 0;
	this->NameLabel->Text = L"Nume: ";
	// 
	// PrevButt
	// 
	this->PrevButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
	this->PrevButt->Location = System::Drawing::Point(65, 515);
	this->PrevButt->Name = L"PrevButt";
	this->PrevButt->Size = System::Drawing::Size(186, 34);
	this->PrevButt->TabIndex = 0;
	this->PrevButt->Text = L"Pacientul anterior";
	this->PrevButt->UseVisualStyleBackColor = true;
	this->PrevButt->Click += gcnew System::EventHandler(this, &MainView::PrevButt_Click);
	this->PrevButt->Enabled = false;
	// 
	// EditButt
	// 
	this->EditButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
	this->EditButt->Location = System::Drawing::Point(304, 515);
	this->EditButt->Name = L"EditButt";
	this->EditButt->Size = System::Drawing::Size(186, 34);
	this->EditButt->TabIndex = 3;
	this->EditButt->Text = L"Editeaza informatia";
	this->EditButt->UseVisualStyleBackColor = true;
	this->EditButt->Click += gcnew System::EventHandler(this, &MainView::EditButt_Click);
	// 
	// NextButt
	// 
	this->NextButt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
	this->NextButt->Location = System::Drawing::Point(535, 515);
	this->NextButt->Name = L"NextButt";
	this->NextButt->Size = System::Drawing::Size(186, 34);
	this->NextButt->TabIndex = 4;
	this->NextButt->Text = L"Pacientul urmator";
	this->NextButt->UseVisualStyleBackColor = true;
	this->NextButt->Click += gcnew System::EventHandler(this, &MainView::NextButt_Click);
	// 
	// MainView
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(57, 108);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoScroll = true;
	this->ClientSize = System::Drawing::Size(784, 561);
	this->Controls->Add(this->NextButt);
	this->Controls->Add(this->EditButt);
	this->Controls->Add(this->PrevButt);
	this->Controls->Add(this->MainContent);
	this->Controls->Add(this->LoggedAs);
	this->Controls->Add(this->Title);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->Margin = System::Windows::Forms::Padding(28, 25, 28, 25);
	this->Name = L"MainView";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"Pacienti";
	this->Load += gcnew System::EventHandler(this, &MainView::MainView_Load);
	this->MainContent->ResumeLayout(false);
	this->MainContent->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

}

System::Void MedicalInformationSystem::MainView::MainView_Load(System::Object^  sender, System::EventArgs^  e)
{
	std::string stringToSend = "GET_INITIAL_DATA>" + this->currentDoctor->getId();
	char buffer[100000], bufferRecv[100000];
	sprintf(buffer, "%s", stringToSend.c_str());
	send(this->sock, buffer, 100000, 0);
	recv(this->sock, bufferRecv, 100000, 0);
	std::string responseToProcess(bufferRecv);
	std::vector<std::string> patientInfo = MedicalInformationSystem::Tokenizer::tokenize(responseToProcess, '^');
	std::vector<MedicalInformationSystem::Patient> patients = {};
	for (std::string s : patientInfo) {
		MedicalInformationSystem::Patient p = MedicalInformationSystem::Patient();
		p.fromString(s);
		patients.push_back(p);
	}
	this->currentDoctor->setPatients(patients);
	System::String ^loggedAsText = gcnew System::String(("Autentificat ca: " + this->currentDoctor->getUsername()).c_str());
	this->LoggedAs->Text = loggedAsText;
	this->setupPatientView();
}

System::Void MedicalInformationSystem::MainView::NextButt_Click(System::Object^  sender, System::EventArgs^  e)
{
	int futureIndex = this->patientIndex + 1;
	if (futureIndex >= this->currentDoctor->getPatients().size()) {
		this->NextButt->Enabled = false;
	}
	else {
		this->patientIndex++;
		this->setupPatientView();
		if (this->PrevButt->Enabled == false) {
			this->PrevButt->Enabled = true;
		}
	}
}

System::Void MedicalInformationSystem::MainView::PrevButt_Click(System::Object^  sender, System::EventArgs^  e)
{
	int previousIndex = this->patientIndex - 1;
	if (previousIndex < 0) {
		this->PrevButt->Enabled = false;
	}
	else {
		this->patientIndex--;
		this->setupPatientView();
		if (this->NextButt->Enabled == false) {
			this->NextButt->Enabled = true;
		}
	}
}

System::Void MedicalInformationSystem::MainView::EditButt_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Hide();
	MedicalInformationSystem::EditPatient editPatient(
		this->sock,
		new MedicalInformationSystem::Doctor(
			this->currentDoctor->getId(),
			this->currentDoctor->getUsername(),
			this->currentDoctor->getPassword(),
			{}
		),
		this->currentDoctor->getPatients()[this->patientIndex].getId(),
		this
	);
	editPatient.ShowDialog();
	std::string stringToSend = "GET_INITIAL_DATA>" + this->currentDoctor->getId();
	char buffer[100000], bufferRecv[100000];
	sprintf(buffer, "%s", stringToSend.c_str());
	send(this->sock, buffer, 100000, 0);
	recv(this->sock, bufferRecv, 100000, 0);
	std::string responseToProcess(bufferRecv);
	std::vector<std::string> patientInfo = MedicalInformationSystem::Tokenizer::tokenize(responseToProcess, '^');
	std::vector<MedicalInformationSystem::Patient> patients = {};
	for (std::string s : patientInfo) {
		MedicalInformationSystem::Patient p = MedicalInformationSystem::Patient();
		p.fromString(s);
		patients.push_back(p);
	}
	this->currentDoctor->setPatients(patients);
	System::String ^loggedAsText = gcnew System::String(("Autentificat ca: " + this->currentDoctor->getUsername()).c_str());
	this->LoggedAs->Text = loggedAsText;
	this->setupPatientView();
}

System::Void MedicalInformationSystem::MainView::setupPatientView() {
	MedicalInformationSystem::Patient p = this->currentDoctor->getPatients()[this->patientIndex];
	System::String ^name = gcnew System::String(p.getName().c_str());
	System::String ^surname = gcnew System::String(p.getSurname().c_str());
	System::String ^birthdate = gcnew System::String(p.getBirthday().c_str());
	System::String ^gender = gcnew System::String(p.getGender().c_str());
	System::String ^obs = gcnew System::String(p.getObservations().c_str());
	this->PName->Text = name;
	this->PSurname->Text = surname;
	this->PBirthday->Text = birthdate;
	this->PGender->Text = gender;
	this->PObservations->Text = obs;
}