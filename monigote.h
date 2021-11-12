#pragma once
#include "Entidad.h"

enum SpritePlayer {
	Abajo,
	Izquierda,
	Derecha,
	Arriba
};

class Humano : public Entidad {
private:
	SpritePlayer accion;
	int dinero;
	int bolsa;
	int capacidadBolsa;
public:
	Humano(Bitmap^ img, int x, int y) {
		height = img->Height / 4; //alto = alto de la imagen entre 4 (un sprite)
		width = img->Width / 4; //ancho = ancho de la imagen entre 4 (un sprite)
		dx = dy = 0; //default dx y dy = 0
		accion = Abajo; //default acción mostrada en pantalla = sprite abajo
		this->x = x; //set x en la posicion de pantalla deseada
		this->y = y; //set y en la posicion de pantalla deseada
		dinero = 0;
		bolsa = 0;
		capacidadBolsa = 20;
	}
	~Humano(){}

	void draw(Graphics^ g, Bitmap^ img) {
		Rectangle corte = Rectangle(IDx * width, accion * height, width, height);
		//corte de la imagen
		g->DrawImage(img, AreaRectangle(), corte, GraphicsUnit::Pixel);
		if (dx != 0 || dy != 0) { //si se mueve
			switch (accion) //depende de la acción que se muestra movimiento del sprite
			{
			case Abajo:
				IDx = (IDx + 1) % 4; //el residuo de 4 entre 4 es 0, por lo que vuelve a 0 
				break;               //y comienza a aumentar hasta 4 cada vez que se ejecuta
			case Izquierda:
				IDx = (IDx + 1) % 4;
				break;
			case Derecha:
				IDx = (IDx + 1) % 4;
				break;
			case Arriba:
				IDx = (IDx + 1) % 4;
				break;
			}
		}
	}
	void move(Graphics^ g) {
		if (x + dx > 0 && x + dx + width < g->VisibleClipBounds.Width) {
			x += dx;
		}  //si (x / y) es mayor a 0 y menor al limite visible del formulario
		if (y + dy > 0 && y + dy + height < g->VisibleClipBounds.Height) {
			y += dy;
		}
		
	}
	
#pragma region Set-Get-Functions
	void setAccion(SpritePlayer value) {
		accion = value;
	}
	void setDinero(int v) { dinero = v; }
	int getDinero() { return dinero; }

	void setBolsa(int v) { bolsa = v; }
	int getBolsa() { return bolsa; }

	void setCapacidadBolsa(int v) { capacidadBolsa = v; }
	int getCapacidadBolsa() { return capacidadBolsa; }
	
#pragma endregion
};

//antigua función (inservible)

//class Humano : public Entidad
//{
//public:
//	Humano(int x, int y)
//	{
//		this->x = x;
//		this->y = y;
//
//		//x = 100;
//		//y = 100;
//	   //comentario salvaje de prueba aparece xd xdxdxdxd
//
//		dx = 5;
//		dy = 5;
//		idx = 0;
//		idy = 0;
//	};
//	~Humano(){}
//
//	void Draw(Graphics^ g, Bitmap^ bmp) {
//		ancho = bmp->Width / 4;;
//		alto = bmp->Height / 4;;
//		Rectangle seccionmostrar = Rectangle(idx * ancho, idy * alto, ancho, alto);
//		Rectangle zoom = Rectangle(x, y, ancho, alto);
//		g->DrawImage(bmp, zoom, seccionmostrar, GraphicsUnit::Pixel);
//	}
//
//	void movimientoMonigote(Graphics^ g, Keys k) //keys es una clase que tiene mapeado todo el teclado
//	{
//		switch (k)
//		{
//		case Keys::Left: //flecha izquierda
//			if (x > 0)
//			{
//				idy = 1;
//				x -= dx;
//			} break;
//
//		case Keys::Up: //flecha arriba
//
//			if (y > 50)
//			{
//				idy = 3;
//				y -= dy;
//
//			}break;
//		case Keys::Right: //flecha derecha
//			if (x + ancho * 1 < g->VisibleClipBounds.Width)
//			{
//				idy = 2;
//				x += dx;
//			}break;
//		case Keys::Down: //flecha abajo
//			if (y + alto * 1 < g->VisibleClipBounds.Height)
//			{
//				idy = 0;
//				y += dy;
//			}break;
//		}
//
//		idx++;
//		if (idx > 3)
//		{
//			idx = 0;
//		}
//	}
//};