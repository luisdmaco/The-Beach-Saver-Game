#pragma once
#include "controller.h"
#include "MyForm_creditos.h"
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
			controller->addTacho(imgTacho,50,buffer->Graphics->VisibleClipBounds.Height-100);
			controller->addBaño(imgBaño, 600, 555);

			contBaños = 0; contTachos = 1;
			//final
			
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
		int contBaños;
		int contTachos;

	private: System::Windows::Forms::Timer^ timerEnemy;
	private: System::Windows::Forms::Timer^ timerBasura;
	private: System::Windows::Forms::Timer^ timerEntierro;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lbBuyTacho;


	private: System::Windows::Forms::Label^ lbBuyBaño;



	private: System::Windows::Forms::Label^ lbVelocidad;

	private: System::Windows::Forms::Label^ lbBolsa;

	private: System::Windows::Forms::Label^ lbDinero;
	private: System::Windows::Forms::Label^ lbBuyBolsa;
	private: System::Windows::Forms::Label^ lbBasura;
	private: System::Windows::Forms::Label^ lbBaños;
	private: System::Windows::Forms::Label^ lbMicrobiologico;
	private: System::Windows::Forms::Timer^ timerMicrobiologicoBaños;
	private: System::Windows::Forms::Label^ lbCapacidadBolsa;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;



	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm_level01::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerEnemy = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerBasura = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerEntierro = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->lbCapacidadBolsa = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbVelocidad = (gcnew System::Windows::Forms::Label());
			this->lbBolsa = (gcnew System::Windows::Forms::Label());
			this->lbDinero = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lbBuyBolsa = (gcnew System::Windows::Forms::Label());
			this->lbBuyTacho = (gcnew System::Windows::Forms::Label());
			this->lbBuyBaño = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->lbBasura = (gcnew System::Windows::Forms::Label());
			this->lbBaños = (gcnew System::Windows::Forms::Label());
			this->lbMicrobiologico = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerMicrobiologicoBaños = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(686, 692);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm_level01::timer1_Tick_1);
			// 
			// timerEnemy
			// 
			this->timerEnemy->Enabled = true;
			this->timerEnemy->Interval = 1000;
			this->timerEnemy->Tick += gcnew System::EventHandler(this, &MyForm_level01::timerEnemy_Tick);
			// 
			// timerBasura
			// 
			this->timerBasura->Enabled = true;
			this->timerBasura->Interval = 500;
			this->timerBasura->Tick += gcnew System::EventHandler(this, &MyForm_level01::timerBasura_Tick);
			// 
			// timerEntierro
			// 
			this->timerEntierro->Enabled = true;
			this->timerEntierro->Tick += gcnew System::EventHandler(this, &MyForm_level01::timerEntierro_Tick);
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Controls->Add(this->groupBox3);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(704, 4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(237, 697);
			this->panel2->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::White;
			this->groupBox3->Controls->Add(this->lbCapacidadBolsa);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->lbVelocidad);
			this->groupBox3->Controls->Add(this->lbBolsa);
			this->groupBox3->Controls->Add(this->lbDinero);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Location = System::Drawing::Point(3, 554);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(231, 132);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"RECURSOS";
			// 
			// lbCapacidadBolsa
			// 
			this->lbCapacidadBolsa->AutoSize = true;
			this->lbCapacidadBolsa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCapacidadBolsa->Location = System::Drawing::Point(139, 81);
			this->lbCapacidadBolsa->Name = L"lbCapacidadBolsa";
			this->lbCapacidadBolsa->Size = System::Drawing::Size(17, 18);
			this->lbCapacidadBolsa->TabIndex = 7;
			this->lbCapacidadBolsa->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 81);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(104, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Capacidad de bolsa:";
			// 
			// lbVelocidad
			// 
			this->lbVelocidad->AutoSize = true;
			this->lbVelocidad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbVelocidad->Location = System::Drawing::Point(139, 100);
			this->lbVelocidad->Name = L"lbVelocidad";
			this->lbVelocidad->Size = System::Drawing::Size(17, 18);
			this->lbVelocidad->TabIndex = 5;
			this->lbVelocidad->Text = L"5";
			// 
			// lbBolsa
			// 
			this->lbBolsa->AutoSize = true;
			this->lbBolsa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBolsa->Location = System::Drawing::Point(139, 57);
			this->lbBolsa->Name = L"lbBolsa";
			this->lbBolsa->Size = System::Drawing::Size(17, 18);
			this->lbBolsa->TabIndex = 4;
			this->lbBolsa->Text = L"0";
			// 
			// lbDinero
			// 
			this->lbDinero->AutoSize = true;
			this->lbDinero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbDinero->Location = System::Drawing::Point(138, 25);
			this->lbDinero->Name = L"lbDinero";
			this->lbDinero->Size = System::Drawing::Size(17, 18);
			this->lbDinero->TabIndex = 3;
			this->lbDinero->Text = L"0";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(32, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Velocidad:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Basura en la mano:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Dinero:";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::White;
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->lbBuyBolsa);
			this->groupBox2->Controls->Add(this->lbBuyTacho);
			this->groupBox2->Controls->Add(this->lbBuyBaño);
			this->groupBox2->Enabled = false;
			this->groupBox2->Location = System::Drawing::Point(3, 255);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(231, 248);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"TIENDA (cerrado por covid :c)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe Script", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(140, 158);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(73, 51);
			this->label14->TabIndex = 8;
			this->label14->Text = L" \"presiona\r\n    la tecla \r\n      (H) \"";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(94, 177);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(46, 13);
			this->label13->TabIndex = 7;
			this->label13->Text = L"----------->";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(94, 111);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(46, 13);
			this->label12->TabIndex = 6;
			this->label12->Text = L"----------->";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(94, 40);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(46, 13);
			this->label11->TabIndex = 5;
			this->label11->Text = L"----------->";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe Script", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(140, 90);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(73, 51);
			this->label10->TabIndex = 4;
			this->label10->Text = L" \"presiona\r\n    la tecla \r\n      (G) \"";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe Script", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(146, 16);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 51);
			this->label9->TabIndex = 3;
			this->label9->Text = L" \"presiona\r\n    la tecla \r\n      (F) \"";
			// 
			// lbBuyBolsa
			// 
			this->lbBuyBolsa->AutoSize = true;
			this->lbBuyBolsa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbBuyBolsa->Font = (gcnew System::Drawing::Font(L"Stencil", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBuyBolsa->Location = System::Drawing::Point(6, 158);
			this->lbBuyBolsa->Name = L"lbBuyBolsa";
			this->lbBuyBolsa->Size = System::Drawing::Size(69, 42);
			this->lbBuyBolsa->TabIndex = 2;
			this->lbBuyBolsa->Text = L" Ampliar\r\n   Bolsa\r\n  (S/.750) : ";
			// 
			// lbBuyTacho
			// 
			this->lbBuyTacho->AutoSize = true;
			this->lbBuyTacho->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbBuyTacho->Font = (gcnew System::Drawing::Font(L"Stencil", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBuyTacho->Location = System::Drawing::Point(7, 91);
			this->lbBuyTacho->Name = L"lbBuyTacho";
			this->lbBuyTacho->Size = System::Drawing::Size(68, 42);
			this->lbBuyTacho->TabIndex = 1;
			this->lbBuyTacho->Text = L" Comprar \r\n  Tacho\r\n (S/.350) : ";
			this->lbBuyTacho->Click += gcnew System::EventHandler(this, &MyForm_level01::lbBuyTacho_Click);
			// 
			// lbBuyBaño
			// 
			this->lbBuyBaño->AutoSize = true;
			this->lbBuyBaño->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lbBuyBaño->Font = (gcnew System::Drawing::Font(L"Stencil", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBuyBaño->Location = System::Drawing::Point(6, 25);
			this->lbBuyBaño->Name = L"lbBuyBaño";
			this->lbBuyBaño->Size = System::Drawing::Size(69, 42);
			this->lbBuyBaño->TabIndex = 0;
			this->lbBuyBaño->Text = L" Comprar\r\n    Baño \r\n  (S/.650) : ";
			this->lbBuyBaño->Click += gcnew System::EventHandler(this, &MyForm_level01::lbBuyBaño_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->progressBar1);
			this->groupBox1->Controls->Add(this->lbBasura);
			this->groupBox1->Controls->Add(this->lbBaños);
			this->groupBox1->Controls->Add(this->lbMicrobiologico);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(8, 64);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(226, 169);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Salubridad de la Playa";
			// 
			// progressBar1
			// 
			this->progressBar1->ForeColor = System::Drawing::Color::Lime;
			this->progressBar1->Location = System::Drawing::Point(10, 56);
			this->progressBar1->Maximum = 2000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(198, 23);
			this->progressBar1->TabIndex = 9;
			this->progressBar1->Value = 2;
			// 
			// lbBasura
			// 
			this->lbBasura->AutoSize = true;
			this->lbBasura->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBasura->Location = System::Drawing::Point(141, 113);
			this->lbBasura->Name = L"lbBasura";
			this->lbBasura->Size = System::Drawing::Size(17, 18);
			this->lbBasura->TabIndex = 8;
			this->lbBasura->Text = L"0";
			// 
			// lbBaños
			// 
			this->lbBaños->AutoSize = true;
			this->lbBaños->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBaños->Location = System::Drawing::Point(141, 87);
			this->lbBaños->Name = L"lbBaños";
			this->lbBaños->Size = System::Drawing::Size(17, 18);
			this->lbBaños->TabIndex = 7;
			this->lbBaños->Text = L"0";
			// 
			// lbMicrobiologico
			// 
			this->lbMicrobiologico->AutoSize = true;
			this->lbMicrobiologico->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMicrobiologico->Location = System::Drawing::Point(104, 29);
			this->lbMicrobiologico->Name = L"lbMicrobiologico";
			this->lbMicrobiologico->Size = System::Drawing::Size(21, 24);
			this->lbMicrobiologico->TabIndex = 6;
			this->lbMicrobiologico->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Basura recogida:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(27, 91);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(95, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Numero de Baños:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(148, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Nivel microbiologico del agua:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Stencil", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(82, 5);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(20, 5, 20, 5);
			this->label1->Size = System::Drawing::Size(93, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MENU";
			// 
			// timerMicrobiologicoBaños
			// 
			this->timerMicrobiologicoBaños->Enabled = true;
			this->timerMicrobiologicoBaños->Interval = 250;
			this->timerMicrobiologicoBaños->Tick += gcnew System::EventHandler(this, &MyForm_level01::timerMicrobiologicoBaños_Tick);
			// 
			// MyForm_level01
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 749);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm_level01";
			this->Text = L"MyForm_level01";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm_level01::MyForm_level01_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm_level01::MyForm_level01_KeyUp);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::White);
		//datos de menu
		this->lbBolsa->Text=Convert::ToString(controller->getCleaner()->getBolsa());
		this->lbCapacidadBolsa->Text=Convert::ToString(controller->getCleaner()->getCapacidadBolsa());
		this->lbDinero->Text = Convert::ToString(controller->getCleaner()->getDinero());
		this->progressBar1->Value = controller->getMicrobiologico(); // funcion para la barra del nvel microbiologico
		this->lbMicrobiologico->Text = Convert::ToString(controller->getMicrobiologico());
		this->lbBaños->Text = Convert::ToString(controller->cantBaños());
		this->lbBasura->Text = Convert::ToString(controller->getLimpiezaPlaya());
		//collision
		controller->collision(buffer->Graphics);
		//move (enemigos)
		controller->moverTodo(buffer->Graphics);
		//draw

		buffer->Graphics->DrawImage(Mapa, 0, 0, panel1->Width, panel1->Height);
		buffer->Graphics->DrawString(nombre, gcnew Drawing::Font("Arial", 16, FontStyle::Bold), Brushes::White, 170, 10);
		buffer->Graphics->DrawString("USUARIO : ", gcnew Drawing::Font("Arial", 16, FontStyle::Bold), Brushes::White, 50, 10);
		//objmonigote->draw(buffer->Graphics, imgCleaner);
		controller->dibujarTodo(buffer->Graphics, imgCleaner, imgEnemy, imgBaño, imgTacho, imgBasura);

		// validacion para abrir la tienda 
		if (controller->getCleaner()->getDinero() > 350)
		{
			groupBox2->Enabled = true;
			groupBox2->Text = "TIENDA ABIERTA (compra lo necesario )";
			
		}
		else
		{
			groupBox2->Enabled = false;
			groupBox2->Text = "TIENDA CERRADA (por covid )";
		}

		
		//render
		buffer->Render(g);
		//final
		if (controller->getMicrobiologico() >=  800 && controller->getLimpiezaPlaya() > 130 && controller->cantBaños() > 2) // funcion opcional de ganar 
		{
			timer1->Enabled = false;
			timerBasura->Enabled = false;
			timerEnemy->Enabled = false;
			timerEntierro->Enabled = false;
			timerMicrobiologicoBaños->Enabled = false;
			timerBasura->Enabled = false;
			progressBar1->Enabled = false;
			MessageBox::Show(" GANASTE : el nivel Microbiologico es mayor a 800 , la basura recogida es mayor a 130  y colocaste mas de 3 baños  ");
			MyForm_creditos^ Ii = gcnew MyForm_creditos();
			this->Hide();
			Ii->ShowDialog();
			this->Close();
		}

		if (controller->getMicrobiologico() < 0)  // funcion opcional de perder 
		{
			timer1->Enabled = false;
			timerBasura->Enabled = false;
			timerEnemy->Enabled = false;
			timerEntierro->Enabled = false;
			timerMicrobiologicoBaños->Enabled = false;
			timerBasura->Enabled = false;
			progressBar1->Enabled = false;
			MessageBox::Show("Game Over");
		}
		
	}
	private: System::Void MyForm_level01_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controller->MovimientoMonigote(true, e->KeyCode);

		if (groupBox2->Enabled == true ) 
		{
			if (e->KeyCode== Keys::F && controller->getCleaner()->getDinero() >= 650 && controller->cantBaños() < 4) // para comprar un baño 
			{
				controller->addBaño(imgBaño, rand() % 900, rand() % 600); // hubicasion del baño 
				controller->getCleaner()->setDinero(controller->getCleaner()->getDinero()-650);  // resta el num de dinero al momento de comprar
				timer1->Interval += 30;  // funcion opcional para disminur la velocidad 
			}
			// el codigo de abajo es de los tachos y me sale error al momento de agregarlo 
			if (e->KeyCode == Keys::G && controller->getCleaner()->getDinero() >= 350 && controller->cantTAchos() < 4) // para comprar un tacho 
			{
				controller->addTacho(imgTacho, rand() % 900, rand() % 600); // hubicacion del tacho 
				controller->getCleaner()->setDinero(controller->getCleaner()->getDinero() - 350);  // resta el num de dinero al momento de comprar
				timer1->Interval += 30;  // funcion opcional para disminur la velocidad 
			
			}
			if (e->KeyCode == Keys::H && controller->getCleaner()->getDinero() >=  750) // para ampliar la capasidad de la bolsa 
			{
				controller->getCleaner()->setCapacidadBolsa(controller->getCleaner()->getCapacidadBolsa() + 4);
				controller->getCleaner()->setDinero(controller->getCleaner()->getDinero() - 750);  // resta el num de dinero al momento de comprar

			}
			
		}
	}
	private: System::Void MyForm_level01_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controller->MovimientoMonigote(false, e->KeyCode);
	}
	private: System::Void timerEnemy_Tick(System::Object^ sender, System::EventArgs^ e) {
		controller->addEnemy(g,imgEnemy);
		
	}
	private: System::Void timerBasura_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		int i=rand() % controller->cantEnem();
		controller->addbasura(imgBasura,controller->getEnemigo(i)->getPosicionX(), controller->getEnemigo(i)->getPosicionY()+(controller->getEnemigo(i)->getHeight())/2);
	}
	private: System::Void timerEntierro_Tick(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < controller->cantBasu(); i++)
		{
			controller->getBasura(i)->addTime();//a cada uno de las basuras en el campo le adiciono 100 milisegundos a su reloj interno
			controller->getBasura(i)->cambioEstado();
		}
	}
	 private: System::Void timerMicrobiologicoBaños_Tick(System::Object^ sender, System::EventArgs^ e) {
		 controller->addNivelMicrobiologico();
	 }
	private: System::Void lbBuyBaño_Click(System::Object^ sender, System::EventArgs^ e) {//DESHABILITADO PUES SE USA TECLAS
		
		/*controller->addBaño(imgBaño, 600 ,555);*/ //no reconoce a la colision
	}
	private: System::Void lbBuyTacho_Click(System::Object^ sender, System::EventArgs^ e) {//DESHABILITADO PUES AHORA SE USA TECLAS
		/*controller->addTacho(imgTacho, 100, buffer->Graphics->VisibleClipBounds.Height - 500);*/ //no reconoloce la colison y tpmko al vector al parecer (observacion)
	}

};
}


