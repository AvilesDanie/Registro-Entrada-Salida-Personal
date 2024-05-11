/***********************************************************************
 * Module:  Persona.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#pragma once
#include <iostream>
#include "Fecha.h"
using namespace std;
class Persona
{
public:
	string getCedula(void);
	void setCedula(string newCedula);
	string getNombre(void);
	void setNombre(string newNombre);
	string getApellido(void);
	void setApellido(string newApellido);
	Fecha getFecha(void);
	void setFecha(Fecha newFecha);
	Persona();
	Persona(string,string,string,Fecha);
	~Persona();


protected:
private:
	string cedula;
	string nombre;
	string apellido;
	Fecha fecha;


};
