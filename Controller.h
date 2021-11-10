#pragma once
#include <vector>
#include "Basura.h"
#include "Tacho.h"
#include "Baño.h"
#include "monigote.h"

class Controller {
private:
	vector<Basura*> basuras;
	vector<Tacho*> tachos;
	vector<Baño*> baños;
	Humano* cleaner;


	
public:
	Controller() {}
	~Controller() {}

};