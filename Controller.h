#pragma once
#include <vector>
#include "Basura.h"
#include "Tacho.h"
#include "Bano.h"
#include "monigote.h"
#include "Enemigo.h"

class Controller {
private:
	vector<Basura*> basuras;
	vector<Tacho*> tachos;
	vector<Enemigo*> enemigos;
	vector<Bano*> baños;
	Humano* cleaner;

public:
	Controller(Bitmap^ imgCleaner) {
		cleaner = new Humano(imgCleaner,100,100);
	}
	void addEnemy(Graphics^ g,Bitmap^ imgEnemigo) {
		int a = rand()% 2 + 1;
		if (a==1)//si sale 1 spawnea a la izquierda y se movera hacia la derecha
			enemigos.push_back(new Enemigo(imgEnemigo, 0 , rand() % 100, derecha));
		else//viceversa
			enemigos.push_back(new Enemigo(imgEnemigo, g->VisibleClipBounds.Width,rand() % 100, izquierda));
	}
	void addBaño() {
		
	}
	void dibujarTodo(Graphics^g, Bitmap^ bmp) {
		cleaner->draw(g,bmp);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->draw(g, bmp);
		}


	}

	~Controller() {}

};