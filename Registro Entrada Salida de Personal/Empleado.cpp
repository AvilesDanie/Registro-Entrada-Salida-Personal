/***********************************************************************
 * Module:  Empleado.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Empleado
 ***********************************************************************/
#include "Empleado.h"

/**
* Devuelve el string de cedula
*
* @return string
**/
string Empleado::getCedula(void)
{
	return Persona::getCedula();
}

/**
* Cambia el string de cedula
*
* @param string newCedula
* 
* @return void
**/
void Empleado::setCedula(string newCedula)
{
	Persona::setCedula(newCedula);
}

/**
* Devuelve el string de nombre
*
* @return string
**/
string Empleado::getNombre(void)
{
	return Persona::getNombre();
}

/**
* Cambia el string de nombre
*
* @param string newNombre
*
* @return void
**/
void Empleado::setNombre(string newNombre)
{
	Persona::setNombre(newNombre);
}

/**
* Devuelve el string de apellido
*
* @return string
**/
string Empleado::getApellido(void)
{
	return Persona::getApellido();
}

/**
* Cambia el string de apellido
*
* @param string newApellido
*
* @return void
**/
void Empleado::setApellido(string newApellido)
{
	Persona::setApellido(newApellido);
}

/**
* Devuelve el TDA de fecha
*
* @return Fecha
**/
Fecha Empleado::getFecha(void)
{
	return Persona::getFecha();
}

/**
* Cambia el TDA de fecha
*
* @param Fecha newFecha
*
* @return void
**/
void Empleado::setFecha(Fecha newFecha)
{
	Persona::setFecha(newFecha);
}

/**
* Devuelve el double de salario
*
* @return double
**/
double Empleado::getSalario(void)
{
	return salario;
}

/**
* Cambia el double de salario
*
* @param double newSalario
*
* @return void
**/
void Empleado::setSalario(double newSalario)
{
	this->salario = newSalario;
}

/**
* Constructor vacio
**/
Empleado::Empleado() :Persona()
{
	this->salario = 0.0;
}

/**
* Constructor
**/
Empleado::Empleado(string newCedula, string newNombre, string newApellido, Fecha newFecha, double newSalario) :Persona(newCedula, newNombre, newApellido, newFecha)
{
	this->salario = newSalario;
}

/**
* Destructor
**/
Empleado::~Empleado()
{

}

/**
* Imprime los atributos en consola
*
* @return void
**/
void Empleado::imprimir() {
	cout << "*************************" << endl;
	cout << "Nombre: " << getNombre() << endl;
	cout << "Apellido: " << getApellido() << endl;
	cout << "Cedula: " << getCedula() << endl;
	cout << "Sueldo: " << getSalario() << endl;
	cout << "*************************" << endl;
}