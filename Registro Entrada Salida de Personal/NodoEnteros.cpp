#include "NodoEnteros.h"

/**
* Constructor
*
* @param int dato Data asignado para el atributo dato
**/
NodoEnteros::NodoEnteros(int dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

/**
* Destructor
**/
NodoEnteros::~NodoEnteros()
{
}

/**
 * Cambia el valor del atributo dato
 *
 * @param int newValor. Dato al que se quiere cambiar.
 **/
void NodoEnteros::setDato(int dato)
{
	this->dato = dato;
}

/**
 * Devuelve el atributo dato
 *
 * @return int dato. El atributo dato.
 **/
int NodoEnteros::getDato()
{
	return this->dato;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoNodoDoble* siguiente. Dato al que se quiere cambiar.
 **/
void NodoEnteros::setSiguiente(NodoEnteros* siguiente)
{
	this->siguiente = siguiente;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoDoble* siguiente. El atributo siguiente.
 **/
NodoEnteros* NodoEnteros::getSiguiente()
{
	return this->siguiente;
}

/**
 * Cambia el valor del atributo anterior
 *
 * @param NodoNodoDoble* anterior. Dato al que se quiere cambiar.
 **/
void NodoEnteros::setAnterior(NodoEnteros* anterior)
{
	this->anterior = anterior;
}

/**
 * Devuelve el atributo anterior
 *
 * @return NodoDoble* anterior. El atributo anterior.
 **/
NodoEnteros* NodoEnteros::getAnterior()
{
	return this->anterior;
}
