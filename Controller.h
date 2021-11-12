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
	~Controller() {}
	void addEnemy(Graphics^ g,Bitmap^ imgEnemigo) {
		int a = rand()% 2 + 1;
		if (a==1)//si sale 1 spawnea a la izquierda y se movera hacia la derecha
			enemigos.push_back(new Enemigo(imgEnemigo, 0, rand() % 500 + 60, derecha));//-50 es para que aparezca fuera de la vista del jugador
		else//viceversa
			enemigos.push_back(new Enemigo(imgEnemigo, g->VisibleClipBounds.Width-50, rand() % 500 + 60, izquierda));
	}
	void addBaño(Bitmap^ img,int x, int y) {
		baños.push_back(new Bano(img, x, y));
	}
	void addTacho(Bitmap^ img, int x, int y) {
		tachos.push_back(new Tacho(img, x, y));
	}
	void addbasura(Bitmap^ img, int x, int y) {
		basuras.push_back(new Basura(img, x, y));
	}
	void dibujarTodo(Graphics^g, Bitmap^ bmpClenaer, Bitmap^ bmpEnemy,  Bitmap^ bmpBaño, Bitmap^ bmpTacho, Bitmap^ bmpBasura) {
		cleaner->draw(g, bmpClenaer);
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->Draw(g, bmpEnemy);
		}
		for (int i = 0; i < baños.size(); i++) {
			baños[i]->draw(g, bmpBaño);
		}
		for (int i = 0; i < tachos.size(); i++) {
			tachos[i]->draw(g, bmpTacho);
		}
		for (int i = 0; i < basuras.size(); i++) {
			basuras[i]->draw(g, bmpBasura);
		}
	}
	void moverTodo(Graphics^g) {
		for (int i = 0; i < enemigos.size(); i++)
			enemigos[i]->move(g);
		cleaner->move(g);//aqui se le pone un condicional para no chocar con opbstaculos (huarzu: fijarse archivo C1)
	}
	void MovimientoMonigote(bool accion, Keys tecla) { //ESTA FUNCIÓN SE MOVERÁ A CONTROLLER
		int v = 5; //value == dx / dy
		if (accion == true)
		{
			if (tecla == Keys::W )
			{
				cleaner->setDy(-v);
				cleaner->setAccion(Arriba);
			}
				
			else if (tecla == Keys::S )
			{
				cleaner->setDy(v);
				cleaner->setAccion(Abajo);
			}

			else if (tecla == Keys::A )
			{
				cleaner->setDx(-v);
				cleaner->setAccion(Izquierda);
			}
				
			else if (tecla == Keys::D )
			{
				cleaner->setDx(v);
				cleaner->setAccion(Derecha);
			}
				
		}
		else
		{
			if (tecla == Keys::W )
				cleaner->setDy(0);
			else if (tecla == Keys::S )
				cleaner->setDy(0);
			else if (tecla == Keys::A)
				cleaner->setDx(0);
			else if (tecla == Keys::D )
				cleaner->setDx(0);
		}
	}
	void Collision() {
		
	}

	void collision(Graphics^ g) {
		//Verification
		for (int i = 0; i < enemigos.size(); i++) {
			
		}

		//Elimination
		//enemigos (fuera del mapa)
		for (int i = 0; i < enemigos.size(); i++) {
			if (!enemigos[i]->getVisible()) {
				enemigos.erase(enemigos.begin() + i);
			}
		}
		//basuras cuando pasan de estado enterrado
		for (int i = 0; i < basuras.size(); i++) {
			if (!basuras[i]->getVisible()) {
				basuras.erase(basuras.begin() + i);
			}
		}

	}
	

	/*void entierro() {
		for (int i = 0; i < basuras.size(); i++)
			switch (basuras[i]->getTipoBasura())
			{
			case 0:
				basuras[i]->setEstado(basuras[i]->getEstado()+1);

			default:
				break;
			}
			
		
	}*/

	
	Humano* getCleaner() { return cleaner; }
	Enemigo* getEnemigo(int i) { return enemigos[i]; }
	int  cantEnem() { return enemigos.size(); }
	Basura* getBasura(int i) { return basuras[i]; }
	int cantBasu() { return basuras.size(); }
	int cantBaños() { return baños.size(); }
	
};