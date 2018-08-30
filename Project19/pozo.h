#pragma once
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
#define tamanoCartaY 8*/

//pozo central en el cual se botan las cartas y empieza con una carta
class CPozo {
	int color;
public:int idCarta;
	vector<CCarta*>* baraja;
	CImagen* img;
public:
	CPozo(Rectangle areaDibujo) {
		this->img = new CImagen(areaDibujo);
		this->baraja = new vector<CCarta*>;
	}
	~CPozo() {
		delete this->baraja;
		for (int i = 0; i < baraja->size(); i++) {
			delete this->baraja->at(i);
		}
	}
	void mostrarCarta(Bitmap^ img, PictureBox^ box3) {
		Bitmap^ a = gcnew Bitmap(190, 280);
		Graphics^ gra = Graphics::FromImage(a);
		Rectangle zoom = Rectangle((this->getCartaEncima()->getArea().Location.X)*0.001, (this->getCartaEncima()->getArea().Location.Y)*0.001, 190, 280);
		gra->DrawImage(img, zoom, this->getCartaEncima()->getArea(), GraphicsUnit::Pixel);
		box3->Image = a;
	}
	Rectangle getArea() {
		return this->img->getArea();
	}
	int getColor() {
		return this->color;
	}
	void setColor(short _color) { this->color = _color; }
	CCarta* getCartaEncima( ) {
		//return this->baraja->back();
		for (int i = 0; i < this->baraja->size(); i++) {
			if (this->baraja->at(i)->getTipo() == Especial)
				return this->baraja->at(i);
		}
	}
	bool recibeCarta(CCarta* carta, CMaso* maso, vector<CJugador*>* jugadores, short sentidoDelJuego, short turnoActual, short cantJugadores, bool muestraBtnColor) {
		if (this->baraja->size() == 0) {
			this->baraja->push_back(carta);
			this->color = carta->getColor();
			this->idCarta = carta->getID();
			return true;
		}
		//logica de aceptacion
		int auxColor = carta->getColor();
		int auxId = carta->getID();
		if ((auxColor == this->color || auxId == this->idCarta) && auxId<10) {
			this->baraja->push_back(carta);
			this->idCarta = auxId;
			this->color = auxColor;
			return true;
		}
		else if (auxColor==this->color && (auxId == 10 || auxId==11 || auxId==12)) {
			switch (auxId)
			{
			case 10:
				this->pierdeTurno(turnoActual, sentidoDelJuego, cantJugadores);
				this->baraja->push_back(carta);
				this->color = carta->getColor();
				this->idCarta = carta->getID();
				break;
			case 11:
				this->cambiaSentido(sentidoDelJuego, jugadores, turnoActual);
				this->baraja->push_back(carta);
				this->color = carta->getColor();
				this->idCarta = carta->getID();
				break;
			case 12:
				this->roba2(maso, jugadores, sentidoDelJuego, turnoActual, cantJugadores);
				this->baraja->push_back(carta);
				this->color = carta->getColor();
				this->idCarta = carta->getID();
				break;
			}
			return true;
		}
		else if (auxId==13 || auxId == 14) {
			switch (auxId)
			{
			case 13:
				this->cambiarColor(muestraBtnColor);
				this->baraja->push_back(carta);
				break;
			case 14:
				this->roba4(maso, jugadores, sentidoDelJuego, turnoActual, cantJugadores);
				this->baraja->push_back(carta);
				break;
			}
			return true;
		}
		else {
			return false;
		}
	}
	vector<CCarta*>* getBaraja() {
		return this->baraja;
	}

	void roba2(CMaso* maso, vector<CJugador*>* jugadores, short &sentidoDelJuego, short &turnoActual, short &cantJugadores) {
		short recibeCastigo = turnoActual + sentidoDelJuego;
		if (recibeCastigo < 0) {
			recibeCastigo = cantJugadores - 1;
		}
		if (recibeCastigo == cantJugadores) {
			recibeCastigo = 0;
		}
		for (int i = 0; i < 2; i++) {
			CCarta* aux = maso->obtenerCartaDeEnCima();
			jugadores->at(recibeCastigo)->recibeCarta(aux);
		}
		jugadores->at(turnoActual)->movimiento = true;
	}
	void cambiaSentido(short &sentidoDelJuego, vector<CJugador*>* jugadores, short &turnoActual) {
		sentidoDelJuego*-1;
		jugadores->at(turnoActual)->movimiento = true;
	}
	void pierdeTurno(short &turnoActual, short &sentidoDelJuego, short &cantJugadores) {
		if (sentidoDelJuego > 0) {
			turnoActual += (sentidoDelJuego * 2);
			if (turnoActual == cantJugadores) {
				turnoActual = 0;
			}
			else if (turnoActual + 1 > cantJugadores) {
				short exe = (turnoActual % cantJugadores);
				turnoActual = exe;
			}
		}
		else if (sentidoDelJuego < 0) {

		}
		turnoActual += (sentidoDelJuego * 2);
	}
	void roba4(CMaso* maso, vector<CJugador*>* jugadores, short &sentidoDelJuego, short &turnoActual, short cantJugadores) {
		short recibeCastigo = turnoActual + sentidoDelJuego;
		if (recibeCastigo < 0) {
			recibeCastigo = cantJugadores - 1;
		}
		if (recibeCastigo == cantJugadores) {
			recibeCastigo = 0;
		}
		for (int i = 0; i < 4; i++) {
			CCarta* aux = maso->obtenerCartaDeEnCima();
			jugadores->at(recibeCastigo)->recibeCarta(aux);
		}
	}
	void cambiarColor(bool &muestraBtnColor) {
		muestraBtnColor = true;
	}
	
};