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

//maso general que empieza con todas las cartas
class CMaso {
	short cantCartas;
	vector <CCarta*>* baraja;
	CImagen* img;
public:
	CMaso(Rectangle areaDibujo) {
		this->img = new CImagen(areaDibujo);
		this->cantCartas = 112;
		this->baraja = new vector<CCarta*>;
		for (int color = 0; color < 4; color++) {
			for (int num = 0; num < 13; num++) {
				CCarta* aux1 = new CCarta(num, color, num, color);
				baraja->push_back(aux1);
				CCarta* aux2 = new CCarta(num, color, num, color);
				baraja->push_back(aux2);
			}
		}
		int color = 5;
		for (int num = 13; num < 15; num++) {
			for (short i = 0; i < 4; i++) {
				CCarta* aux = new CCarta(num, color, 13, (num == 13) ? 0 : 5);
				baraja->push_back(aux);
			}
		}
	}
	~CMaso() {
		delete this->baraja;
		for (int i = 0; i < cantCartas; i++) {
			delete this->baraja->at(i);
		}
	};
	void repartirCartas() {
	}
	//no todas retornan un valor
	CCarta* obtenerCartaDeEnCima() {
		if (this->baraja->size() > 0) {
			CCarta* aux = baraja->at(0);
			baraja->erase(this->baraja->begin());
			this->cantCartas -= 1;
			return aux;
		}
	}
	Rectangle getArea() {
		return this->img->getArea();
	}
	vector<CCarta*>* getBaraja() {
		return this->baraja;
	}
};