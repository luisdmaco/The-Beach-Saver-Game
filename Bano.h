#pragma once
#include "Entidad.h"

class Bano : public Entidad {
public:
	Bano(Bitmap^ img, int x, int y) {
		width = img->Width;
		height = img->Height;
		this->x = x;
		this->y = y;
		dx = dy = 0;
		IDx = 0; 
	}
	~Bano(){}
	Rectangle AreaBano() { return Rectangle(x - 50, y - 50, width + 100, height + 100); }
	                                     //inicio del area - hasta el final del baño + el area restante
	void draw(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * width, 0 * height, 64, 64);
		g->DrawImage(img, AreaRectangle(), corte, GraphicsUnit::Pixel);
	}

	//para obtener y / x, las funciones están en entidad (herencia)
};