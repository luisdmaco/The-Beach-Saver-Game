#pragma once
#include "controller.h"

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
			srand(time(NULL));
			InitializeComponent();
			
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			imgCleaner = gcnew Bitmap("personaje.png");
			
			Mapa = gcnew Bitmap("mapa.jpeg");
			imgTacho = gcnew Bitmap("tacho.png");
			imgBaño = gcnew Bitmap("baño.png");
			imgBasura = gcnew Bitmap("basura.png");
			imgEnemy = gcnew Bitmap("enemy.png");

			controller = new Controller(imgCleaner);
			controller->addEnemy(g, imgEnemy);
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
		Bitmap^ imgCleaner;
		Bitmap^ Mapa;
		Bitmap^ imgTacho;
		Bitmap^ imgBaño;
		Bitmap^ imgBasura;
		Bitmap^ imgEnemy;
		String ^nombre;
		Controller* controller;


	protected:


	protected:
		
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
			this->panel1->Location = System::Drawing::Point(-2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(700, 700);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm_level01::timer1_Tick_1);
			// 
			// MyForm_level01
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 702);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm_level01";
			this->Text = L"MyForm_level01";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm_level01::MyForm_level01_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm_level01::MyForm_level01_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::White);
		//collision
		
		//move (enemigos)
		controller->moverTodo(buffer->Graphics);
		//draw
		buffer->Graphics->DrawImage(Mapa, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawString(nombre, gcnew Drawing::Font("Arial", 10, FontStyle::Bold), Brushes::Black, 120, 10);
		buffer->Graphics->DrawString("USUARIO : ", gcnew Drawing::Font("Arial", 10, FontStyle::Bold), Brushes::Black, 50, 10);
		//objmonigote->draw(buffer->Graphics, imgCleaner);
		controller->dibujarTodo(buffer->Graphics, imgCleaner, imgEnemy, imgBaño, imgTacho, imgBasura);
		//render
		buffer->Render(g);
	}
	private: System::Void MyForm_level01_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controller->MovimientoMonigote(true, e->KeyCode);
	}
	private: System::Void MyForm_level01_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controller->MovimientoMonigote(false, e->KeyCode);
	}
};
}
//problemas con el mov del personaje

