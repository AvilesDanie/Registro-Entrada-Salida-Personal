/***********************************************************************
 * Module:  Arbol.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/
#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>
#include "ListaRegistro.h"
#include "ListaEmpleados.h"

class Arbol
{
private:
    Nodo* arbol = NULL;
public:
    void setArbol(Nodo*);
    Nodo* getArbol();
    Nodo* crearNodo(Empleado);
    void insertarNodoCedula(Nodo*&, Empleado);
    void insertarNodoNombre(Nodo*&, Empleado);
    void insertarNodoApellido(Nodo*&, Empleado);
    void insertarNodoFecha(Nodo*&, Empleado);
    void insertarNodoSueldo(Nodo*&, Empleado);
    void buscar(Nodo*, std::string);
    void inOrden(Nodo*);
    Nodo* eliminarNodo(Nodo*, std::string);
    ListaEmpleados* generarLista(Nodo*, ListaEmpleados*);

};
