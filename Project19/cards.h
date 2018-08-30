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

//del 0 al 4
enum colorCarta { rojo,  amarillo, verde, azul, colorida };
//del 0 al 1
enum TipoCarta { Normal, Especial };
//Representado desde el 0 al 14
enum IDCarta { Cero, Uno, Dos, Tres, Cuatro, Cinco, Seis, Siete, Ocho, Nueve, Nulo, Reserva, Roba2, Comodin, Roba4 };
#define tamanoCartaX 14
#define tamanoCartaY 8

class CImagen {
protected:
	Rectangle areaDibujo;
public:
	CImagen(Rectangle _areaDibujo) { 
		this->areaDibujo = _areaDibujo;
	}
	void hacerTransparente(Bitmap^ _imagen) {
		Color color = _imagen->GetPixel(0,0);
		_imagen->MakeTransparent(color);
	}
	Rectangle getArea() {
		return this->areaDibujo; 
	}
	Point getPosicion() { 
		return this->areaDibujo.Location; 
	}
	void  setPosicion(Point posi) {
		this->areaDibujo.Location = posi; 
	}
	virtual void dibujar(BufferedGraphics^ bufer, Bitmap^ img) {
		bufer->Graphics->DrawImage(img, this->areaDibujo);
	}
};
class CSprite : public CImagen {
	short indice;
	short nroSubimagenes;
public:
	CSprite(Rectangle _areaDibujo) :
		CImagen(_areaDibujo) {
	}
	CSprite(Rectangle _areaDibujo, short nroSI) :
		CImagen(_areaDibujo) {
		this->nroSubimagenes = nroSI;
		this->indice = 0;
	}
	void dibujar(BufferedGraphics^ _buffer, Bitmap^ _imagen) override {
		Rectangle recorte = obtenerRecorte(_imagen);
		_buffer->Graphics->DrawImage(_imagen, this->areaDibujo, recorte, GraphicsUnit::Pixel);
		short ultimoIndice = this->nroSubimagenes - 1;
		this->indice = (this->indice == ultimoIndice) ? 0 : this->indice + 1;
	}
private:
	Rectangle obtenerRecorte(Bitmap^ _imagen) {
		short Ancho = _imagen->Width /14 ;
		short Alto = _imagen->Height / 8;
		short x = this->indice*Ancho;
		short y = 0;
		return Rectangle(x, y, Ancho, Alto);
	}
};


class CCarta {
protected:
	CImagen* img;
	int tipo;
	int id;
	int color;
	int x;
	int y;
	int puntaje;
public:
	CCarta(int _valor, int _color, int x, int y) {
		this->x = x*50;
		this->y = y*75;
		this->tipo = 0;
		this->id = _valor;
		this->color = _color;
		switch (_valor)
		{
		case 0: this->puntaje = 0; break;
		case 1: this->puntaje = 1; break;
		case 2: this->puntaje = 2; break;
		case 3: this->puntaje = 3; break;
		case 4: this->puntaje = 4; break;
		case 5: this->puntaje = 5; break;
		case 6: this->puntaje = 6; break;
		case 7: this->puntaje = 7; break;
		case 8: this->puntaje = 8; break;
		case 9: this->puntaje = 9; break;
		case 10: this->puntaje = 20; break;
		case 11: this->puntaje = 20; break;
		case 12: this->puntaje = 20; break;
		case 13: this->puntaje = 50; break;
		case 14: this->puntaje = 50; break;
		}
		this->img = new CImagen(Rectangle(this->x, this->y, 50, 75));
	}
	~CCarta() {
		delete this->img;
	}
public:
	int getColor() { 
		return this->color;
	}
	int getID() { 
		return this->id;
	}
	int getPuntaje() { 
		return this->puntaje; 
	}
	void dibujarCarta(Bitmap^_imagen, BufferedGraphics^_buffer) {
		_buffer->Graphics->DrawImage(_imagen, this->img->getArea(), Rectangle(x, y, 50, 75), GraphicsUnit::Pixel);
	}
	Rectangle getArea() {
		return this->img->getArea();
	}
	virtual short getTipo() { 
		return 0; 
	}
};

class CartasEspeciales :public CCarta {
	//falta mejorar
	bool activa;
public:
	CartasEspeciales(IDCarta _valor, colorCarta _color, short _puntaje) 
		:CCarta(_valor, _color, _valor, _color) {
		this->tipo = 1;
	}
	short getTipo() override { return 1; }
	void roba_Dos() {}
	void cambio_Sentido() {}
	void pierde_turno() {}
	void comodin_cambiaColor() {}
	void comodin_robaCuatro() {}
};