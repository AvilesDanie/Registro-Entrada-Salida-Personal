/***********************************************************************
 * Module:  NodoEnteros.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoEnteros
 ***********************************************************************/
#pragma once
class NodoEnteros
{
private:
	int dato;
	NodoEnteros* siguiente;
	NodoEnteros* anterior;
public:
	NodoEnteros(int);
	~NodoEnteros();
	void setDato(int);
	int getDato();
	void setSiguiente(NodoEnteros*);
	NodoEnteros* getSiguiente();
	void setAnterior(NodoEnteros*);
	NodoEnteros* getAnterior();
};
