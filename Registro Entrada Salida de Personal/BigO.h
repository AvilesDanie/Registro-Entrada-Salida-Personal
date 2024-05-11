/***********************************************************************
 * Module:  BigO.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 23 de agosto de 2023
 * Purpose: Declaration of the class BigO
 ***********************************************************************/
#pragma once
#include "Arbol.h"
#include "ListaEmpleados.h"
#include "ListaRegistro.h"
#include "ListaEnteros.h"
#include "Archivos.h"
#include <fstream>
#include <chrono>

class BigO
{
public:
	void guardar(ListaEnteros datos, ListaEnteros duracion);
	void graficar();
	void insertarNodoCedulaBigO();
	void insertarNodoNombreBigO();
	void insertarNodoApellidoBigO();
	void insertarNodoSueldoBigO();
	void insertarNodoFechaBigO();
	void inOrdenBigO();
	void buscarBigO();
	void eliminarNodoBigO();
	void generarListaBigO();

	void insertarListaEmpleadosBigO();
	void eliminarListaEmpleadosBigO();
	void mostrarListaEmpleadosBigO();
	void buscarListaEmpleadosBigO();
	void dimencionListaEmpleadosBigO();
	void getPosicionListaEmpleadosBigO();
	void setPosicionListaEmpleadosBigO();
	void RecuperarListaEmpleadosBigO();

	void insertarListaRegistroBigO();
	void eliminarListaRegistroBigO();
	void mostrarListaRegistroBigO();
	void buscarListaRegistroBigO();
	void dimencionListaRegistroBigO();
	void getPosicionListaRegistroBigO();
	void setPosicionListaRegistroBigO();
	void RecuperarListaRegistroBigO();

	void insertarListaEnterosBigO();
	void dimencionListaEnterosBigO();
	void getPosicionListaEnterosBigO();

	void guardarListaRegistroBigO();
	void leerListaRegistroBigO();
	void leerListaRegistroFechaBigO();
	void guardarListaEmpleadosBigO();
	void leerListaEmpleadosBigO();
	/*void moverArchivosBigO();
	void crearCarpetaBigO();
	void copiarArchivosBigO();
	void imprimirImagenBigO();*/
	void generarPDFBigO();
	void generarPDFRegisrtosBigO();


	

};

