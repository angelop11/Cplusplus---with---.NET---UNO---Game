#pragma once
#include "cards.h"
#include "maso.h"
#include "jugador.h"
#include "pozo.h"
#include "partida.h"
namespace Project19 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		BufferedGraphicsContext^ espacioBuffer;
		Graphics^ graficador;
		BufferedGraphics^ buffer;
		CPartida^ partida;
		Bitmap^ fondo;
	private: System::Windows::Forms::Button^  button1;
			 System::Windows::Forms::Button^  button2;//izquierda
			 System::Windows::Forms::Button^  button3;//derecha
			 System::Windows::Forms::Button^  button4;//pasar
			 System::Windows::Forms::Button^  button5;//instrucciones
			 System::Windows::Forms::Button^  button6;//salir
			 System::Windows::Forms::Button^  button7;//rojo
			 System::Windows::Forms::Button^  button8;//azul
			 System::Windows::Forms::Button^  button9;//verde
			 System::Windows::Forms::Button^  button10;//amarillo
	private: System::Windows::Forms::Timer^  timer1;
			 System::Windows::Forms::RadioButton^  rad1;
			 System::Windows::Forms::RadioButton^  rad2;
			 System::Windows::Forms::RadioButton^  rad3;
			 System::Windows::Forms::RadioButton^  rad4;
			 System::Windows::Forms::RadioButton^  rad5;
			 System::Windows::Forms::Label^ label1;
			 System::Windows::Forms::Label^ label2;
			 System::Windows::Forms::Label^ label3;
			 System::Windows::Forms::PictureBox^ box1;
			 System::Windows::Forms::PictureBox^ box2;
			 System::Windows::Forms::PictureBox^ box3;
			 short cantJugadores;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->espacioBuffer = BufferedGraphicsManager::Current;
			this->graficador = this->CreateGraphics();
			this->buffer = espacioBuffer->Allocate(this->graficador, this->ClientRectangle);
			this->fondo = gcnew Bitmap("fondoini.jpg");
			this->cantJugadores = 0;
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
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::animar);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(300, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"JUGAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::jugar);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->Location = System::Drawing::Point(300, 500);
			this->button5->Name = L"button1";
			this->button5->Size = System::Drawing::Size(270, 70);
			this->button5->TabIndex = 0;
			this->button5->Text = L"INSTRUCCIONES";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::instrucciones);
			this->Controls->Add(button5);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Red;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button6->Location = System::Drawing::Point(300, 700);
			this->button6->Name = L"button1";
			this->button6->Size = System::Drawing::Size(250, 70);
			this->button6->TabIndex = 0;
			this->button6->Text = L"SALIR";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::salir);
			this->Controls->Add(button6);
			// 
			// MyForm
			// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Red;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::White;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			//this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void animar(System::Object^  sender, System::EventArgs^  e) {
		this->buffer->Graphics->DrawImage(this->fondo, this->ClientRectangle);
		if (this->partida) {
			this->buffer->Graphics->DrawImage(gcnew Bitmap("fondo2.jpg"), Rectangle(600, 505, 300, 300));
			if (partida->repartirCartasEmpezar == false) {
				partida->repartirCartasJugar(7);
			}
			if (partida->puedePasar()) {
				this->Controls->Add(button4);
			}
			else{
				this->Controls->Remove(button4);
			}
			if (partida->activaBotonesColor()) {
				this->Controls->Add(button7);
				this->Controls->Add(button8);
				this->Controls->Add(button9);
				this->Controls->Add(button10);
			}
			else if (partida->activaBotonesColor()==false) {
				this->Controls->Remove(button7);
				this->Controls->Remove(button8);
				this->Controls->Remove(button9);
				this->Controls->Remove(button10);
			}

			label1->Text = "Turno del jugador N°: "+(partida->turnoActual+1);
			partida->dibujar(this->buffer, this->box1, this->box2, this->box3);
			label2->Text = "Tienes " + partida->cantCartasJugadorActual() + " cartas";
			label3->Text = "Tienes un total de "+ partida->getPuntaje() +" puntos en tu baraja";
		}
		this->buffer->Render(this->graficador);
	}
	private: System::Void jugar(System::Object^  sender, System::EventArgs^  e) {
		if (button1->Text == "JUGAR") {
			this->Controls->Remove(button5);
			this->Controls->Remove(button6);
			// 
			// button2 left
			// 
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(830, 650);
			this->button2->Name = L"button1";
			this->button2->Size = System::Drawing::Size(60, 40);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Left";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::left);
			// 
			// button3 right
			// 
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(620, 650);
			this->button3->Name = L"button1";
			this->button3->Size = System::Drawing::Size(60, 40);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Right";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::right);
			// 
			// button4 pasar
			// 
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button4->BackColor = System::Drawing::Color::Red;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(900, 550);
			this->button4->Name = L"button1";
			this->button4->Size = System::Drawing::Size(60, 40);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Pasar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::pasar);
			// 
			// button7 rojo
			// 
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button7->BackColor = System::Drawing::Color::Red;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button7->Location = System::Drawing::Point(660, 400);
			this->button7->Name = L"button1";
			this->button7->Size = System::Drawing::Size(90, 40);
			this->button7->TabIndex = 0;
			this->button7->Text = L"Rojo";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::rojo);
			// 
			// button8 azul
			// 
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button8->BackColor = System::Drawing::Color::Red;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button8->Location = System::Drawing::Point(760, 400);
			this->button8->Name = L"button1";
			this->button8->Size = System::Drawing::Size(90, 40);
			this->button8->TabIndex = 0;
			this->button8->Text = L"Azul";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::azul);
			// 
			// button9 verde
			// 
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button9->BackColor = System::Drawing::Color::Red;
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button9->Location = System::Drawing::Point(660, 450);
			this->button9->Name = L"button1";
			this->button9->Size = System::Drawing::Size(90, 40);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Verde";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::verde);
			// 
			// button10 amarillo
			// 
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button10->BackColor = System::Drawing::Color::Red;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button10->Location = System::Drawing::Point(760, 450);
			this->button10->Name = L"button1";
			this->button10->Size = System::Drawing::Size(90, 40);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Amarillo";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::amarillo);
			// 
			// pictureBox1 jug
			// 
			this->box1 = gcnew System::Windows::Forms::PictureBox();
			this->box1->BackColor = System::Drawing::Color::Transparent;
			this->box1->Location = System::Drawing::Point(700, 580);
			this->box1->Name = L"pictureBox1";
			this->box1->Size = System::Drawing::Size(110, 185);
			this->box1->TabIndex = 1;
			this->box1->TabStop = false;
			this->box1->Tag = L"1";
			this->box1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->box1->Click += gcnew System::EventHandler(this, &MyForm::jugadorBotarCarta);
			// 
			// pictureBox2 mazo
			// 
			this->box2 = gcnew System::Windows::Forms::PictureBox();
			this->box2->BackColor = System::Drawing::Color::Transparent;
			this->box2->Location = System::Drawing::Point(1200, 120);
			this->box2->Name = L"pictureBox1";
			this->box2->Size = System::Drawing::Size(130, 200);
			this->box2->TabIndex = 1;
			this->box2->TabStop = false;
			this->box2->Tag = L"1";
			this->box2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->box2->Click += gcnew System::EventHandler(this, &MyForm::sacarCartaMaso);
			// 
			// pictureBox3 pozo
			// 
			this->box3 = gcnew System::Windows::Forms::PictureBox();
			this->box3->BackColor = System::Drawing::Color::Transparent;
			this->box3->Location = System::Drawing::Point(655, 100);
			this->box3->Name = L"pictureBox1";
			this->box3->Size = System::Drawing::Size(190, 280);
			this->box3->TabIndex = 1;
			this->box3->TabStop = false;
			this->box3->Tag = L"1";
			//label1
			label1 = gcnew System::Windows::Forms::Label();
			label1->Size = System::Drawing::Size(500, 40);
			label1->Text = "Selecciona la cantidad de jugadores: ";
			label1->Location = System::Drawing::Point((this->Width / 2) - 250, 50);
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			label1->BackColor = System::Drawing::Color::Transparent;
			label1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Controls->Add(label1);
			//label2
			label2 = gcnew System::Windows::Forms::Label();
			label2->Size = System::Drawing::Size(250, 40);
			label2->Location = System::Drawing::Point(626, 505);
			label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			label2->BackColor = System::Drawing::Color::Transparent;
			label2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//label3
			label3 = gcnew System::Windows::Forms::Label();
			label3->Size = System::Drawing::Size(400, 35);
			label3->Location = System::Drawing::Point(20, 80);
			label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			label3->BackColor = System::Drawing::Color::Transparent;
			label3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//rad1
			rad1 = gcnew System::Windows::Forms::RadioButton();
			rad1->Size = System::Drawing::Size(130, 25);
			rad1->Location = System::Drawing::Point(300, 250);
			rad1->Name = L"1jugador";
			rad1->Text = L"1 Jugador";
			rad1->BackColor = System::Drawing::Color::Transparent;
			rad1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			rad1->UseVisualStyleBackColor = true;
			//this->Controls->Add(rad1);
			//rad2
			rad2 = gcnew System::Windows::Forms::RadioButton();
			rad2->Size = System::Drawing::Size(150, 25);
			rad2->Location = System::Drawing::Point(400, 250);
			rad2->Name = L"2jugadores";
			rad2->Text = L"2 Jugadores";
			rad2->BackColor = System::Drawing::Color::Transparent;
			rad2->Checked = true;
			rad2->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			rad2->UseVisualStyleBackColor = true;
			this->Controls->Add(rad2);

			//rad3
			rad3 = gcnew System::Windows::Forms::RadioButton();
			rad3->Size = System::Drawing::Size(150, 25);
			rad3->Location = System::Drawing::Point(600, 250);
			rad3->Name = L"3jugadores";
			rad3->Text = L"3 Jugadores";
			rad3->BackColor = System::Drawing::Color::Transparent;
			rad3->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			rad3->UseVisualStyleBackColor = true;
			this->Controls->Add(rad3);

			//rad4
			rad4 = gcnew System::Windows::Forms::RadioButton();
			rad4->Size = System::Drawing::Size(150, 25);
			rad4->Location = System::Drawing::Point(800, 250);
			rad4->Name = L"4jugadores";
			rad4->Text = L"4 Jugadores";
			rad4->BackColor = System::Drawing::Color::Transparent;
			rad4->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			rad4->UseVisualStyleBackColor = true;
			this->Controls->Add(rad4);
			//rad5
			rad5 = gcnew System::Windows::Forms::RadioButton();
			rad5->Size = System::Drawing::Size(150, 25);
			rad5->Location = System::Drawing::Point(1000, 250);
			rad5->Name = L"5jugadores";
			rad5->Text = L"5 Jugadores";
			rad5->BackColor = System::Drawing::Color::Transparent;
			rad5->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			rad5->UseVisualStyleBackColor = true;
			this->Controls->Add(rad5);
			//boton1
			button1->Size = System::Drawing::Size(190, 50);
			button1->Location = System::Drawing::Point((this->Width / 2) - 150, 500);
			button1->Text = "EMPEZAR";
			button1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
		else if (button1->Text=="EMPEZAR") {
			if (this->rad1->Checked) {
				cantJugadores = 1;
				MessageBox::Show("1");
			}
			else if (this->rad2->Checked) {
				cantJugadores = 2;
			}
			else if (this->rad3->Checked) {
				cantJugadores = 3;
			}
			else if (this->rad4->Checked) {
				cantJugadores = 4;
			}
			else if (this->rad5->Checked) {
				cantJugadores = 5;
			}
			
			this->Controls->Remove(rad1);
			this->Controls->Remove(rad2);
			this->Controls->Remove(rad3);
			this->Controls->Remove(rad4);
			this->Controls->Remove(rad5);
			this->Controls->Remove(button1);

			label1->Location = System::Drawing::Point(20, 10);
			label1->Text = "Empezando...";
			//empiezo una partida
			this->partida = gcnew CPartida(this->ClientRectangle, cantJugadores);
			this->Controls->Add(label2);
			this->Controls->Add(label3);
			this->Controls->Add(box1);
			this->Controls->Add(box2);
			this->Controls->Add(box3);
			this->Controls->Add(button2);
			this->Controls->Add(button3);
			//this->partida->imprimir();
			//this->partida->efectoBarajeo();
		}
	}
	private: System::Void right(System::Object^  sender, System::EventArgs^  e) {
		partida->jugadorCartasRight();
	}
	private: System::Void left(System::Object^  sender, System::EventArgs^  e) {
		partida->jugadorCartasLeft();
	}
	private: System::Void jugadorBotarCarta(System::Object^  sender, System::EventArgs^  e) {
		partida->jugadorBotarCarta ();
	}
	private: System::Void sacarCartaMaso(System::Object^  sender, System::EventArgs^  e) {
		partida->sacarCartaMaso();
	}
	private: System::Void pasar(System::Object^  sender, System::EventArgs^  e) {
		partida->siguienteTurno();
	}
	private: System::Void rojo(System::Object^  sender, System::EventArgs^  e) {
		partida->cambioColor(0);
	}
	private: System::Void azul(System::Object^  sender, System::EventArgs^  e) {
		partida->cambioColor(3);
	}
	private: System::Void verde(System::Object^  sender, System::EventArgs^  e) {
		partida->cambioColor(2);
	}
	private: System::Void amarillo(System::Object^  sender, System::EventArgs^  e) {
		partida->cambioColor(1);
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		short x = (this->Width / 2)-125;
		short y = (this->Height / 4)-35;
		button1->Location = System::Drawing::Point(x, y);
		button5->Location = System::Drawing::Point(x-10, 350);
		button6->Location = System::Drawing::Point(x, 550);
	}
	private: System::Void instrucciones(System::Object^  sender, System::EventArgs^  e) {
		this->Controls->Remove(button1);
		this->Controls->Remove(button5);
		this->Controls->Remove(button6);
		//label1
		label1 = gcnew System::Windows::Forms::Label();
		label1->Size = System::Drawing::Size(1530, 800);
		label1->Location = System::Drawing::Point(0, 0);
		label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		label1->BackColor = System::Drawing::Color::Transparent;
		label1->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label1->Text = "Instrucciones: \n" + "- Al comenzar la partida, cada jugador dispone de 7 cartas.\n" +
			"- Si en algún momento de la partida, un jugador no puede jugar ninguna de las cartas de su mano por no coincidir con la ultima carta de la pila, está obligado a robar una carta del montón, pudiéndola jugar inmediatamente.\n" +
			"- Un jugador en su turno podrá decidir no jugar una de las cartas de su mano, aunque esta coincida en número, color o símbolo con la última de la pila de descarte.En este caso, debe robar una carta del montón, pudiéndola jugar inmediatamente.\n" +
			"- Gana el jugador que se queda sin cartas.\n" +
			"- El jugador que más puntos en contra haga pierde.\n" +
			"\n"+
			"Cartas especiales :\n" +
			"-Roba 2 : esta carta hace que el próximo jugador este obligado a coger 2 cartas del mazo\n" +
			"- Roba 4 : esta carta hace que el próximo jugador este obligado a coger cartas del mazo 4\n" +
			"- Cambio de sentido : invierte el sentido de la partida.\n" +
			"- Pierde turno : anula la jugada del próximo jugador\n" +
			"- Comodín : permite al jugador que lo usa escoger el color de la partida\n" +
			"\n"+
			"Puntuación :\n" +
			"Cartas del 0 al 9 : Su valor número\n" +
			"Carta “Roba Dos” : 20 puntos\n" +
			"Carta “Cambio De Sentido” : 20 puntos\n" +
			"Carta “Pierde El Turno” : 20 puntos\n" +
			"Carta “Comodín” : 50 puntos\n" +
			"Carta “Comodín Roba Cuatro” : 50 puntos'\n";
		this->Controls->Add(label1);
	}
	private: System::Void salir(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}
};
}
