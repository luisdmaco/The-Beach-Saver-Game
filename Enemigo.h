#pragma once
#include "Entidad.h"

class Enemigo : public Entidad {

public:
	Enemigo(int x, int y) {
		this->x = x;
		this->y = y;
		dx = 5;
		dy = 5;
		idx = 0;
		idy = 0;
	}
	~Enemigo(){}
	void Draw(Graphics^ g, Bitmap^ bmp) {
		ancho = bmp->Width / 4;
		alto = bmp->Height / 4;
		Rectangle seccionmostrar = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, seccionmostrar, GraphicsUnit::Pixel);
	}
	void move(Graphics^ g) {
		if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) { 
			dx = dx * -1; 
			if (dx == -1) {
				idy = 1; //si se mueve hacia la otra dirección se usa la otra fila del sprite
			}
		}
		if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) dy = dy * -1;
		x += dx;
	}


};