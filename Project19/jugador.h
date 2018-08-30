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

class CJugador {
	vector<CCarta*>* barajaMano;
	int puntaje;
	int cantCarta;
	int turno;
	int cartaEncima;
public: int chaparCartas;
public: bool movimiento;
public:
	CJugador(short _turno) {
		this->cantCarta = 0;
		this->turno = _turno;
		this->puntaje = 0;
		this->barajaMano = new vector<CCarta*>;
		this->cartaEncima = 0;
		this->movimiento = false;
		this->chaparCartas = 0;
	};
	~CJugador() {
		delete this->barajaMano;
		for (int i = 0; i < barajaMano->size(); i++) {
			delete this->barajaMano->at(i);
		}
	}
	vector<CCarta*>* getBarajaMano() {
		return this->barajaMano;
	}
	void recibeCarta(CCarta* carta) {
		barajaMano->push_back(carta);
		this->cantCarta += 1;
	}
	void actualizarCantCartas() {//debo actializar por ahi
		this->cantCarta = (int)barajaMano->size();
	}
	short getPuntaje() {
		this->sumadorPuntos();
		return this->puntaje;
	};
	short getCantCartas() {
		return this->cantCarta;
	}
	void mostrarCarta(Bitmap^ img, PictureBox^ box1) {
		Bitmap^ a = gcnew Bitmap(110, 185);
		Graphics^ gra = Graphics::FromImage(a);
		Rectangle zoom = Rectangle((this->getCartaEncima()->getArea().Location.X)*0.001, (this->getCartaEncima()->getArea().Location.Y)*0.001, 110, 185);
		gra->DrawImage(img, zoom, this->getCartaEncima()->getArea(), GraphicsUnit::Pixel);
		box1->Image = a;
	}
	void setCartaEncima(short n) {
		this->cartaEncima += n;
		if (this->cartaEncima == cantCarta) {
			this->cartaEncima = 0;
		}
		if (this->cartaEncima < 0) {
			this->cartaEncima = cantCarta - 1;
		}
	}
	CCarta* getCartaEncima() {
		return this->barajaMano->at(cartaEncima);
	}
	CCarta* botarCarta() {
		return this->barajaMano->at(cartaEncima);
	}
	void confirBotaCarta() {
		this->barajaMano->erase(this->barajaMano->begin() + cartaEncima);
		this->actualizarCantCartas();
		this->cartaEncima = 0;
		this->chaparCartas = 0;
		this->movimiento = true;
	}
private:
	void sumadorPuntos() {
		this->puntaje = 0;
		for (short i = 0; i < this->barajaMano->size(); i++) {
			this->puntaje += this->barajaMano->at(i)->getPuntaje();
		}
	}
};
