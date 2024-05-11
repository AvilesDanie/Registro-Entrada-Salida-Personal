/***********************************************************************
 * Module:  ValidacionDatos.h
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 22 de junio de 2023
 * Purpose: Declaration of the class ValidacionDatos
 ***********************************************************************/
#pragma once
#include <iostream>
#include "Fecha.h"
class ValidacionDatos
{
public:
	bool validarCedula(std::string);
	Fecha ingresarFecha();
	Fecha ingresarFechaA();
	int ingresarDatosEnteros();
	string ingresarNombre();
	float ingresarDatosfloat();
};

