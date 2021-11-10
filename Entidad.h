#pragma once
#include "Dependencias.h"

public enum Direccion { right, left, nothing };

class Entidad
{
protected:
	int x, y;
	int idx, idy;
	int dx, dy;
	int ancho, alto;
	bool visible;
	Direccion orientation;
	int w, h;
	int width, height;
	int limF, limC;
	int fil, col;
	int fracY, fracX;
	int life;
public: // utilicen el que más les convenga 
	Entidad() {
		visible = false;
		dx = dy = 0;
		orientation = Direccion::nothing;
		width = height = 70;
	}
	Entidad(int px, int py, int pw, int ph) {
		x = px; y = py;
		w = pw; h = ph;
		visible = false;
		dx = dy = 0;
		orientation = Direccion::nothing;
		width = height = 70;
	}
	Entidad(int px, int py, int pw, int ph, int plimF, int plimC, int pfil, int pcol) {
		x = px; y = py;
		w = pw; h = ph;
		limF = plimF;
		limC = plimC;
		fil = pfil;
		col = pcol;
		visible = false;
		dx = dy = 0;
		orientation = Direccion::nothing;
		width = height = 70;
	}
	~Entidad(){}
#pragma region Set_Get
	// metodo get
	int getx() { return x; }
	int gety() { return y; }
	int getw() { return w; }
	int geth() { return h; }
	int getlimF() { return limF; }
	int getlimC() { return limC; }
	int getcol() { return col; }
	int getfil() { return fil; }
	int getdx() { return dx; }
	int getdy() { return dy; }
	int getfracY() { return fracY; }
	int getfracX() { return fracX; }
	bool getvisible() { return visible; }
	Rectangle getrec() { return Rectangle(x, y, width, height); }
	// metodo set
	void setx(int date) { x = date; }
	void sety(int date) { y = date; }
	void setw(int date) { w = date; }
	void seth(int date) { h = date; }
	void setlimF(int date) { limF = date; }
	void setlimC(int date) { limC = date; }
	void setcol(int date) { col = date; }
	void setfil(int date) { fil = date; }
	void setdx(int date) { dx = date; }
	void setdy(int date) { dy = date; }
	void setvisible(bool date) { visible = date; }
	void setfracX(int date) { fracX = date; }
	void setfracY(int date) { fracY = date; }
#pragma endregion

	/*void Desplazamiento(Direccion date)
	{
		dx = dy = 0;
		if (orientation == right) { dx = (w / fracX); fil = 3; }
		if (orientation == left) { dx = -(w / fracX); fil = 3; }
	}*/
	virtual void Move(Graphics^ g)
	{
		if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = dx * -1;
		if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) dy = dy * -1;
		x += dx;
		y += dy;
	}
	virtual void Draw(Graphics^ g, Bitmap^ bmp)
	{
		w = bmp->Width / limC;
		h = bmp->Height / limF;
		Rectangle destiny = Rectangle(x, y, width, height);
		Rectangle porcion = Rectangle(col * w, fil * h, w, h);
		g->DrawImage(bmp, destiny, porcion, GraphicsUnit::Pixel);
		col++;
		if (col == limC) col = 0;
	}


};