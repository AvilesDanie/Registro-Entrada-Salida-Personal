/***********************************************************************
 * Module:  Archivos.h
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Archivos
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaEmpleados.h"
#include "ListaRegistro.h"
#include "Empleado.h"
#include "Registro.h"
#include <unordered_set>
#include <opencv2/opencv.hpp>

class Archivos {
public:
	void guardarListaRegistro(ListaRegistro* lista);
	ListaRegistro* leerListaRegistro(int, int, int);
	ListaRegistro* leerListaRegistro();
	void guardarListaEmpleados(ListaEmpleados* lista);
	ListaEmpleados* leerListaEmpleados();
	void moverArchivos(const std::vector<std::string>&, const std::string&);
	void crearCarpeta(const std::string& );
	void copiarArchivos(const std::string& , const std::string& );
	void imprimirImagen();
	void generarPDF( ListaEmpleados* );
	void generarPDFRegisrtos(ListaRegistro*);

};

