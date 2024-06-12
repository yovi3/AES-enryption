#pragma once
#include <Windows.h>
#include <vcclr.h>
#include <msclr/marshal_cppstd.h>
#include "encrypt.h"


namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form {
	public:
		main(void) {
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ TitleLabel;
	protected:

	protected:

	//private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ DecryptButton;

	private: System::Windows::Forms::Button^ EncryptButton;
	private: System::Windows::Forms::Label^ AuthorsLabel;


	private: System::Windows::Forms::TextBox^ StatusBar;
	private: System::Windows::Forms::TextBox^ FilePathBox;


	private: System::Windows::Forms::Button^ FileSelectorButton;



	private: System::Windows::Forms::Label^ pathLabel;
	private: System::Windows::Forms::Label^ StatusLabel;


	protected:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->DecryptButton = (gcnew System::Windows::Forms::Button());
			this->EncryptButton = (gcnew System::Windows::Forms::Button());
			this->AuthorsLabel = (gcnew System::Windows::Forms::Label());
			this->StatusBar = (gcnew System::Windows::Forms::TextBox());
			this->FilePathBox = (gcnew System::Windows::Forms::TextBox());
			this->FileSelectorButton = (gcnew System::Windows::Forms::Button());
			this->pathLabel = (gcnew System::Windows::Forms::Label());
			this->StatusLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TitleLabel
			// 
			this->TitleLabel->AutoSize = true;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->TitleLabel->ForeColor = System::Drawing::SystemColors::MenuText;
			this->TitleLabel->Location = System::Drawing::Point(68, 67);
			this->TitleLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(1014, 46);
			this->TitleLabel->TabIndex = 0;
			this->TitleLabel->Text = L"Szyfrowanie plików z wykorzystaniem algorytmu AES";
			this->TitleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DecryptButton
			// 
			this->DecryptButton->BackColor = System::Drawing::Color::WhiteSmoke;
			this->DecryptButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->DecryptButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->DecryptButton->Location = System::Drawing::Point(561, 417);
			this->DecryptButton->Margin = System::Windows::Forms::Padding(6);
			this->DecryptButton->Name = L"DecryptButton";
			this->DecryptButton->Size = System::Drawing::Size(317, 85);
			this->DecryptButton->TabIndex = 1;
			this->DecryptButton->Text = L"Odszyfruj";
			this->DecryptButton->UseVisualStyleBackColor = false;
			// 
			// EncryptButton
			// 
			this->EncryptButton->BackColor = System::Drawing::Color::WhiteSmoke;
			this->EncryptButton->FlatAppearance->BorderColor = System::Drawing::Color::DimGray;
			this->EncryptButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->EncryptButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->EncryptButton->Location = System::Drawing::Point(232, 417);
			this->EncryptButton->Margin = System::Windows::Forms::Padding(6);
			this->EncryptButton->Name = L"EncryptButton";
			this->EncryptButton->Size = System::Drawing::Size(317, 85);
			this->EncryptButton->TabIndex = 2;
			this->EncryptButton->Text = L"Zaszyfruj";
			this->EncryptButton->UseVisualStyleBackColor = false;
			this->EncryptButton->Click += gcnew System::EventHandler(this, &main::EncryptButton_Click);
			// 
			// AuthorsLabel
			// 
			this->AuthorsLabel->AutoSize = true;
			this->AuthorsLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->AuthorsLabel->Location = System::Drawing::Point(556, 575);
			this->AuthorsLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->AuthorsLabel->Name = L"AuthorsLabel";
			this->AuthorsLabel->Size = System::Drawing::Size(526, 25);
			this->AuthorsLabel->TabIndex = 3;
			this->AuthorsLabel->Text = L"Autorzy: Piotr Marciniak, Maciej Łuczka, Oliwier Kucik";
			// 
			// StatusBar
			// 
			this->StatusBar->BackColor = System::Drawing::Color::DimGray;
			this->StatusBar->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->StatusBar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->StatusBar->ForeColor = System::Drawing::Color::Red;
			this->StatusBar->Location = System::Drawing::Point(49, 575);
			this->StatusBar->Margin = System::Windows::Forms::Padding(6);
			this->StatusBar->Name = L"StatusBar";
			this->StatusBar->Size = System::Drawing::Size(500, 31);
			this->StatusBar->TabIndex = 4;
			// 
			// FilePathBox
			// 
			this->FilePathBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->FilePathBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->FilePathBox->Location = System::Drawing::Point(187, 278);
			this->FilePathBox->Margin = System::Windows::Forms::Padding(6);
			this->FilePathBox->Name = L"FilePathBox";
			this->FilePathBox->Size = System::Drawing::Size(598, 31);
			this->FilePathBox->TabIndex = 5;
			// 
			// FileSelectorButton
			// 
			this->FileSelectorButton->BackColor = System::Drawing::Color::Gainsboro;
			this->FileSelectorButton->FlatAppearance->BorderColor = System::Drawing::Color::DarkCyan;
			this->FileSelectorButton->FlatAppearance->BorderSize = 3;
			this->FileSelectorButton->Location = System::Drawing::Point(815, 247);
			this->FileSelectorButton->Margin = System::Windows::Forms::Padding(6);
			this->FileSelectorButton->Name = L"FileSelectorButton";
			this->FileSelectorButton->Size = System::Drawing::Size(170, 62);
			this->FileSelectorButton->TabIndex = 6;
			this->FileSelectorButton->Text = L"Przeglądaj";
			this->FileSelectorButton->UseVisualStyleBackColor = false;
			this->FileSelectorButton->Click += gcnew System::EventHandler(this, &main::FileSelectorButton_Click);
			// 
			// pathLabel
			// 
			this->pathLabel->AutoSize = true;
			this->pathLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->pathLabel->Location = System::Drawing::Point(182, 247);
			this->pathLabel->Name = L"pathLabel";
			this->pathLabel->Size = System::Drawing::Size(169, 25);
			this->pathLabel->TabIndex = 7;
			this->pathLabel->Text = L"Ścieżka do pliku";
			// 
			// StatusLabel
			// 
			this->StatusLabel->AutoSize = true;
			this->StatusLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->StatusLabel->Location = System::Drawing::Point(44, 544);
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(79, 25);
			this->StatusLabel->TabIndex = 8;
			this->StatusLabel->Text = L"Status:";
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(192, 192);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::LightSlateGray;
			this->ClientSize = System::Drawing::Size(1174, 629);
			this->Controls->Add(this->StatusLabel);
			this->Controls->Add(this->pathLabel);
			this->Controls->Add(this->FileSelectorButton);
			this->Controls->Add(this->FilePathBox);
			this->Controls->Add(this->StatusBar);
			this->Controls->Add(this->AuthorsLabel);
			this->Controls->Add(this->EncryptButton);
			this->Controls->Add(this->DecryptButton);
			this->Controls->Add(this->TitleLabel);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main";
			this->ShowIcon = false;
			this->Text = L"AES | Projekt Programowanie";
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void FileSelectorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

		// Set filter options and filter index
		openFileDialog->Filter = "All Files (*.*)|*.*|Text Files (*.txt)|*.txt";
		openFileDialog->FilterIndex = 1;
		openFileDialog->Multiselect = false;

		try {
			// Show the dialog and get the result
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// Get the selected file name
				String^ selectedFileName = openFileDialog->FileName;

				// Echo selected path to textbox called FilePathBox
				FilePathBox->Text = selectedFileName;
				StatusBar->Text = "Wybrano plik";
			}
		}
		catch (System::Exception^ ex) {
			// Handle the exception and show an error
			MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			StatusBar->Text = "Wybrano zly plik, sprobuj ponownie";
			//TODO need to export this to the StatusBar!!!
		}
	}


private: System::Void EncryptButton_Click(System::Object^ sender, System::EventArgs^ e) {
	
	msclr::interop::marshal_context context;
	std::string filePath = context.marshal_as<std::string>(FilePathBox->Text);
	std::string encrypt1 = encrypt(filePath);
	String^ encryptKeyValue = gcnew String(encrypt1.c_str());
	StatusBar->Text = encryptKeyValue;

}
};
}
