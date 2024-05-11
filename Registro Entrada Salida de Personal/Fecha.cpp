/***********************************************************************
 * Module:  Fecha.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/
#include "Fecha.h"

/**
* Devuelve el int de dia
*
* @return double
**/
int Fecha::getDia(void)
{
	return dia;
}

/**
* Cambia el int de dia
*
* @param int newDia
*
* @return void
**/
void Fecha::setDia(int newDia)
{
	this->dia = newDia;
}

/**
* Devuelve el int de mes
*
* @return double
**/
int Fecha::getMes(void)
{
	return mes;
}

/**
* Cambia el int de mes
*
* @param int newMes
*
* @return void
**/
void Fecha::setMes(int newMes)
{
	this->mes = newMes;
}

/**
* Devuelve el int de anio
*
* @return double
**/
int Fecha::getAnio(void)
{
	return anio;
}

/**
* Cambia el int de anio
*
* @param int newAnio
*
* @return void
**/
void Fecha::setAnio(int newAnio)
{
	this->anio = newAnio;
}

/**
* Devuelve el int de hora
*
* @return double
**/
int Fecha::getHora(void)
{
	return hora;
}

/**
* Cambia el int de hora
*
* @param int newHora
*
* @return void
**/
void Fecha::setHora(int newHora)
{
	this->hora = newHora;
}

/**
* Devuelve el int de hora
*
* @return double
**/
int Fecha::getMinutos(void)
{
	return minutos;
}

/**
* Cambia el int de minutos
*
* @param int newMinutos
*
* @return void
**/
void Fecha::setMinutos(int newMinutos)
{
	this->minutos = newMinutos;
}

/**
* Devuelve el int de segundos
*
* @return double
**/
int Fecha::getSegundos(void)
{
	return segundos;
}

/**
* Cambia el int de segundos
*
* @param int newSegundos
*
* @return void
**/
void Fecha::setSegundos(int newSegundos)
{
	this->segundos = newSegundos;
}

/**
* Constructor
**/
Fecha::Fecha(int newDia,int newMes, int newAnio, int newHora, int newMinutos, int newSegundos)
{
	this->dia = newDia;
	this->mes = newMes;
	this->anio = newAnio;
	this->hora = newHora;
	this->minutos = newMinutos;
	this->segundos = newSegundos;
}

/**
* Constructor
**/
Fecha::Fecha(int newDia, int newMes, int newAnio)
{
	this->dia = newDia;
	this->mes = newMes;
	this->anio = newAnio;
	this->hora = 0;
	this->minutos = 0;
	this->segundos = 0;
}

/**
* Constructor vacio
**/
Fecha::Fecha()
{
	this->dia = 0;
	this->mes = 0;
	this->anio = 0;
	this->hora = 0;
	this->minutos = 0;
	this->segundos = 0;

}

/**
* Destructor
**/
Fecha::~Fecha()
{

}