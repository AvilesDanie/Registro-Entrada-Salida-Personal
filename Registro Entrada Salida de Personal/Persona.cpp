/***********************************************************************
 * Module:  Persona.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#include "Persona.h"

/**
* Devuelve el string de cedula
*
* @return string
**/
string Persona::getCedula(void)
{
	return cedula;
}


/**
* Cambia el string de cedula
*
* @param string newCedula
*
* @return void
**/
void Persona::setCedula(string newCedula)
{
	this->cedula = newCedula;
}

/**
* Devuelve el string de nombre
*
* @return string
**/
string Persona::getNombre(void)
{
	return nombre;
}

/**
* Cambia el string de nombre
*
* @param string newNombre
*
* @return void
**/
void Persona::setNombre(string newNombre)
{
	this->nombre = newNombre;
}


/**
* Devuelve el string de apellido
*
* @return string
**/
string Persona::getApellido(void)
{
	return apellido;
}


/**
* Cambia el string de apellido
*
* @param string newApellido
*
* @return void
**/
void Persona::setApellido(string newApellido)
{
	this->apellido = newApellido;
}


/**
* Devuelve el TDA de fecha
*
* @return Fecha
**/
Fecha Persona::getFecha(void)
{
	return fecha;
}


/**
* Cambia el TDA de fecha
*
* @param Fecha newFecha
*
* @return void
**/
void Persona::setFecha(Fecha newFecha)
{
	this->fecha = newFecha;
}


/**
* Cosntructor vacio
**/
Persona::Persona()
{
	this->cedula = "NULL";
	this->nombre = "NULL";
	this->apellido = "NULL";
	this->fecha;
}


/**
* Cosntructor
* 
* @param string newCedula, string newNombre, string newApellido, Fecha newFecha
* 
**/
Persona::Persona(string newCedula, string newNombre, string newApellido, Fecha newFecha)
{
	this->cedula = newCedula;
	this->nombre = newNombre;
	this->apellido = newApellido;
	this->fecha = newFecha;
}

/**
* Destructor
**/
Persona::~Persona()
{

}