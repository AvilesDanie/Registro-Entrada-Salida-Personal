/***********************************************************************
 * Module:  ListaEnteros.h
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaEnteros
 ***********************************************************************/
#pragma once
#include "NodoEnteros.h"
class ListaEnteros
{
private:
	NodoEnteros* cabeza;
	NodoEnteros* cola;
public:
	ListaEnteros();
	~ListaEnteros();
	void insertar(int);

	int dimencion();
	int getPosicion(int);
};
