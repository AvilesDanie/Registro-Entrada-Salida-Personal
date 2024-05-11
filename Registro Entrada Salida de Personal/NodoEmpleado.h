/***********************************************************************
 * Module:  NodoEmpleado.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoEmpleado
 ***********************************************************************/
#pragma once
#include "Empleado.h"
class NodoEmpleado
{
private:
	Empleado dato;
	NodoEmpleado* siguiente;
	NodoEmpleado* anterior;
public:
	NodoEmpleado(Empleado);
	~NodoEmpleado();
	void setDato(Empleado);
	Empleado getDato();
	void setSiguiente(NodoEmpleado*);
	NodoEmpleado* getSiguiente();
	void setAnterior(NodoEmpleado*);
	NodoEmpleado* getAnterior();
};

