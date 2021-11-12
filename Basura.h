#pragma once
#include "Entidad.h"

class Basura : public Entidad {
private:
	int tipoBasura;
public:
	Basura(Bitmap^ img, int x, int y) {
		width = img->Width / 3;
		height = img->Height / 3;
		this->x = x;
		this->y = y;
		dx = dy = 0;
		IDx = 0; //sirve para cambiar de estado en este caso
		tipoBasura = rand() % 3;//son 3 filas, cada fila es una tipo diferente de fila
		
	}
	void draw(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * width, tipoBasura * height, 40, 40);
		g->DrawImage(img, AreaRectangle(), corte, GraphicsUnit::Pixel);
	}
	void cambioEstado(int milisegundos) { //implementar en timer (crear un for e ingresar el int a la función)
		if (milisegundos == 100) { //al pasar 10 segundos
			IDx = 1;
		}
		if (milisegundos == 300) { //al pasar 30 segundos
			IDx = 2;
		}
	}
#pragma region Set-Get-Functions
	int getEstado() { return IDx; } //implementar para hacer eventos en base al estado de la basura
	// 0 = basura normal, 1 = basura media enterrada, 2 = basura totalmente enterrada
	
	void setEstado(int newIDx) { IDx = newIDx; } //probable implementación en colision
												 //cuando la persona choca con la basura
#pragma endregion
};