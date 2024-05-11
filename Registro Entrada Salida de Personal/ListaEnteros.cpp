/***********************************************************************
 * Module:  ListaEnteros.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 23 de agosto de 2023
 * Purpose: Declaration of the class ListaEnteros
 ***********************************************************************/
#include "ListaEnteros.h"
#include <iostream>
using namespace std;

/**
 * Constructor
 **/
ListaEnteros::ListaEnteros()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
}

/**
 * Destructor
 **/
ListaEnteros::~ListaEnteros()
{
}

/**
* Inserta un elemento a la insertar
*
* @param int valor. Valor que se quiere insertar en la lista
**/
void ListaEnteros::insertar(int dato)
{
	NodoEnteros* nuevo = new NodoEnteros(dato);
	if (this->cabeza == nullptr)
	{
		this->cabeza = nuevo;
		this->cola = nuevo;
		this->cabeza->setSiguiente(this->cola);
		this->cabeza->setAnterior(this->cola);
		this->cola->setSiguiente(this->cabeza);
		this->cola->setAnterior(this->cabeza);
	}
	else
	{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
		nuevo->setSiguiente(this->cabeza);
		this->cabeza->setAnterior(nuevo);
		this->cola = nuevo;
	}
}

/**
* Cuenta la cantidad de elementos que existe dentro de la lista.
*
* @return Un entero con el numero de elementos incluyendo el 0
**/
int ListaEnteros::dimencion() {
	NodoEnteros* aux = cabeza;
	int dim = 0;
	aux = aux->getSiguiente();
	dim += 1;
	while (aux != cabeza) {
		aux = aux->getSiguiente();
		dim += 1;
	}
	return dim;
}

/**
* Devuelve el valor del elemento de una lista dependiendo de en que posicion se encuentre.
*
* @param int Indice posicion en la que se quiere buscar
*
* @return El valor de  elemento en la posicion propuesta
**/
int ListaEnteros::getPosicion(int indice) {
	NodoEnteros* aux = cabeza;
	for (int i = 0; i < indice; i++) {
		aux = aux->getSiguiente();
	}
	return aux->getDato();
}
