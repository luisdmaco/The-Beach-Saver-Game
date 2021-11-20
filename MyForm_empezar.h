#pragma once
#include "MyForm_level01.h"
#include "MyForm_level_02.h"
namespace trabajofinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm_empezar
	/// </summary>
	public ref class MyForm_empezar : public System::Windows::Forms::Form
	{
	public:
		MyForm_empezar(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm_empezar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Button^ button2_level02;
	private: System::Windows::Forms::Button^ button1_level01;
	private: System::Windows::Forms::TextBox^ textBox1_nombre;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_empezar::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2_level02 = (gcnew System::Windows::Forms::Button());
			this->button1_level01 = (gcnew System::Windows::Forms::Button());
			this->textBox1_nombre = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Coral;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(88, 274);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 32);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Enter Your Name : ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2_level02
			// 
			this->button2_level02->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2_level02->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2_level02->Location = System::Drawing::Point(292, 357);
			this->button2_level02->Name = L"button2_level02";
			this->button2_level02->Size = System::Drawing::Size(139, 38);
			this->button2_level02->TabIndex = 7;
			this->button2_level02->Text = L"LEVEL 02";
			this->button2_level02->UseVisualStyleBackColor = false;
			this->button2_level02->Click += gcnew System::EventHandler(this, &MyForm_empezar::button2_level02_Click);
			// 
			// button1_level01
			// 
			this->button1_level01->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1_level01->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1_level01->Font = (gcnew System::Drawing::Font(L"Segoe Print", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1_level01->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1_level01->Location = System::Drawing::Point(110, 357);
			this->button1_level01->Name = L"button1_level01";
			this->button1_level01->Size = System::Drawing::Size(139, 39);
			this->button1_level01->TabIndex = 6;
			this->button1_level01->Text = L"LEVEL 01 ";
			this->button1_level01->UseVisualStyleBackColor = false;
			this->button1_level01->Click += gcnew System::EventHandler(this, &MyForm_empezar::button1_level01_Click);
			// 
			// textBox1_nombre
			// 
			this->textBox1_nombre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1_nombre->Location = System::Drawing::Point(231, 275);
			this->textBox1_nombre->Name = L"textBox1_nombre";
			this->textBox1_nombre->Size = System::Drawing::Size(200, 26);
			this->textBox1_nombre->TabIndex = 5;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 402);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(392, 122);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(437, 228);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(124, 275);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 24;
			this->pictureBox3->TabStop = false;
			// 
			// MyForm_empezar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(573, 536);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2_level02);
			this->Controls->Add(this->button1_level01);
			this->Controls->Add(this->textBox1_nombre);
			this->Name = L"MyForm_empezar";
			this->Text = L"MyForm_empezar";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_level01_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1_nombre->Text != "")
		{
			MyForm_level01^ L1 = gcnew MyForm_level01();
			L1->ColocaNombre(textBox1_nombre->Text);
			L1->Show();
			this->Visible = false;
		}
		else {
			MessageBox::Show("Ingrese Su Nombre Primero ");
		}
		
	}
    private: System::Void button2_level02_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1_nombre->Text != "")
		{

			MyForm_level_02^ L2 = gcnew MyForm_level_02();
			L2->ColocaNombre(textBox1_nombre->Text);
			L2->Show();
			this->Visible = false;
		}
		else {
			MessageBox::Show("Ingrese Su Nombre Primero ");
		}
		
    }
};
}
