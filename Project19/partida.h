#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

using namespace System::Drawing;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

/*//del 0 al 4
enum colorCarta { rojo, amarillo, verde, azul, colorida };
//del 0 al 1
enum TipoCarta { Normal, Especial };
//Representado desde el 0 al 14
enum IDCarta { Cero, Uno, Dos, Tres, Cuatro, Cinco, Seis, Siete, Ocho, Nueve, Nulo, Reserva, Roba2, Comodin, Roba4 };
#define tamanoCartaX 14
#define tamanoCartaY 8
*/

ref class CPartida {
public:
	vector<CJugador*>* jugadores;
	Rectangle areaJugadores;
	Rectangle areaDibujo;
	Bitmap^ cartas;
	Bitmap^ atrasCarta;
	CMaso* maso;
	CPozo* pozo;
	short cantJugadores;
	bool compruebaJugada;
	short sentidoDelJuego;//-1 izquierda , 1 derecha
	short cantCartasRepar;
	bool muestraBtnColor;
public: bool repartirCartasEmpezar;//7
public: short turnoActual;
		CPartida(Rectangle _areaDibujo, short cantJugadores) {
			this->cantJugadores = cantJugadores;
			this->areaDibujo = _areaDibujo;
			this->sentidoDelJuego = 1;
			this->muestraBtnColor = false;
			this->pozo = new CPozo(Rectangle(655, 100, 190, 280));

			this->maso = new CMaso(Rectangle(1200, 120, 130, 200));
			this->barajearBaraja(maso->getBaraja());

			//inicializo los jugadores
			jugadores = new vector<CJugador*>;
			for (int i = 0; i < cantJugadores; i++) {
				CJugador* aux = new CJugador(i);
				jugadores->push_back(aux);
			}

			this->turnoActual = 0;

			this->areaJugadores = Rectangle(700, 580, 110, 185);
			this->atrasCarta = gcnew Bitmap("TraseraUNO2.jpg");
			this->cartas = gcnew Bitmap("UNOBa.png");
		}
		~CPartida() {
		}
		void imprimir() {
		}
		void dibujar(BufferedGraphics^ bufer, PictureBox^ box1, PictureBox^ box2, PictureBox^ box3) {
			if (this->jugadores->at(turnoActual)->getCantCartas() == 0) {
				//bufer->Graphics->DrawImage(this->atrasCarta, this->areaJugadores);
				box1->Image = atrasCarta;
			}
			else if (this->jugadores->at(turnoActual)->getCantCartas() > 0) {
				this->jugadores->at(turnoActual)->mostrarCarta(cartas, box1);
			}
			if (jugadores->at(turnoActual)->movimiento) {
				actualizarTurnoActual();
			}
			//dibujo maso(todas cartas)
			box2->Image = atrasCarta;
			//dibujo pozo(botar cartas)
			if (this->pozo->getBaraja()->size() > 0) {
				this->pozo->mostrarCarta(cartas, box3);
			}
			else if (this->pozo->getBaraja()->size() == 0) {
				box3->Image = atrasCarta;
			}
		}
		void actualizarTurnoActual() {
			turnoActual += sentidoDelJuego;
			if (turnoActual < 0) {
				turnoActual = cantJugadores - 1;
			}
			if (turnoActual == cantJugadores) {
				turnoActual = 0;
			}
			for (int j = 0; j < cantJugadores; j++) {
				this->jugadores->at(j)->movimiento = false;
			}
		}
		void repartirCartasJugar(short n) {
			bool veri = false;
			for (int j = 0; j < cantJugadores; j++) {
				for (int c = 0; c < n; c++) {
					CCarta* aux = maso->obtenerCartaDeEnCima();

					if (veri == false && aux->getID() >= 0 && aux->getID() <= 9) {
						this->pozo->recibeCarta(aux, this->maso, this->jugadores, this->sentidoDelJuego, this->turnoActual, this->cantJugadores, this->muestraBtnColor);
						CCarta* aux2 = maso->obtenerCartaDeEnCima();
						this->jugadores->at(j)->recibeCarta(aux2);
						veri = true;
					}
					else {
						this->jugadores->at(j)->recibeCarta(aux);
					}
				}
			}
			this->repartirCartasEmpezar = true;
		}
		short cantCartasJugadorActual() {
			return this->jugadores->at(turnoActual)->getCantCartas();
		}
		void jugadorCartasRight() {
			this->jugadores->at(turnoActual)->setCartaEncima(1);
		}
		void jugadorCartasLeft() {
			this->jugadores->at(turnoActual)->setCartaEncima(-1);
		}
		void jugadorBotarCarta() {
			bool veri = false;
			CCarta* aux = this->jugadores->at(turnoActual)->botarCarta();
			veri = this->pozo->recibeCarta(aux, this->maso, this->jugadores, this->sentidoDelJuego, this->turnoActual, this->cantJugadores, this->muestraBtnColor);
			if (veri) {
				this->jugadores->at(turnoActual)->confirBotaCarta();
			}
			else {
				//mensaje de que no puede hacer eso
			}
		}
		void sacarCartaMaso() {
			if (jugadores->at(turnoActual)->chaparCartas == 0) {
				CCarta* aux = this->maso->obtenerCartaDeEnCima();
				short n = jugadores->at(turnoActual)->getCantCartas();
				jugadores->at(turnoActual)->recibeCarta(aux);
				jugadores->at(turnoActual)->setCartaEncima(-n);
				jugadores->at(turnoActual)->chaparCartas = 1;
			}
		}
		bool puedePasar() {
			if (this->jugadores->at(turnoActual)->chaparCartas == 1) {
				return true;
			}
			return false;
		}
		void siguienteTurno() {
			this->jugadores->at(turnoActual)->movimiento = true;
			this->jugadores->at(turnoActual)->chaparCartas = 0;
		}
		int getPuntaje() {
			return this->jugadores->at(turnoActual)->getPuntaje();
		}
		void cambioColor(int n) {
			this->pozo->setColor(n);
			this->muestraBtnColor = false;
		}
		bool activaBotonesColor() {
			if (this->muestraBtnColor) {
				return true;
			}
			else {
				return false;
			}
			
		}
private:
	void barajearBaraja(vector<CCarta*>* baraja) {
		srand(unsigned(time(0)));
		random_shuffle(baraja->begin(), baraja->end());
	}
};
