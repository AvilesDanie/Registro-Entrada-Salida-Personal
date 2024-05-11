/***********************************************************************
 * Module:  Empleado.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Empleado
 ***********************************************************************/
#pragma once
#include <iostream>
#include "Persona.h"
#include <string>
using namespace std;

class Empleado : public Persona
{
public:
    Empleado();
    Empleado(string, string, string, Fecha, double);
    ~Empleado();
    string getCedula(void);
    void setCedula(string newCedula);
    string getNombre(void);
    void setNombre(string newNombre);
    string getApellido(void);
    void setApellido(string newApellido);
    Fecha getFecha(void);
    void setFecha(Fecha newFecha);
    double getSalario(void);
    void setSalario(double newSalario);
    void imprimir();

private:
    double salario;
};

