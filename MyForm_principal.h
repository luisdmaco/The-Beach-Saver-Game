#pragma once
#include "MyForm_empezar.h"
#include "MyForm_creditos.h"
#include "MyForm_instrucciones.h"
namespace trabajofinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm_principal
	/// </summary>
	public ref class MyForm_principal : public System::Windows::Forms::Form
	{
	public:
		MyForm_principal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm_principal()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Button^ button2_instrucciones;
	private: System::Windows::Forms::Button^ button5_creditos;
	private: System::Windows::Forms::Button^ button3_salir;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_principal::typeid));
			this->button2_instrucciones = (gcnew System::Windows::Forms::Button());
			this->button5_creditos = (gcnew System::Windows::Forms::Button());
			this->button3_salir = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button2_instrucciones
			// 
			this->button2_instrucciones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2_instrucciones.BackgroundImage")));
			this->button2_instrucciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2_instrucciones->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2_instrucciones->Font = (gcnew System::Drawing::Font(L"Ravie", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2_instrucciones->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2_instrucciones->Location = System::Drawing::Point(276, 393);
			this->button2_instrucciones->Name = L"button2_instrucciones";
			this->button2_instrucciones->Size = System::Drawing::Size(216, 36);
			this->button2_instrucciones->TabIndex = 20;
			this->button2_instrucciones->Text = L"instrucciones";
			this->button2_instrucciones->UseVisualStyleBackColor = true;
			this->button2_instrucciones->Click += gcnew System::EventHandler(this, &MyForm_principal::button2_instrucciones_Click);
			// 
			// button5_creditos
			// 
			this->button5_creditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5_creditos.BackgroundImage")));
			this->button5_creditos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5_creditos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5_creditos->Font = (gcnew System::Drawing::Font(L"Ravie", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5_creditos->ForeColor = System::Drawing::Color::White;
			this->button5_creditos->Location = System::Drawing::Point(242, 435);
			this->button5_creditos->Name = L"button5_creditos";
			this->button5_creditos->Size = System::Drawing::Size(288, 32);
			this->button5_creditos->TabIndex = 21;
			this->button5_creditos->Text = L"Mostrar créditos ";
			this->button5_creditos->UseVisualStyleBackColor = true;
			this->button5_creditos->Click += gcnew System::EventHandler(this, &MyForm_principal::button5_creditos_Click);
			// 
			// button3_salir
			// 
			this->button3_salir->BackColor = System::Drawing::Color::Transparent;
			this->button3_salir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3_salir.BackgroundImage")));
			this->button3_salir->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3_salir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3_salir->Font = (gcnew System::Drawing::Font(L"Ravie", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3_salir->ForeColor = System::Drawing::Color::White;
			this->button3_salir->Location = System::Drawing::Point(322, 473);
			this->button3_salir->Name = L"button3_salir";
			this->button3_salir->Size = System::Drawing::Size(101, 34);
			this->button3_salir->TabIndex = 22;
			this->button3_salir->Text = L"Salir";
			this->button3_salir->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button3_salir->UseVisualStyleBackColor = false;
			this->button3_salir->Click += gcnew System::EventHandler(this, &MyForm_principal::button3_salir_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Ravie", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(243, 345);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(272, 38);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Empezar el juego ";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm_principal::button1_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(216, 28);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(326, 311);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 23;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm_principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(745, 562);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button3_salir);
			this->Controls->Add(this->button5_creditos);
			this->Controls->Add(this->button2_instrucciones);
			this->Name = L"MyForm_principal";
			this->Text = L"MyForm_principal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
   
            private: System::Void button2_instrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
        		MyForm_instrucciones^ I1 = gcnew MyForm_instrucciones();
        		this->Hide();
        		I1->ShowDialog();
        		this->Show();
        	
            }
            private: System::Void button5_creditos_Click(System::Object^ sender, System::EventArgs^ e) {
        		MyForm_creditos^ Ii = gcnew MyForm_creditos();
        		this->Hide();
        		Ii->ShowDialog();
        		this->Show();
            }
            private: System::Void button3_salir_Click(System::Object^ sender, System::EventArgs^ e) {
        		this->Close();
            }
	       private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
			   MyForm_empezar^ f1 = gcnew MyForm_empezar();
			   f1->Show();
			   this->Visible = false;
	       }
};
}
