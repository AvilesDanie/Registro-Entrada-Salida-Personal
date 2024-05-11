/***********************************************************************
 * Module:  Registro.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Registro
 ***********************************************************************/
#pragma once
#include "Fecha.h"
#include "Empleado.h"
#include <iostream>
class Registro
{
private:
	Empleado empleado;
	Fecha entrada;
	Fecha salidaAlmuerzo;
	Fecha entradaAlmuerzo;
	Fecha salida;
public:
	Registro();
	Registro(Empleado);
	Registro(Empleado,Fecha, Fecha, Fecha, Fecha);
	Registro(Fecha, Fecha, Fecha, Fecha);
	~Registro();
	Empleado getEmpleado();
	void setEmpleado(Empleado);
	Fecha getEntrada();
	void setEntrada(Fecha);
	Fecha getSalidaAlmuerzo();
	void setSalidaAlmuerzo(Fecha);
	Fecha getEntradaAlmuerzo();
	void setEntradaAlmuerzo(Fecha);
	Fecha getSalida();
	void setSalida(Fecha);
	void imprimir();
};

