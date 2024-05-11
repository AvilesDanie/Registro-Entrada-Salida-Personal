/***********************************************************************
 * Module:  Arbol.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/
#pragma once
#include "Arbol.h"
#include <vector>

/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 *
 * @param _arbol El nodo raíz del árbol.
 */
void Arbol::setArbol(Nodo* _arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 *
 * @return El nodo raíz del árbol.
 */
Nodo* Arbol::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 *
 * @param dato El valor del nodo
 *
 * @return Un puntero a un objeto Nodo.
 */
Nodo* Arbol::crearNodo(Empleado dato)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoCedula(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        string raiz = arbol->getValor().getCedula();
        if (dato.getCedula() < raiz)
        {
            insertarNodoCedula(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodoCedula(arbol->getDerecha(), dato);
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoNombre(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        string raiz = arbol->getValor().getNombre();
        if (dato.getNombre() < raiz)
        {
            insertarNodoNombre(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodoNombre(arbol->getDerecha(), dato);
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoApellido(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        string raiz = arbol->getValor().getApellido();
        if (dato.getApellido() < raiz)
        {
            insertarNodoApellido(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodoApellido(arbol->getDerecha(), dato);
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoSueldo(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        double raiz = arbol->getValor().getSalario();
        if (dato.getSalario() < raiz)
        {
            insertarNodoApellido(arbol->getIzquierda(), dato);
        }
        else
        {
            insertarNodoApellido(arbol->getDerecha(), dato);
        }
    }
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 *
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodoFecha(Nodo*& arbol, Empleado dato)
{
    if (arbol == NULL)
    {
        Nodo* nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
    }
    else
    {
        Fecha raiz = arbol->getValor().getFecha();
        if (dato.getFecha().getAnio() < raiz.getAnio())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
        }
        else if (dato.getFecha().getAnio() > raiz.getAnio())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
        }
        else if (dato.getFecha().getMes() < raiz.getMes())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
        }
        else if (dato.getFecha().getMes() > raiz.getMes())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
        }
        else if (dato.getFecha().getDia() < raiz.getDia())
        {
            insertarNodoFecha(arbol->getIzquierda(), dato);
        }
        else if (dato.getFecha().getDia() > raiz.getDia())
        {
            insertarNodoFecha(arbol->getDerecha(), dato);
        }
        else {
            insertarNodoFecha(arbol->getDerecha(), dato);
        }
    }
}



/**
 * Recorrido inOrden.
 *
 * @param arbol Un puntero al nodo de la raíz.
 *
 * @return Dato entero del nodo.
 */
void Arbol::inOrden(Nodo* arbol)
{
    if (arbol == NULL)
    {
        return;
        cout << "No se encuentran datos en el arbol" << endl;
        cout << "El arbol se encuentra vacio" << endl;
    }
    else
    {
        inOrden(arbol->getIzquierda());
        arbol->getValor().imprimir();
        inOrden(arbol->getDerecha());
    }
}

void Arbol::buscar(Nodo* arbol, std::string dato) {
    if (arbol == NULL) {
        cout << "No se encuentran datos en el arbol\n";
    }
    else if (arbol->getValor().getCedula() == dato) {
        arbol->getValor().imprimir();
        cout << "Dato encontrado correctamente...\n";
    }
    else if (dato < arbol->getValor().getCedula()) {
        buscar(arbol->getIzquierda(), dato);
    }
    else {
        buscar(arbol->getDerecha(), dato);
    }
}



Nodo* Arbol::eliminarNodo(Nodo* raiz, std::string dato) {

    if (raiz == NULL)
        return raiz;
    if (dato < raiz->getValor().getCedula())
        raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), dato));

    else if (dato > raiz->getValor().getCedula())
        raiz->setDerecha(eliminarNodo(raiz->getDerecha(), dato));
    else {
        if (raiz->getIzquierda() == NULL) {
            Nodo* temp = raiz->getDerecha();
            delete(raiz);
            return temp;
        }
        else if (raiz->getDerecha() == NULL) {
            Nodo* temp = raiz->getIzquierda();
            delete(raiz);
            return temp;
        }
        else {
            auto getmax = [](Nodo* raiz) {
                Nodo* aux = new Nodo();
                aux = raiz;
                while (aux && aux->getDerecha()) {
                    aux = aux->getDerecha();
                }
                return aux;
            };

            Nodo* temp = getmax(raiz->getIzquierda());

            raiz->setValor(temp->getValor());
            raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), temp->getValor().getCedula()));
        }
    }
    return raiz;
}




ListaEmpleados* Arbol::generarLista(Nodo* arbol, ListaEmpleados* listaEmpleados)
{
    if (arbol == NULL)
    {
    }
    else
    {
        generarLista(arbol->getIzquierda(), listaEmpleados);

        listaEmpleados->insertar(arbol->getValor());

        //arbol->getValor().imprimir();

        generarLista(arbol->getDerecha(), listaEmpleados);
    }
    return listaEmpleados;
}