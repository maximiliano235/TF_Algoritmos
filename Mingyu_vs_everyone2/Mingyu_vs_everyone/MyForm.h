#pragma once
#include "CJuego.h"
#include "CFondo.h"
#include "CFondoJuego.h"
#include "fstream"
#include "CCola.h"
#include "iostream"
#include "string"
#include "sstream"

namespace Mingyuvseveryone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		//Variables para los beacons y atributos
		/*int* beacons = new int[1000000];*/

		
		int* ambiente = new int[1000000];
		int* cantidadenemigos = new int[1000000];
		int* cantidadmonedas = new int[1000000];
		int* cantidadtrampas = new int[1000000];

		

		int Jugador1, Jugador2, Jugador3;
		int Estatico1, Estatico2, Estatico3;

		int tiempoMartillo;
		int tiempoFuegoMorado;
		int tiempoFuegoNormal;

		bool FuegoMorado;
		bool FuegoNormal;
		bool Martillo;
		bool Portal;

		bool inicio;
		bool teletransportar;
		bool menu2;
		bool menu;
		bool intro;

		int beacon;
		String^ Ambiente;

		CCola<Keys>* Cola;

		CJuego *objJuego;
		CFondo *objFondo;
		CFondoJuego *objFondoJuego;
		Graphics^ g;
		BufferedGraphics^ buffer;

		//Fondo de inicio
		Bitmap^ imgFondo;
		Bitmap^ imgAmbiente0;
		Bitmap^ imgAmbiente1;
		Bitmap^ imgAmbiente2;
		Bitmap^ imgAmbiente3;
		Bitmap^ imgRojo;
		Bitmap^ imgContinuar;

		//HP
		Bitmap^ imgHP;
		Bitmap^ imgMedidor;

		//Jugadores
		Bitmap^ imgMely;
		Bitmap^ imgMingyu; //La poni que saltaba encima de Canaval en el TP
		Bitmap^ imgPonky;

		//Portal
		Bitmap^ imgPortal;

		//Enemigos
		Bitmap^ imgAcosta;
		Bitmap^ imgCanaval;
		Bitmap^ imgIquise;
		Bitmap^ imgMedina;

		//Ataques
		Bitmap^ imgMartillo;
		Bitmap^ imgFuego;
		Bitmap^ imgFuegoMorado;
		Bitmap^ Moneda;
		Bitmap^ Trampa;
		//Ambiente
		Bitmap^ imgAgua;
		Bitmap^ imgArena;
		Bitmap^ imgCasa;
		Bitmap^ imgCesped;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	public:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btn_comprobar;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btn_ir;
	private: System::Windows::Forms::CheckBox^  chBoxEnemigos;
	private: System::Windows::Forms::CheckBox^  chMonedas;
	private: System::Windows::Forms::CheckBox^  chTrampas;

	private: System::Windows::Forms::CheckBox^  chAmbiente;
	private: System::Windows::Forms::TextBox^  txtbxCantidad;
	private: System::Windows::Forms::Label^  lbl_BusqCantidad;


	private: System::Windows::Forms::NumericUpDown^  num_mapa;
	private: System::Windows::Forms::Label^  lbl_Ambiente;
	private: System::Windows::Forms::Label^  lbl_canEnemigos;

	private: System::Windows::Forms::Label^  lbl_Monedas;
	private: System::Windows::Forms::Label^  lbl_Trampas;
	private: System::Windows::Forms::Button^  btn_Buscar;
	private: System::Windows::Forms::Button^  bt_Jugar2;

	private: System::Windows::Forms::Label^  lbl_numMapa;


	public:

	public:

	public:

	public:
		Bitmap^ imgLava;

		

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_comprobar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btn_ir = (gcnew System::Windows::Forms::Button());
			this->chBoxEnemigos = (gcnew System::Windows::Forms::CheckBox());
			this->chMonedas = (gcnew System::Windows::Forms::CheckBox());
			this->chTrampas = (gcnew System::Windows::Forms::CheckBox());
			this->chAmbiente = (gcnew System::Windows::Forms::CheckBox());
			this->txtbxCantidad = (gcnew System::Windows::Forms::TextBox());
			this->lbl_BusqCantidad = (gcnew System::Windows::Forms::Label());
			this->num_mapa = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_Ambiente = (gcnew System::Windows::Forms::Label());
			this->lbl_canEnemigos = (gcnew System::Windows::Forms::Label());
			this->lbl_Monedas = (gcnew System::Windows::Forms::Label());
			this->lbl_Trampas = (gcnew System::Windows::Forms::Label());
			this->btn_Buscar = (gcnew System::Windows::Forms::Button());
			this->bt_Jugar2 = (gcnew System::Windows::Forms::Button());
			this->lbl_numMapa = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_mapa))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(710, 334);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1172, 684);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Enabled = false;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(37, 134);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Número de mapa:";
			this->label1->Visible = false;
			// 
			// btn_comprobar
			// 
			this->btn_comprobar->Enabled = false;
			this->btn_comprobar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_comprobar->Location = System::Drawing::Point(43, 196);
			this->btn_comprobar->Margin = System::Windows::Forms::Padding(4);
			this->btn_comprobar->Name = L"btn_comprobar";
			this->btn_comprobar->Size = System::Drawing::Size(271, 119);
			this->btn_comprobar->TabIndex = 3;
			this->btn_comprobar->Text = L"¿Qué hay ahí\?";
			this->btn_comprobar->UseVisualStyleBackColor = true;
			this->btn_comprobar->Visible = false;
			this->btn_comprobar->Click += gcnew System::EventHandler(this, &MyForm::btn_comprobar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(37, 379);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Tipo de ambiente: ";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Enabled = false;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(37, 421);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(235, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Cantidad de enemigos:";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Enabled = false;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(37, 463);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(236, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Cantidad de monedas: ";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Enabled = false;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(37, 506);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(225, 25);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Cantidad de trampas: ";
			this->label5->Visible = false;
			// 
			// btn_ir
			// 
			this->btn_ir->Enabled = false;
			this->btn_ir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ir->Location = System::Drawing::Point(606, 439);
			this->btn_ir->Margin = System::Windows::Forms::Padding(4);
			this->btn_ir->Name = L"btn_ir";
			this->btn_ir->Size = System::Drawing::Size(271, 119);
			this->btn_ir->TabIndex = 8;
			this->btn_ir->Text = L"Jugar";
			this->btn_ir->UseVisualStyleBackColor = true;
			this->btn_ir->Visible = false;
			this->btn_ir->Click += gcnew System::EventHandler(this, &MyForm::btn_ir_Click);
			// 
			// chBoxEnemigos
			// 
			this->chBoxEnemigos->AutoSize = true;
			this->chBoxEnemigos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chBoxEnemigos->Location = System::Drawing::Point(1016, 142);
			this->chBoxEnemigos->Name = L"chBoxEnemigos";
			this->chBoxEnemigos->Size = System::Drawing::Size(118, 28);
			this->chBoxEnemigos->TabIndex = 9;
			this->chBoxEnemigos->Text = L"Enemigos";
			this->chBoxEnemigos->UseVisualStyleBackColor = true;
			this->chBoxEnemigos->Visible = false;
			this->chBoxEnemigos->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// chMonedas
			// 
			this->chMonedas->AutoSize = true;
			this->chMonedas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chMonedas->Location = System::Drawing::Point(1172, 142);
			this->chMonedas->Name = L"chMonedas";
			this->chMonedas->Size = System::Drawing::Size(111, 28);
			this->chMonedas->TabIndex = 10;
			this->chMonedas->Text = L"Monedas";
			this->chMonedas->UseVisualStyleBackColor = true;
			this->chMonedas->Visible = false;
			// 
			// chTrampas
			// 
			this->chTrampas->AutoSize = true;
			this->chTrampas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chTrampas->Location = System::Drawing::Point(1309, 142);
			this->chTrampas->Name = L"chTrampas";
			this->chTrampas->Size = System::Drawing::Size(106, 28);
			this->chTrampas->TabIndex = 11;
			this->chTrampas->Text = L"Trampas";
			this->chTrampas->UseVisualStyleBackColor = true;
			this->chTrampas->Visible = false;
			this->chTrampas->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// chAmbiente
			// 
			this->chAmbiente->AutoSize = true;
			this->chAmbiente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chAmbiente->Location = System::Drawing::Point(1437, 142);
			this->chAmbiente->Name = L"chAmbiente";
			this->chAmbiente->Size = System::Drawing::Size(113, 28);
			this->chAmbiente->TabIndex = 12;
			this->chAmbiente->Text = L"Ambiente";
			this->chAmbiente->UseVisualStyleBackColor = true;
			this->chAmbiente->Visible = false;
			// 
			// txtbxCantidad
			// 
			this->txtbxCantidad->Location = System::Drawing::Point(1016, 192);
			this->txtbxCantidad->Name = L"txtbxCantidad";
			this->txtbxCantidad->Size = System::Drawing::Size(94, 22);
			this->txtbxCantidad->TabIndex = 13;
			this->txtbxCantidad->Visible = false;
			// 
			// lbl_BusqCantidad
			// 
			this->lbl_BusqCantidad->AutoSize = true;
			this->lbl_BusqCantidad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_BusqCantidad->Location = System::Drawing::Point(919, 192);
			this->lbl_BusqCantidad->Name = L"lbl_BusqCantidad";
			this->lbl_BusqCantidad->Size = System::Drawing::Size(91, 25);
			this->lbl_BusqCantidad->TabIndex = 14;
			this->lbl_BusqCantidad->Text = L"Cantidad";
			this->lbl_BusqCantidad->Visible = false;
			// 
			// num_mapa
			// 
			this->num_mapa->Enabled = false;
			this->num_mapa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->num_mapa->Location = System::Drawing::Point(42, 62);
			this->num_mapa->Margin = System::Windows::Forms::Padding(4);
			this->num_mapa->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->num_mapa->Name = L"num_mapa";
			this->num_mapa->Size = System::Drawing::Size(220, 34);
			this->num_mapa->TabIndex = 1;
			this->num_mapa->Visible = false;
			this->num_mapa->ValueChanged += gcnew System::EventHandler(this, &MyForm::num_mapa_ValueChanged);
			// 
			// lbl_Ambiente
			// 
			this->lbl_Ambiente->AutoSize = true;
			this->lbl_Ambiente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Ambiente->Location = System::Drawing::Point(236, 379);
			this->lbl_Ambiente->Name = L"lbl_Ambiente";
			this->lbl_Ambiente->Size = System::Drawing::Size(95, 25);
			this->lbl_Ambiente->TabIndex = 15;
			this->lbl_Ambiente->Text = L"Ambiente";
			this->lbl_Ambiente->Visible = false;
			// 
			// lbl_canEnemigos
			// 
			this->lbl_canEnemigos->AutoSize = true;
			this->lbl_canEnemigos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_canEnemigos->Location = System::Drawing::Point(292, 421);
			this->lbl_canEnemigos->Name = L"lbl_canEnemigos";
			this->lbl_canEnemigos->Size = System::Drawing::Size(141, 25);
			this->lbl_canEnemigos->TabIndex = 16;
			this->lbl_canEnemigos->Text = L"CantEnemigos";
			this->lbl_canEnemigos->Visible = false;
			// 
			// lbl_Monedas
			// 
			this->lbl_Monedas->AutoSize = true;
			this->lbl_Monedas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Monedas->Location = System::Drawing::Point(292, 463);
			this->lbl_Monedas->Name = L"lbl_Monedas";
			this->lbl_Monedas->Size = System::Drawing::Size(136, 25);
			this->lbl_Monedas->TabIndex = 17;
			this->lbl_Monedas->Text = L"CantMonedas";
			this->lbl_Monedas->Visible = false;
			// 
			// lbl_Trampas
			// 
			this->lbl_Trampas->AutoSize = true;
			this->lbl_Trampas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Trampas->Location = System::Drawing::Point(292, 506);
			this->lbl_Trampas->Name = L"lbl_Trampas";
			this->lbl_Trampas->Size = System::Drawing::Size(132, 25);
			this->lbl_Trampas->TabIndex = 18;
			this->lbl_Trampas->Text = L"CantTrampas";
			this->lbl_Trampas->Visible = false;
			// 
			// btn_Buscar
			// 
			this->btn_Buscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Buscar->Location = System::Drawing::Point(1016, 243);
			this->btn_Buscar->Name = L"btn_Buscar";
			this->btn_Buscar->Size = System::Drawing::Size(116, 31);
			this->btn_Buscar->TabIndex = 19;
			this->btn_Buscar->Text = L"Buscar";
			this->btn_Buscar->UseVisualStyleBackColor = true;
			this->btn_Buscar->Visible = false;
			this->btn_Buscar->Click += gcnew System::EventHandler(this, &MyForm::btn_Buscar_Click);
			// 
			// bt_Jugar2
			// 
			this->bt_Jugar2->Enabled = false;
			this->bt_Jugar2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_Jugar2->Location = System::Drawing::Point(606, 439);
			this->bt_Jugar2->Margin = System::Windows::Forms::Padding(4);
			this->bt_Jugar2->Name = L"bt_Jugar2";
			this->bt_Jugar2->Size = System::Drawing::Size(271, 119);
			this->bt_Jugar2->TabIndex = 20;
			this->bt_Jugar2->Text = L"Jugar";
			this->bt_Jugar2->UseVisualStyleBackColor = true;
			this->bt_Jugar2->Visible = false;
			this->bt_Jugar2->Click += gcnew System::EventHandler(this, &MyForm::bt_Jugar2_Click);
			// 
			// lbl_numMapa
			// 
			this->lbl_numMapa->AutoSize = true;
			this->lbl_numMapa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numMapa->Location = System::Drawing::Point(265, 138);
			this->lbl_numMapa->Name = L"lbl_numMapa";
			this->lbl_numMapa->Size = System::Drawing::Size(103, 25);
			this->lbl_numMapa->TabIndex = 21;
			this->lbl_numMapa->Text = L"NumMapa";
			this->lbl_numMapa->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->lbl_numMapa);
			this->Controls->Add(this->bt_Jugar2);
			this->Controls->Add(this->btn_Buscar);
			this->Controls->Add(this->lbl_Trampas);
			this->Controls->Add(this->lbl_Monedas);
			this->Controls->Add(this->lbl_canEnemigos);
			this->Controls->Add(this->lbl_Ambiente);
			this->Controls->Add(this->lbl_BusqCantidad);
			this->Controls->Add(this->txtbxCantidad);
			this->Controls->Add(this->chAmbiente);
			this->Controls->Add(this->chTrampas);
			this->Controls->Add(this->chMonedas);
			this->Controls->Add(this->chBoxEnemigos);
			this->Controls->Add(this->btn_ir);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_comprobar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->num_mapa);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Mingyu vs Everyone: Canaval\'s Revenge";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num_mapa))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		inicio = false;
		intro = true;
		menu = false;
		menu2 = false;
		beacon = 0;
		Random r;
		objJuego = new CJuego(400, 348, 10, 0);
		g = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		buffer = context->Allocate(g, this->ClientRectangle);
		imgMely = gcnew Bitmap("mely.png");
		imgMingyu = gcnew Bitmap("mingyu.png");
		imgPonky = gcnew Bitmap("ponky.png");
		imgHP = gcnew Bitmap("hp.png");
		imgMedidor = gcnew Bitmap("medidor.png");
		imgFondo = gcnew Bitmap("canaval_revenge.jpeg");
		imgRojo = gcnew Bitmap("rojo.png");
		imgContinuar = gcnew Bitmap("tecla_continuar.png");
		imgFuego = gcnew Bitmap("feu2_20_gbp2.png");
		imgFuegoMorado = gcnew Bitmap("feu2_20_gbp_morado2.png");
		imgMartillo = gcnew Bitmap("hammer.png");
		imgPortal = gcnew Bitmap("portal_sprite2.png");
		Moneda = gcnew Bitmap("moneda.png");
		Trampa = gcnew Bitmap("Traps.png");
		imgCesped = gcnew Bitmap("cesped_fondo.jpg");
		imgCanaval = gcnew Bitmap("canaval.jpg");
		imgAmbiente0 = gcnew Bitmap("montania.jpg");
		imgAmbiente1 = gcnew Bitmap("piso.jpg");
		imgAmbiente2 = gcnew Bitmap("fondo_seco.jpg");
		imgAmbiente3 = gcnew Bitmap("cesped_fondo.jpg");
		objFondo = new CFondo(-80, -600);
		objFondoJuego = new CFondoJuego(0, 0);
		Jugador1 = 0;
		Jugador2 = 0;
		Jugador3 = 0;
		Estatico1 = 0;
		Estatico2 = 0;
		Estatico3 = 0;

		FuegoMorado = false;
		FuegoNormal = false;
		Martillo = false;
		Portal = false;
		this->Cola = new CCola<Keys>();
		tiempoMartillo = 0;
		tiempoFuegoMorado = 0;
		tiempoFuegoNormal = 0;
		/*
		//Generar 1 millon de variables (Falta agregar el tema de guardado)
		for (int i = 0; i < 1000000; i++)
		{
			beacons[i] = i+1;
			ambiente[i] = r.Next(0, 3);
			tipoenemigos[i] = r.Next(0, 3);
			cantidadenemigos[i] = r.Next(5, 15);
			jefe[i] = r.Next(0, 2);
			if (jefe[i] == 1)
			{
				tipojefe[i] = r.Next(1, 4);
			}
			else
			{
				tipojefe[i] = 0;
			}
			cantidaditems[i] = r.Next(1, 30);
			tipoitems[i] = r.Next(0, 3);
		}
		*/

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(this->BackColor);

		if (menu2 == true) {
			this->pictureBox1->Visible = true;
			this->lbl_numMapa->Visible = true;
			this->lbl_Ambiente->Visible = true;
			this->lbl_Monedas->Visible = true;
			this->lbl_Trampas->Visible = true;
			lbl_canEnemigos->Visible = true;
			CNivel* n = objJuego->getNivelat();
			String^ numMapa = gcnew String(n->getID().ToString());
			lbl_numMapa->Text = numMapa;
			String^ Ambiente = gcnew String(n->getAmbiente().ToString());
			lbl_Ambiente->Text = Ambiente;
			String^ canMonedas = gcnew String(n->getcantMonedas().ToString());
			lbl_Monedas->Text = canMonedas;
			String^ canTrampas = gcnew String(n->getcantTrampas().ToString());
			lbl_Trampas->Text = canTrampas;
			String^ canEnemigos = gcnew String(n->getCantEnemigos().ToString());
			lbl_canEnemigos->Text = canEnemigos;
			this->label1->Visible = true;
			this->label2->Visible = true;
			this->label3->Visible = true;
			this->label4->Visible = true;
			this->label5->Visible = true;
			lbl_BusqCantidad->Visible = true;
			btn_Buscar->Enabled = true;
			btn_Buscar->Visible = true;
			chAmbiente->Enabled = true;
			chAmbiente->Visible = true;
			txtbxCantidad->Visible = true;
			txtbxCantidad->Enabled = true;
			chBoxEnemigos->Visible = true;
			chBoxEnemigos->Enabled = true;
			chMonedas->Visible = true;
			chMonedas->Enabled = true;
			chTrampas->Visible = true;
			chTrampas->Enabled = true;
			this->btn_comprobar->Enabled = true;
			this->btn_comprobar->Visible = true;
			this->bt_Jugar2->Enabled = true;
			bt_Jugar2->Visible = true;
		}
		if (menu == true)
		{
			this->pictureBox1->Visible = true;
			this->lbl_numMapa->Visible = true;
			this->lbl_Ambiente->Visible = true;
			this->lbl_Monedas->Visible = true;
			this->lbl_Trampas->Visible = true;
			lbl_canEnemigos->Visible = true;
			CNivel* n=objJuego->getNivelat();
			String^ numMapa = gcnew String(n->getID().ToString());
			lbl_numMapa->Text = numMapa;
			Ambiente = gcnew String(n->getAmbiente().ToString());
			lbl_Ambiente->Text = Ambiente;
			String^ canMonedas = gcnew String(n->getcantMonedas().ToString());
			lbl_Monedas->Text = canMonedas;
			String^ canTrampas = gcnew String(n->getcantTrampas().ToString());
			lbl_Trampas->Text = canTrampas;
			String^ canEnemigos = gcnew String(n->getCantEnemigos().ToString());
			lbl_canEnemigos->Text = canEnemigos;
			this->label1->Visible = true;
			this->label2->Visible = true;
			this->label3->Visible = true;
			this->label4->Visible = true;
			this->label5->Visible = true;
			this->btn_comprobar->Enabled = true;
			this->btn_comprobar->Visible = true;
			this->btn_ir->Enabled = true;
			this->btn_ir->Visible = true;
			this->num_mapa->Enabled = false;
			this->num_mapa->Visible = false;
		}
		if (intro == true)
		{
			objFondo->Dibujar(buffer->Graphics, imgFondo, imgRojo, imgContinuar);
		}
		
		if (menu == false && intro == false&& menu2== false)
		{
			objFondoJuego->Dibujar(buffer->Graphics, imgAmbiente0);

			objJuego->Dibujar(buffer->Graphics, imgMingyu, imgMely, imgPonky, imgHP, imgMedidor, imgFuego, imgFuegoMorado, imgMartillo, imgPortal,Moneda,Trampa,imgCesped, imgCanaval);
			objJuego->Mover_Enemigo(this->ClientRectangle.Width, this->ClientRectangle.Height);
			//Usar multiples teclas a la vez
		//Tecnicamente el Timer repite el uso de las teclas
			if (tiempoMartillo == 1)
			{
				objJuego->Mover_Principal(Cola->desencolar());
			}
			if (tiempoMartillo > 0)
			{
				tiempoMartillo -= 1;
			}

			if (tiempoFuegoMorado == 1)
			{
				objJuego->Mover_Principal(Cola->desencolar());
			}
			if (tiempoFuegoMorado > 0)
			{
				tiempoFuegoMorado -= 1;
			}

			if (tiempoFuegoNormal == 1)
			{
				objJuego->Mover_Principal(Cola->desencolar());
			}
			if (tiempoFuegoNormal > 0)
			{
				tiempoFuegoNormal -= 1;
			}

			if (Jugador1 == 1)
			{
				objJuego->Mover_Principal(Keys::Up);
			}
			else if (Jugador1 == 2)
			{
				objJuego->Mover_Principal(Keys::Down);
			}
			else if (Jugador1 == 3)
			{
				objJuego->Mover_Principal(Keys::Right);
			}
			else if (Jugador1 == 4)
			{
				objJuego->Mover_Principal(Keys::Left);
			}

			if (Jugador2 == 1)
			{
				objJuego->Mover_Principal(Keys::T);
			}
			else if (Jugador2 == 2)
			{
				objJuego->Mover_Principal(Keys::G);
			}
			else if (Jugador2 == 3)
			{
				objJuego->Mover_Principal(Keys::H);
			}
			else if (Jugador2 == 4)
			{
				objJuego->Mover_Principal(Keys::F);
			}

			if (Jugador3 == 1)
			{
				objJuego->Mover_Principal(Keys::W);
			}
			else if (Jugador3 == 2)
			{
				objJuego->Mover_Principal(Keys::S);
			}
			else if (Jugador3 == 3)
			{
				objJuego->Mover_Principal(Keys::D);
			}
			else if (Jugador3 == 4)
			{
				objJuego->Mover_Principal(Keys::A);
			}

			if (FuegoMorado == true)
			{
				objJuego->Mover_Principal(Keys::Y);
				FuegoMorado = false;
			}
			if (FuegoNormal == true)
			{
				objJuego->Mover_Principal(Keys::Q);
				FuegoNormal = false;
			}
			if (Martillo == true)
			{
				objJuego->Mover_Principal(Keys::C);
				Martillo = false;
			}
			if (Portal == true)
			{
				objJuego->Mover_Principal(Keys::R);
				Portal = false;
			}
			if (objJuego->get_Teletransportar() == true || objJuego->getPerdiste() == true)
			{
				menu2 = true;
			}

		}
		buffer->Render(g);
	}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (inicio == false)
		{
			
		}
		else
		{
			if (e->KeyData == Keys::Up)
			{
				Jugador1 = 1;
			}
			else if (e->KeyData == Keys::Down)
			{
				Jugador1 = 2;
			}
			else if (e->KeyData == Keys::Right)
			{
				Jugador1 = 3;
			}
			else if (e->KeyData == Keys::Left)
			{
				Jugador1 = 4;
			}

			if (e->KeyData == Keys::T)
			{
				Jugador2 = 1;
			}
			else if (e->KeyData == Keys::G)
			{
				Jugador2 = 2;
			}
			else if (e->KeyData == Keys::H)
			{
				Jugador2 = 3;
			}
			else if (e->KeyData == Keys::F)
			{
				Jugador2 = 4;
			}

			if (e->KeyData == Keys::W)
			{
				Jugador3 = 1;
			}
			else if (e->KeyData == Keys::S)
			{
				Jugador3 = 2;
			}
			else if (e->KeyData == Keys::D)
			{
				Jugador3 = 3;
			}
			else if (e->KeyData == Keys::A)
			{
				Jugador3 = 4;
			}

			if (e->KeyData == Keys::Y)
			{
				//FuegoMorado = true;
				tiempoFuegoMorado = 30;
				Cola->add(e->KeyData);
			}
			if (e->KeyData == Keys::Q)
			{
				//FuegoNormal = true;
				tiempoFuegoNormal = 30;
				Cola->add(e->KeyData);
			}
			if (e->KeyData == Keys::C)
			{
				//Martillo = true;
				tiempoMartillo = 30;
				Cola->add(e->KeyData);
			}
			if (e->KeyData == Keys::R)
			{
				Portal = true;
			}
			//if (e->KeyData == Keys::Up)
			//objJuego->Mover_Principal(e->KeyData);
		}
	}
private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	if (inicio == false)
	{
		objJuego->GenerarDatosIniciales();
		intro = false;
		menu = true;

		/*
		for (int i = 0; i < 1000000; i++)
		{
			string filename;
			stringstream str;

			ambiente[i] = rand() % 4;
			str << i;
			filename = "ambiente";
			filename += str.str();
			filename += ".txt";
			ofstream out(filename.c_str());
		}
		for (int i = 0; i < 1000000; i++)
		{
			string filename;
			stringstream str;

			cantidadenemigos[i] = rand() % 15 + 25;
			str << i;
			filename = "cantidadenemigos";
			filename += str.str();
			filename += ".txt";
			ofstream out(filename.c_str());
			
		}
		for (int i = 0; i < 1000000; i++)
		{
			string filename;
			stringstream str;

			cantidadmonedas[i] = rand() % 15 + 25;
			str << i;
			filename = "cantidadmonedas";
			filename += str.str();
			filename += ".txt";
			ofstream out(filename.c_str());
		}
		for (int i = 0; i < 1000000; i++)
		{
			string filename;
			stringstream str;

			cantidadtrampas[i] = rand() % 3 + 5;
			str << i;
			filename = "cantidadtrampas";
			filename += str.str();
			filename += ".txt";
			ofstream out(filename.c_str());
		}
		*/

	}
	else
	{
		if (e->KeyData == Keys::Up)
		{
			Estatico1 = 1;
		}
		else if (e->KeyData == Keys::Down)
		{
			Estatico1 = 2;
		}
		else if (e->KeyData == Keys::Right)
		{
			Estatico1 = 3;
		}
		else if (e->KeyData == Keys::Left)
		{
			Estatico1 = 4;
		}
		if (Estatico1 == Jugador1)
		{
			objJuego->Estatico_Principal(e->KeyData);
			Jugador1 = 0;
		}

		if (e->KeyData == Keys::T)
		{
			Estatico2 = 1;
		}
		else if (e->KeyData == Keys::G)
		{
			Estatico2 = 2;
		}
		else if (e->KeyData == Keys::H)
		{
			Estatico2 = 3;
		}
		else if (e->KeyData == Keys::F)
		{
			Estatico2 = 4;
		}
		if (Estatico2 == Jugador2)
		{
			objJuego->Estatico_Principal(e->KeyData);
			Jugador2 = 0;
		}

		if (e->KeyData == Keys::W)
		{
			Estatico3 = 1;
		}
		else if (e->KeyData == Keys::S)
		{
			Estatico3 = 2;
		}
		else if (e->KeyData == Keys::D)
		{
			Estatico3 = 3;
		}
		else if (e->KeyData == Keys::A)
		{
			Estatico3 = 4;
		}
		if (Estatico3 == Jugador3)
		{
			objJuego->Estatico_Principal(e->KeyData);
			Jugador3 = 0;
		}
	}
}
private: System::Void MyForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
}
private: System::Void btn_ir_Click(System::Object^  sender, System::EventArgs^  e) {
	inicio = true;
	
	menu = false;
	this->pictureBox1->Visible = false;
	this->label1->Visible = false;
	this->label2->Visible = false;
	this->label3->Visible = false;
	this->label4->Visible = false;
	this->label5->Visible = false;
	lbl_Ambiente->Visible = false;
	lbl_canEnemigos->Visible = false;
	lbl_Monedas->Visible = false;
	lbl_Trampas->Visible = false;
	this->btn_comprobar->Enabled = false;
	this->btn_comprobar->Visible = false;
	this->btn_ir->Enabled = false;
	this->btn_ir->Visible = false;
	this->num_mapa->Enabled = false;
	this->num_mapa->Visible = false;
}
private: System::Void btn_comprobar_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ num_Mapa = gcnew String(beacon.ToString());
	num_Mapa = num_mapa->Text;
	/*
	int* ambiente = new int[1000000];
	int* cantidadenemigos = new int[1000000];
	int* cantidadmonedas = new int[1000000];
	int* cantidadtrampas = new int[1000000];
	*/
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void num_mapa_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bt_Jugar2_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void btn_Buscar_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((chBoxEnemigos->Checked&&chMonedas->Checked)||(chBoxEnemigos->Checked&&chAmbiente->Checked)||(chBoxEnemigos->Checked&&chTrampas->Checked)||(chMonedas->Checked&&chTrampas->Checked)||(chMonedas->Checked&&chAmbiente->Checked)||(chTrampas->Checked&& chAmbiente->Checked)
		||(chBoxEnemigos->Checked&&chMonedas->Checked&&chTrampas->Checked)||(chBoxEnemigos->Checked&&chMonedas->Checked&&chTrampas->Checked&&chAmbiente->Checked)||(chMonedas->Checked&&chTrampas->Checked&&chAmbiente->Checked)||(chAmbiente->Checked&&chMonedas->Checked&&chBoxEnemigos->Checked)
		)
	{
		MessageBox::Show("Solo debe seleccionar una opcion");

	}
	else {
		if (chBoxEnemigos->Checked)
		{
			int n;
			
			n = Convert::ToInt32(txtbxCantidad->Text);
			CNivel* niv=objJuego->buscarxEnemigos(n);
			objJuego->Set_Nivel(niv);
		}
		else {
			if (chMonedas->Checked)
			{
				int n;

				n = Convert::ToInt32(txtbxCantidad->Text);
				CNivel* niv = objJuego->buscarxMonedas(n);
				objJuego->Set_Nivel(niv);
			}
		}
		if (chTrampas->Checked) {
			int n;

			n = Convert::ToInt32(txtbxCantidad->Text);
			CNivel* niv = objJuego->buscarxTrampas(n);
			objJuego->Set_Nivel(niv);
		}
		if (chAmbiente->Checked) {
			int n;

			n = Convert::ToInt32(txtbxCantidad->Text);
			CNivel* niv = objJuego->buscarxAmbiente(n);
			objJuego->Set_Nivel(niv);

		}
	}

}
};
}
