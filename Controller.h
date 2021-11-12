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
			if (tecla == Keys::Up )
			{
				cleaner->setDy(-v);
				cleaner->setAccion(Arriba);
			}
				
			else if (tecla == Keys::Down )
			{
				cleaner->setDy(v);
				cleaner->setAccion(Abajo);
			}

			else if (tecla == Keys::Left )
			{
				cleaner->setDx(-v);
				cleaner->setAccion(Izquierda);
			}
				
			else if (tecla == Keys::Right )
			{
				cleaner->setDx(v);
				cleaner->setAccion(Derecha);
			}
				
		}
		else
		{
			if (tecla == Keys::Up )
				cleaner->setDy(0);
			else if (tecla == Keys::Down )
				cleaner->setDy(0);
			else if (tecla == Keys::Left)
				cleaner->setDx(0);
			else if (tecla == Keys::Right )
				cleaner->setDx(0);
		}
	}
	void Collision() {
		
	}

	




	Humano* getCleaner() { return cleaner; }
	Enemigo* getEnemigo(int i) { return enemigos[i]; }
	int  cantEnem() { return enemigos.size(); }
	
};