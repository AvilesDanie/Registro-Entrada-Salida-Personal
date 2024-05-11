/***********************************************************************
 * Module:  Registro.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Registro
 ***********************************************************************/
#include "Registro.h"

 /**
 * Constructor vacio
 **/
Registro::Registro() {
	this->empleado = Empleado("null","null","null",Fecha(0,0,0),0);
	this->entrada = Fecha(0, 0, 0);
	this->entradaAlmuerzo = Fecha(0, 0, 0);
	this->salidaAlmuerzo = Fecha(0, 0, 0);
	this->salida = Fecha(0, 0, 0);
}

/**
* Constructor con solamente empleado
*
* @param Empleado empleado
**/
Registro::Registro(Empleado empleado) {
	this->empleado = empleado;
	this->entrada = Fecha(0, 0, 0);
	this->entradaAlmuerzo = Fecha(0, 0, 0);
	this->salidaAlmuerzo = Fecha(0, 0, 0);
	this ->salida = Fecha(0, 0, 0);
}

/**
* Constructor con todos los atributos
*
* @param Empleado empleado, Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida
**/
Registro::Registro(Empleado empleado, Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida) {
	this->empleado = empleado;
	this->entrada = entrada;
	this->entradaAlmuerzo = entradaAlmuerzo;
	this->salidaAlmuerzo = salidaAlmuerzo;
	this->salida = salida;
}

/**
* Constructor con solamente las fechas
*
* @param Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida
**/
Registro::Registro(Fecha entrada, Fecha salidaAlmuerzo, Fecha entradaAlmuerzo, Fecha salida) {
	this->empleado = Empleado(NULL, NULL, NULL, Fecha(0, 0, 0), 0);
	this->entrada = entrada;
	this->entradaAlmuerzo = entradaAlmuerzo;
	this->salidaAlmuerzo = salidaAlmuerzo;
	this->salida = salida;
}

/**
* Destructor
**/
Registro::~Registro() {

}

/**
* Devuelve el TDA de empleado
*
* @return Empleado
**/
Empleado Registro::getEmpleado() {
	return empleado;
}

/**
* Cambia el TDA de empleado
*
* @param Empleado newEmpleado
*
* @return void
**/
void Registro::setEmpleado(Empleado newEmpleado) {
	empleado = newEmpleado;
}

/**
* Devuelve el TDA de entrada
*
* @return Fecha
**/
Fecha Registro::getEntrada() {
	return entrada;
}

/**
* Cambia el TDA de entrada
*
* @param Fecha newEntrada
*
* @return void
**/
void Registro::setEntrada(Fecha newEntrada) {
	entrada = newEntrada;
}

/**
* Devuelve el TDA de salidaAlmuerzo
*
* @return Fecha
**/
Fecha Registro::getSalidaAlmuerzo() {
	return salidaAlmuerzo;
}

/**
* Cambia el TDA de salidaAlmuerzo
*
* @param Fecha newSalidaAlmuerzo
*
* @return void
**/
void Registro::setSalidaAlmuerzo(Fecha newSalidaAlmuerzo) {
	salidaAlmuerzo = newSalidaAlmuerzo;
}

/**
* Devuelve el TDA de entradaAlmuerzo
*
* @return Fecha
**/
Fecha Registro::getEntradaAlmuerzo() {
	return entradaAlmuerzo;
}

/**
* Cambia el TDA de entradaAlmuerzo
*
* @param Fecha newEntradaAlmuerzo
*
* @return void
**/
void Registro::setEntradaAlmuerzo(Fecha newEntradaAlmuerzo ) {
	entradaAlmuerzo = newEntradaAlmuerzo;
}

/**
* Devuelve el TDA de salida
*
* @return Fecha
**/
Fecha Registro::getSalida() {
	return salida;
}

/**
* Cambia el TDA de salida
*
* @param Fecha newSalida
*
* @return void
**/
void Registro::setSalida(Fecha newSalida) {
	salida = newSalida;
}

/**
* Imprime los atributos en consola
*
* @return void
**/
void Registro::imprimir() {
	cout << "*************************" << endl;
	if (entrada.getAnio() == 0)
		cout << "Entrada: Sin registrar" << endl;
	else
		cout << "Entrada: " << entrada.getHora()<< ":" << entrada.getMinutos() <<":"<< entrada.getSegundos() << "  " << entrada.getDia() << "/" << entrada.getMes() << "/" << entrada.getAnio() << endl;
	if (salidaAlmuerzo.getAnio() == 0)
		cout << "Salida Almuerzo: Sin registrar" << endl;
	else
		cout << "Salida Almuerzo: " << salidaAlmuerzo.getHora() << ":" << salidaAlmuerzo.getMinutos() << ":" << salidaAlmuerzo.getSegundos() << "  " << salidaAlmuerzo.getDia() << "/" << salidaAlmuerzo.getMes() << "/" << salidaAlmuerzo.getAnio() << endl;
	if (entradaAlmuerzo.getAnio()==0)
		cout << "Entrada Almuerzo: Sin registrar" << endl;
	else
		cout << "Entrada Almuerzo: " << entradaAlmuerzo.getHora() << ":" << entradaAlmuerzo.getMinutos() << ":" << entradaAlmuerzo.getSegundos() << "  " << entradaAlmuerzo.getDia() << "/" << entradaAlmuerzo.getMes() << "/" << entradaAlmuerzo.getAnio() << endl;
	if (salida.getAnio() == 0)
		cout << "Salida: Sin registrar" << endl;
	else
		cout << "Salida: " << salida.getHora() << ":" << salida.getMinutos() << ":" << salida.getSegundos() << "  " << salida.getDia() << "/" << salida.getMes() << "/" << salida.getAnio() << endl;
	cout << "*************************" << endl;
}