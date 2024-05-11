/***********************************************************************
 * Module:  Nodo.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/
#pragma once
#include <iostream>
#include <stdio.h>
#include "Empleado.h"
using namespace std;
class Nodo
{
public:
	Empleado getValor();
	Nodo*& getDerecha();
	Nodo*& getIzquierda();
	Nodo*& getNivel();
	void setValor(Empleado);
	void setDerecha(Nodo*);
	void setIzquierda(Nodo*);

private:
	Empleado valor;
	Nodo* derecha;
	Nodo* izquierda;
	Nodo* nivel;
};

