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
	int nivelMicrobiologico;
	int limpiezaPlaya;

public:
	Controller(Bitmap^ imgCleaner) {
		cleaner = new Humano(imgCleaner,100,100);
		nivelMicrobiologico = 0;
		limpiezaPlaya = 0;
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
		for (int i = 0; i < tachos.size(); i++)//colision con tacho 
			if (!cleaner->AreaNextRectangle().IntersectsWith(tachos[i]->AreaTacho()))
				cleaner->move(g);
		for (int i = 0; i < baños.size(); i++)//colision con baño 
			if (!cleaner->AreaNextRectangle().IntersectsWith(baños[i]->AreaBano()))
				cleaner->move(g);
	}
	void MovimientoMonigote(bool accion, Keys tecla) {
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
	

	void collision(Graphics^ g) {
		//colisiones directas
		for (int i = 0; i < basuras.size(); i++) {//personaje con basura respecto a su bolsa
			if (cleaner->getBolsa() != cleaner->getCapacidadBolsa())
			{
				if (cleaner->AreaRectangle().IntersectsWith(basuras[i]->AreaRectangle())) {
					basuras[i]->setVisible(false);
					basuras.erase(basuras.begin() + i);
					cleaner->setBolsa(cleaner->getBolsa() + 1);
				}
			}
		}
		for (int i = 0; i < basuras.size(); i++)//radio de recoleccion automatica de tacho con basura 
		{
			for (int g = 0; g < tachos.size(); g++)
			{
				if (basuras[i]->AreaRectangle().IntersectsWith(tachos[g]->AreaRecoleccionTacho())) {
					basuras[i]->setVisible(false);
					basuras.erase(basuras.begin() + i);
					cleaner->setDinero(cleaner->getDinero() + 10);
					limpiezaPlaya++;
				}
			}
			
		}
		for (int i = 0; i < tachos.size(); i++)//radio de tacho interactua con personaje
		{
			if (tachos[i]->AreaRecoleccionTacho().IntersectsWith(cleaner->AreaRectangle())) {
				cleaner->setDinero(cleaner->getDinero() + (cleaner->getBolsa() * cleaner->getCapacidadBolsa()));//el dinero = el dinero actual + (capacidad de bolsa*cantidad de basura en la bolsa*10(dinero que otorga cada basura))
				limpiezaPlaya += cleaner->getBolsa();
				cleaner->setBolsa(0);
			}
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
				nivelMicrobiologico-=8;
			}
		}

	}
	void addNivelMicrobiologico() { nivelMicrobiologico+=cantBaños()*2; }

	
	Humano* getCleaner() { return cleaner; }
	Enemigo* getEnemigo(int i) { return enemigos[i]; }
	int  cantEnem() { return Convert::ToInt64(enemigos.size()); }
	Basura* getBasura(int i) { return basuras[i]; }
	int cantBasu() { return Convert::ToInt64(basuras.size()); }
	int cantBaños() { return Convert::ToInt64(baños.size()); }
	int getMicrobiologico() { return nivelMicrobiologico; }
	void setMicrobiologico(int v) { nivelMicrobiologico = v; }
	int getLimpiezaPlaya() { return limpiezaPlaya; }
	void setLimpiezaPlaya(int v) { limpiezaPlaya = v; }
	
};