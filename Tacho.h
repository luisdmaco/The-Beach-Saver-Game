#pragma once
#include "Entidad.h"

class Tacho : public Entidad {
public:
	Tacho(Bitmap^ img, int x, int y) {
		width = img->Width;
		height = img->Height;
		this->x = x;
		this->y = y;
		dx = dy = 0;
		IDx = 0;
	}
	~Tacho() {}
	Rectangle AreaTacho() { return Rectangle(x, y , width , height ); }
	Rectangle AreaRecoleccionTacho() { return Rectangle(x - 20, y - 20, width + 30, height +30); }
	//inicio del area - hasta el final del baño + el area restante
	void draw(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * width, 0 * height, width, height);
		g->DrawImage(img, AreaRectangle(), corte, GraphicsUnit::Pixel);
	}
	//para obtener y / x, las funciones están en entidad (herencia)
};