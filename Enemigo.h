#pragma once
#include "Entidad.h"

enum SpriteEnemigo {
	izquierda,
	derecha
};

class Enemigo : public Entidad {
private:
	SpriteEnemigo accion;
public:
	Enemigo(Bitmap^ img, int x,int y, SpriteEnemigo accion) { //y será rand en el controller /huarzu:agregue x pues spwaneara desde ambos lados
		height = img->Height / 2; //2 filas   //accion será hacia dónde se mueve el enemigo (izq. o der.)
		width = img->Width / 4; //4 columnas
		this->y = y;
		this->x = x;
		dx = dy = 0;
		this->accion = accion;
	}
	~Enemigo(){}
	void Draw(Graphics^ g, Bitmap^ img) {
		Rectangle cut = Rectangle(IDx * width, accion * height, 64, 64);
		g->DrawImage(img, AreaRectangle(), cut, GraphicsUnit::Pixel); 
		if (dx != 0 || dy != 0) { //si se mueve
			switch (accion) //depende de la acción que se muestra movimiento del sprite
			{
			case izquierda:
				IDx = (IDx + 1) % 4; //el residuo de 4 entre 4 es 0, por lo que vuelve a 0 
				break;               //y comienza a aumentar hasta 4 cada vez que se ejecuta
			case derecha:
				IDx = (IDx + 1) % 4;
				break;
			}
		}
	}
	void move(Graphics^ g) {
		if (accion == derecha) { //si se va hacia la derecha
			if (x < g->VisibleClipBounds.Width) {
			
				setDx(10);
				x += dx;
			}
			else { //si sobrepasa los limites de la pantalla se detiene (para evitar errores)
				setDx(0);
				visible = false;
			}
			
		}
		if (accion == izquierda) { //si se va hacia la izquierda
			if (x + dx + width > 0) {
				setDx(-10);
				x += dx;
			}
			else { //cuando sea igual a 0 se detiene (para evitar errores)
				setDx(0);
				visible = false;
			}
			
		}
	}

#pragma region Set-Get-Functions
	int getPosicionX() { return x; } //usado para saber donde está x (desaparecer en una posición)
	int getPosicionY() { return y; } //por si acaso
	

	int getHeight() { return height; }

#pragma endregion
};