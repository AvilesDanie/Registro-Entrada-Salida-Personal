/***********************************************************************
 * Module:  ListaRegistro.h
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 22 de junio de 2023
 * Purpose: Declaration of the class ListaRegistro
 ***********************************************************************/
#pragma once
#include "NodoRegistro.h"
#include <iostream>
#include "Fecha.h"
#include <string>
class ListaRegistro
{
private:
	NodoRegistro* cabeza;
	NodoRegistro* cola;
public:
	ListaRegistro();
	~ListaRegistro();
	void insertar(Registro);
	void eliminar(std::string);
	void mostrar();
	bool buscar(std::string);

	NodoRegistro* getCabeza();
	NodoRegistro* getCola();

	int dimencion();
	Registro getPosicion(int);
	void setPosicion(Registro, int);


	void Modificar(Registro);
	Registro Recuperar(string dato);


};

