/***********************************************************************
 * Module:  Nodo.cpp
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 22 de junio de 2023
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/
#include "Nodo.h"

/**
 * Establece el valor del nodo.
 *
 * @param Empleado _dato El valor que se almacenar� en el nodo.
 */
void Nodo::setValor(Empleado _dato)
{
    valor = _dato;
}

/**
 *
 * @param _izquierda El nodo que se establecer� como el hijo izquierdo del nodo actual.
 */
void Nodo::setIzquierda(Nodo* _izquierda)
{
    izquierda = _izquierda;
}

/**
 *
 * @param _derecha El nodo que se establecer� como el nodo derecho.
 */
void Nodo::setDerecha(Nodo* _derecha)
{
    derecha = _derecha;
}

/**
 * Devuelve el valor del nodo.
 *
 * @return El valor del nodo.
 */
Empleado Nodo::getValor()
{
    return valor;
}

/**
 * Devuelve el nodo izquierdo.
 *
 * @return Un puntero al nodo izquierdo.
 */
Nodo*& Nodo::getIzquierda()
{
    return izquierda;
}

/**
 * Devuelve el nodo derecho.
 *
 * @return Una referencia al nodo derecho.
 */
Nodo*& Nodo::getDerecha()
{
    return derecha;
}
Nodo*& Nodo::getNivel()
{
    return nivel;
}