/***********************************************************************
 * Module:  Administrador.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Administrador
 ***********************************************************************/
#include "Administrador.h"
/**
* Destructor
*/
Administrador::~Administrador() {

}

/**
* Constructor vacio
**/
Administrador::Administrador() {
	this->usuario = "NULL";
	this->contrasenia = "NULL";
	this->empleado;

}

/**
* Constructor
* 
* @param string newUsuario, string newContrasenia, Empleado newEmpleado
**/
Administrador::Administrador(string newUsuario, string newContrasenia, Empleado newEmpleado) {
	this->usuario = newUsuario;
	this->contrasenia = newContrasenia;
	this->empleado = newEmpleado;
}

/**
* Devuelve el strign de usuario
*
* @return string 
**/
std::string Administrador::getUsuario() {
	return usuario;
}

/**
* Cambia el strign de usuario
* 
* @param std::string newUsuario
*
* @return void
**/
void Administrador::setUsuario(std::string newUsuario) {
	this->usuario = newUsuario;

}

/**
* Devuelve el strign de constaseña
*
* @return string
**/
std::string Administrador::getContrasenia() {
	return contrasenia;
}

/**
* Cambia el strign de contraseña
*
* @param std::string newContrasenia
*
* @return void
**/
void Administrador::setContrasenia(std::string newContrasenia) {
	this->contrasenia = newContrasenia;

}

/**
* Devuelve el TDA de empleado
*
* @return Empleado
**/
Empleado Administrador::getEmpleado() {
	return empleado;
}

/**
* Cambia el TDA de empleado
*
* @param Empleado newEmpleado
*
* @return void
**/
void Administrador::setEmpleado(Empleado newEmpleado) {
	this->empleado = newEmpleado;

}