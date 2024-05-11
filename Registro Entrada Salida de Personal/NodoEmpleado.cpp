/***********************************************************************
 * Module:  NodoEmpleado.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class NodoEmpleado
 ***********************************************************************/
#include "NodoEmpleado.h"

 /**
 * Constructor
 *
 * @param Empleado dato Data asignado para el atributo dato
 **/
NodoEmpleado::NodoEmpleado(Empleado dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

/**
* Destructor
**/
NodoEmpleado::~NodoEmpleado()
{
}

/**
 * Cambia el valor del atributo dato
 *
 * @param Empleado dato. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setDato(Empleado dato)
{
	this->dato = dato;
}

/**
 * Devuelve el atributo dato
 *
 * @return Empleado. El atributo dato.
 **/
Empleado NodoEmpleado::getDato()
{
	return this->dato;
}

/**
 * Cambia el valor del atributo siguiente
 *
 * @param NodoEmpleado* siguiente. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setSiguiente(NodoEmpleado* siguiente)
{
	this->siguiente = siguiente;
}

/**
 * Devuelve el atributo siguiente
 *
 * @return NodoEmpleado* siguiente. El atributo siguiente.
 **/
NodoEmpleado* NodoEmpleado::getSiguiente()
{
	return this->siguiente;
}

/**
 * Cambia el valor del atributo anterior
 *
 * @param NodoEmpleado* anterior. Dato al que se quiere cambiar.
 **/
void NodoEmpleado::setAnterior(NodoEmpleado* anterior)
{
	this->anterior = anterior;
}

/**
 * Devuelve el atributo anterior
 *
 * @return NodoEmpleado* anterior. El atributo anterior.
 **/
NodoEmpleado* NodoEmpleado::getAnterior()
{
	return this->anterior;
}