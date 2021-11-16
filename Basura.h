#pragma once
#include "Entidad.h"

class Basura : public Entidad {
private:
	int tipoBasura;
	int tiempo;
public:
	Basura(Bitmap^ img, int x, int y) {
		width = img->Width / 3;
		height = img->Height / 3;
		this->x = x;
		this->y = y;
		dx = dy = 0;
		tiempo = 0;
		IDx = 0; //sirve para cambiar de estado en este caso
		tipoBasura = rand() % 2;//son 3 filas, cada fila es una tipo diferente de fila desde el menos contaminante(0=papel/organico) hasta el que mas (2=plastico/inorganico)
		
	}
	void addTime() { tiempo++; }
	void draw(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * width, tipoBasura * height, 40, 40);
		g->DrawImage(img, AreaRectangle(), corte, GraphicsUnit::Pixel);
	}
	void cambioEstado() { 
		if (tiempo == 50)//5segundos
			IDx++;
		if (tiempo == 100)//10segundos
			IDx++;
		if (tiempo == 130)//13segundos
			IDx++;
		if (IDx >= 3)
			visible = false;

	}
#pragma region Set-Get-Functions
	int getEstado() { return IDx; } //implementar para hacer eventos en base al estado de la basura
	// 0 = basura normal, 1 = basura media enterrada, 2 = basura totalmente enterrada, si es 3 se elimina
	
	void setEstado(int newIDx) { IDx = newIDx; } //probable implementación en colision
												 //cuando la persona choca con la basura

#pragma endregion
};