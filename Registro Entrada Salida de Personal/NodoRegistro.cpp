/***********************************************************************
 * Module:  NodoRegistro.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoRegistro
 ***********************************************************************/
#include "NodoRegistro.h"

 /**
 * Constructor
 *
 * @param Registro dato Data asignado para el atributo dato
 **/
NodoRegistro::NodoRegistro(Registro dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

/**
* Destructor
**/
NodoRegistro::~NodoRegistro()
{
}

/**
 * Cambia el valor del atributo dato
 *
 * @param Registro dato. Dato al que se quiere cambiar.
 **/
void NodoRegistro::setDato(Registro dato)
{
	this->dato = dato;
}

/**
 * Devuelve el atributo dato
 *
 * @return Registro dato. El atributo dato.
 **/
Registro NodoRegistro::getDato()
{
	return this->dato;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoRegistro* siguiente. Dato al que se quiere cambiar.
 **/
void NodoRegistro::setSiguiente(NodoRegistro* siguiente)
{
	this->siguiente = siguiente;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoRegistro* siguiente. El atributo siguiente.
 **/
NodoRegistro* NodoRegistro::getSiguiente()
{
	return this->siguiente;
}

/**
 * Cambia el valor del atributo anterior
 *
 * @param NodoRegistro* anterior. Dato al que se quiere cambiar.
 **/
void NodoRegistro::setAnterior(NodoRegistro* anterior)
{
	this->anterior = anterior;
}

/**
 * Devuelve el atributo anterior
 *
 * @return NodoRegistro* anterior. El atributo anterior.
 **/
NodoRegistro* NodoRegistro::getAnterior()
{
	return this->anterior;
}
