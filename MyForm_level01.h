#pragma once
#include "monigote.h"
namespace trabajofinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm_level01
	/// </summary>
	public ref class MyForm_level01 : public System::Windows::Forms::Form
	{
	public:
		MyForm_level01(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			p = gcnew Bitmap("personaje.png");
			objmonigote = new Humano(48,460);
			Mapa = gcnew Bitmap("mapa.jpeg");
		}
		void ColocaNombre(String^ s)
		{
			nombre = s ;
		}
	protected:
		/// <summary>
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ p;
		Bitmap^ Mapa;
		String ^nombre;



	protected:


	protected:
		Humano* objmonigote;
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm_level01()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-3, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(795, 560);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm_level01::timer1_Tick_1);
			// 
			// MyForm_level01
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 572);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm_level01";
			this->Text = L"MyForm_level01";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm_level01::MyForm_level01_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		buffer->Graphics->DrawImage(Mapa, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawString(nombre, gcnew Drawing::Font("Arial", 10, FontStyle::Bold), Brushes::Black, 120, 10);
		buffer->Graphics->DrawString("USUARIO : ", gcnew Drawing::Font("Arial", 10, FontStyle::Bold), Brushes::Black, 50, 10);
		objmonigote->Draw(buffer->Graphics, p);
		buffer->Render(g);
	}
	private: System::Void MyForm_level01_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objmonigote->movimientoMonigote(g, e->KeyCode);
	}
};
}
