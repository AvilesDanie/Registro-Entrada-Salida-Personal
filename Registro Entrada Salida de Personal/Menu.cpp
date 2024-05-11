/***********************************************************************
 * Module:  Menu.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 4 de julio de 2023
 * Purpose: Declaration of the class Menu
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "ValidacionDatos.h"
#include "Arbol.h"
#include "ListaRegistro.h"
#include "ListaEmpleados.h"
#include "Registro.h"
#include <ctime>
#include "Administrador.h"
#include "BigO.h"

#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13
using namespace std;

/**
* Muestra y controla el menu de opciones
*
* @param null
*
* @return void
**/
void Menu::menuPrincipal() {
	int opcMP = 0, opcMN = 0, op=0;
	bool repetir = true, repetir1 = false, repetirCedula = false, repetirLI, repetirL2=false, repetirM=false;
	Arbol empleados;
	ValidacionDatos validacion;
	Archivos objArc;
	ListaRegistro* listaRegistros = new ListaRegistro();
	ListaRegistro* listaRegistrosR = new ListaRegistro();
	ListaEmpleados* listaEmpleados = new ListaEmpleados();

	BigO bigO;

	const char* titulo = "BIENVENIDO AL APLICATIVO DE REGISTRO";

	const char** opciones = (const char**)malloc(3 * sizeof(const char**));
	*opciones = "REGISTRO DE PERSONAL.";
	*(opciones + 1) = "LOG IN.";
	*(opciones + 2) = "MAS ...\n\n";

	const char** opciones1 = (const char**)malloc(2 * sizeof(const char*));
	*opciones1 = "INTENTAR NUEVAMENTE.";
	*(opciones1 + 1) = "SALIR.\n\n";

	const char** opciones2 = (const char**)malloc(9 * sizeof(const char*));
	*opciones2 = "INGRESAR.";
	*(opciones2 + 1) = "MODIFICAR.";
	*(opciones2 + 2) = "ELIMINAR.";
	*(opciones2 + 3) = "BUSCAR.";
	*(opciones2 + 4) = "ORDENAR.";
	*(opciones2 + 5) = "GENERAR PDF.";
	*(opciones2 + 6) = "VER REGISTRO.";
	*(opciones2 + 7) = "BACK UP.";
	*(opciones2 + 8) = "SALIR.\n\n";

	const char** opciones3 = (const char**)malloc(4 * sizeof(const char*));
	*opciones3 = "Nombre.";
	*(opciones3 + 1) = "Apellido.";
	*(opciones3 + 2) = "Sueldo.";
	*(opciones3 + 3) = "Atras. \n\n";

	const char** opciones4 = (const char**)malloc(5 * sizeof(const char*));
	*opciones4 = "Ordenar por cedula.";
	*(opciones4 + 1) = "Ordenar por nombre.";
	*(opciones4 + 2) = "Ordenar por apellido.";
	*(opciones4 + 3) = "Ordenas por nacimiento.";
	*(opciones4 + 4) = "Ordenar por sueldo. \n\n";

	const char** opciones5 = (const char**)malloc(5 * sizeof(const char*));
	*opciones5 = "FOTO.";
	*(opciones5 + 1) = "AYUDA.";
	*(opciones5 + 2) = "VERSION.";
	*(opciones5 + 3) = "BIG O.";
	*(opciones5 + 4) = "SALIR. \n\n";

	const char** opciones6 = (const char**)malloc(3 * sizeof(const char*));
	*opciones6 = "ABOUT.";
	*(opciones6 + 1) = "COMO FUNCIONA?.";
	*(opciones6 + 2) = "SUGERENCIAS E INTRUCCIONES. \n\n";

	const char** opciones7 = (const char**)malloc(6 * sizeof(const char*));
	*opciones7 = "PDF de empleados por cedula.";
	*(opciones7 + 1) = "PDF de empleados por nombre.";
	*(opciones7 + 2) = "PDF de empleados por apellido.";
	*(opciones7 + 3) = "PDF de empleados por nacimiento.";
	*(opciones7 + 4) = "PDF de empleados por sueldo.";
	*(opciones7 + 5) = "PDF de Registros. \n\n";

	const char** opciones8 = (const char**)malloc(3 * sizeof(const char*));
	*opciones8 = "Buscar por dia.";
	*(opciones8 + 1) = "Ver todo el registro.";
	*(opciones8 + 2) = "Salir.";

	const char** opciones9 = (const char**)malloc(36 * sizeof(const char*));
	*opciones9 = "insertarNodoCedulaBigO";
	*(opciones9 + 1) = "insertarNodoNombreBigO";
	*(opciones9 + 2) = "insertarNodoApellidoBigO";
	*(opciones9 + 3) = "insertarNodoSueldoBigO";
	*(opciones9 + 4) = "insertarNodoFechaBigO";
	*(opciones9 + 5) = "inOrdenBigO";
	*(opciones9 + 6) = "buscarBigO";
	*(opciones9 + 7) = "eliminarNodoBigO";
	*(opciones9 + 8) = "generarListaBigO";
	*(opciones9 + 9) = "insertarListaEmpleadosBigO";
	*(opciones9 + 10) = "eliminarListaEmpleadosBigO";
	*(opciones9 + 11) = "mostrarListaEmpleadosBigO";
	*(opciones9 + 12) = "buscarListaEmpleadosBigO";
	*(opciones9 + 13) = "dimencionListaEmpleadosBigO";
	*(opciones9 + 14) = "getPosicionListaEmpleadosBigO";
	*(opciones9 + 15) = "setPosicionListaEmpleadosBigO";
	*(opciones9 + 16) = "RecuperarListaEmpleadosBigO";
	*(opciones9 + 17) = "insertarListaRegistroBigO";
	*(opciones9 + 18) = "eliminarListaRegistroBigO";
	*(opciones9 + 19) = "mostrarListaRegistroBigO";
	*(opciones9 + 20) = "buscarListaRegistroBigO";
	*(opciones9 + 21) = "dimencionListaRegistroBigO";
	*(opciones9 + 22) = "getPosicionListaRegistroBigO";
	*(opciones9 + 23) = "setPosicionListaRegistroBigO";
	*(opciones9 + 24) = "RecuperarListaRegistroBigO";
	*(opciones9 + 25) = "insertarListaEnterosBigO";
	*(opciones9 + 26) = "dimencionListaEnterosBigO";
	*(opciones9 + 27) = "getPosicionListaEnterosBigO";
	*(opciones9 + 28) = "guardarListaRegistroBigO";
	*(opciones9 + 29) = "leerListaRegistroBigO";
	*(opciones9 + 30) = "leerListaRegistroFechaBigO";
	*(opciones9 + 31) = "guardarListaEmpleadosBigO";
	*(opciones9 + 32) = "leerListaEmpleadosBigO";
	*(opciones9 + 33) = "generarPDFBigO";
	*(opciones9 + 34) = "generarPDFRegisrtosBigO";
	*(opciones9 + 35) = "Salir";
	



	Empleado e;
	Administrador admin("u","c",e);
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int dia = ltm->tm_mday;
	int mes = 1 + ltm->tm_mon;
	int anio = 1900 + ltm->tm_year;

	listaRegistros = objArc.leerListaRegistro();
	listaRegistrosR = objArc.leerListaRegistro(anio, mes, dia);
	listaEmpleados = objArc.leerListaEmpleados();
	
	do {
		opcMP = menu(titulo, opciones, 3);
		switch (opcMP) {
		case 1: {
			std::system("cls");
			std::cout << "REGISTRO DE PERSONAL" << endl;

			string cedula;

			do {
				cedula = "";
				std::cout << "Ingrese la cedula: " << endl;
				cin >> cedula;

				repetirCedula = validacion.validarCedula(cedula);

				if (!(repetirCedula)) {
					std::system("cls");



					bool funcionTerminada = false;

					std::thread hilo([&]() {
						opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
						funcionTerminada = true;
						});

					int tiempoLimite = 5;

					for (int segundos = 0; segundos < tiempoLimite; ++segundos)
					{
						if (funcionTerminada)
						{
							break;
						}
						std::this_thread::sleep_for(std::chrono::seconds(1));
					}

					if (!funcionTerminada)
					{
						
						hilo.detach();

						opcMN = 2;
					}
					else
					{
						hilo.join();
					}

					switch (opcMN) {
					case 1: {
						std::system("cls");
						repetirCedula = false;

						break;
					}
					case 2: {
						std::system("cls");
						repetirCedula = true;

						break;
					}
					}

				}

			} while (!repetirCedula);

			if (validacion.validarCedula(cedula) && listaEmpleados->buscar(cedula)) {
				Registro reg;

				if (listaRegistros->getCabeza() == NULL || !listaRegistrosR->buscar(cedula)) {
					reg.setEmpleado(listaEmpleados->Recuperar(cedula));
				}
				else {
					reg = listaRegistrosR->Recuperar(cedula);
				}


				time_t now = time(0);
				tm* ltm = localtime(&now);

				int dia = ltm->tm_mday;
				int mes = 1 + ltm->tm_mon;
				int anio = 1900 + ltm->tm_year;
				int hora = ltm->tm_hour;
				int minutos = ltm->tm_min;
				int segundos = ltm->tm_sec;

				Fecha fechaActual(dia, mes, anio, hora, minutos, segundos);

				if (reg.getEntrada().getAnio() == 0) {
					reg.setEntrada(fechaActual);
				}
				else if (reg.getSalidaAlmuerzo().getAnio() == 0) {
					reg.setSalidaAlmuerzo(fechaActual);
				}
				else if (reg.getEntradaAlmuerzo().getAnio() == 0) {
					reg.setEntradaAlmuerzo(fechaActual);
				}
				else if (reg.getSalida().getAnio() == 0) {
					reg.setSalida(fechaActual);
				}
				else {
					std::cout << "YA A REALISADO LOS CUATRO REGISTROS" << endl;
				}
				if (listaRegistrosR->buscar(cedula)) {
					listaRegistrosR->Modificar(reg);
					listaRegistros->Modificar(reg);
				}
				else {
					listaRegistrosR->insertar(reg);
					listaRegistros->insertar(reg);
				}
				objArc.guardarListaRegistro(listaRegistros);
				std::system("pause");
			}
			else if (!(listaEmpleados->buscar(cedula)) && validacion.validarCedula(cedula)) {
				std::cout << "USTED NO SE ENCUENTRA REGISTRADO COMO EMPLEADO" << std::endl;
				std::system("pause");
			}
			
			break;
		}

		case 2: {
			std::system("cls");
			std::cout << "LOG IN" << endl;
			string usuario, contrasenia;
			do {
				usuario = "";
				std::cout << "Ingrese la usuario: " << endl;
				cin >> usuario;

				contrasenia = "";
				std::cout << "Ingrese la contrasenia: " << endl;
				cin >> contrasenia;

				
				repetirLI = usuario == admin.getUsuario() && contrasenia == admin.getContrasenia();

				
				if (!(repetirLI)) {
					std::system("cls");


					opcMN = menu("INGRESO NO VALIDO", opciones1, 2);
					switch (opcMN) {
					case 1: {
						std::system("cls");
						repetirLI = false;

						break;
					}
					case 2: {
						std::system("cls");
						repetirLI = true;

						break;
					}
					}


				}
				else {
					do {
						opcMN = menu("OPCIONES", opciones2, 9);
						switch (opcMN) {
						case 1: {
							std::system("cls");
							std::cout << "INGRESE LOS DATOS DEL EMPLEADO" << endl;
							string cedula,nombre,apellido;
							Fecha nacimiento;
							double sueldo;
							repetirCedula = false;
							do {
								cedula = "";
								std::cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);
								if (listaEmpleados->buscar(cedula)) {
									repetirCedula = false;
									std::cout << "CEDULA REPETIDA" << std::endl;
									std::system("pause");
								}

								if (!(repetirCedula)) {
									std::system("cls");


									opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
									
									switch (opcMN) {
									case 1: {
										std::system("cls");
										repetirCedula = false;

										break;
									}
									case 2: {
										std::system("cls");
										repetirCedula = true;

										break;
									}
									}

								}

							} while (!repetirCedula);

							if (validacion.validarCedula(cedula) && !listaEmpleados->buscar(cedula)) {
								do{
									std::system("cls");

									std::cout << "Ingrese el nombre: ";
									nombre = validacion.ingresarNombre();
								} while (nombre == "");

								do {
									std::system("cls");

									std::cout << "Ingrese el apellido: ";
									apellido = validacion.ingresarNombre();
								} while (apellido == "");

								
								std::cout << "Ingrese la fecha de nacimiento" << endl;
								nacimiento = validacion.ingresarFecha();
								do {
									std::cout << "Ingrese el sueldo: ";
									sueldo = validacion.ingresarDatosfloat();
									if (!(sueldo >= 450 && sueldo <= 7000)) {
										std::cout << "Ingrese un sueldo entre 450 y 7000 dolares" << endl;
									}
								} while (!(sueldo >= 450 && sueldo <= 7000));

								Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
								listaEmpleados->insertar(empleado);

								objArc.guardarListaEmpleados(listaEmpleados);
								std::system("pause");
							}


							
							break;
						}
						case 2: {
							std::system("cls");
							string cedula, nombre, apellido;
							Fecha nacimiento;
							double sueldo;
							repetirCedula = false;
							std::cout << "MODIFICAR DATOS EMPLEADO" << endl;
							std::cout << "Ingrese la cedula de la persona que desea modificar" << endl;
							do {
								cedula = "";
								std::cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									opcMN = menu("CEDULA NO VALIDA", opciones1, 2);

									

									switch (opcMN) {
									case 1: {
										std::system("cls");
										repetirCedula = false;

										break;
									}
									case 2: {
										std::system("cls");
										repetirCedula = true;

										break;
									}
									}
								}

							} while (!repetirCedula);

							if (validacion.validarCedula(cedula)) {
								if (!listaEmpleados->buscar(cedula)) {
									std::cout << "No se encutra la cedula en la lista de empleados" << endl;
									std::system("pause");
									break;
								}
								else {
									Empleado empleado = listaEmpleados->Recuperar(cedula);
									empleado.imprimir();
									std::system("pause");
									int op = menu("¿QUE ATRIBUTO DESEA CAMBIAR?", opciones3, 4);
									std::system("cls");
									switch (op)
									{
									case 1: {
										do {
											std::system("cls");

											std::cout << "Ingrese el nombre: ";
											nombre = validacion.ingresarNombre();
										} while (nombre == "");
										empleado.setNombre(nombre);
										break;
									}
									case 2: {
										do {
											std::system("cls");

											std::cout << "Ingrese el apellido: ";
											apellido = validacion.ingresarNombre();

										} while (apellido == "");
										empleado.setApellido(apellido);
										break;
									}
									case 3: {
										do {
											std::cout << "Ingrese el sueldo: ";
											sueldo = validacion.ingresarDatosfloat();
											if (!(sueldo >= 450 && sueldo <= 7000)) {
												std::cout << "Ingrese un sueldo entre 450 y 7000 dolares" << endl;
											}
										} while (!(sueldo >= 450 && sueldo <= 7000));
										empleado.setSalario(sueldo);
										break;
									}
									case 4: {
										break;
									}
									}
									listaEmpleados->Modificar(empleado);
								}

								
							}
							objArc.guardarListaEmpleados(listaEmpleados);
							std::system("pause");
							break;
						}
						case 3: {
							std::system("cls");
							std::cout << "ELIMINAR EMPLEADO" << endl;
							string cedula;
							do {
								cedula = "";
								std::cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									opcMN = menu("CEDULA NO VALIDA", opciones1, 2);

									switch (opcMN) {
									case 1: {
										std::system("cls");
										repetirCedula = false;

										break;
									}
									case 2: {
										std::system("cls");
										repetirCedula = true;

										break;
									}
									}
								}

							} while (!repetirCedula);

							if (validacion.validarCedula(cedula)) {
								if (!listaEmpleados->buscar(cedula)) {
									std::cout << "No se encutra la cedula en la lista de empleados" << endl;
									std::system("pause");
								}
								else {
									listaEmpleados->eliminar(cedula);
									objArc.guardarListaEmpleados(listaEmpleados);
								}
							}
							break;
							
						}
						case 4: {
							std::system("cls");
							std::cout << "BUSCAR EMPLEADO" << endl;
							Arbol arbol;
							Nodo* aux = arbol.getArbol();
							string cedula;
							do {
								cedula = "";
								std::cout << "Ingrese la cedula: " << endl;
								cin >> cedula;

								repetirCedula = validacion.validarCedula(cedula);

								if (!(repetirCedula)) {
									std::system("cls");

									opcMN = menu("CEDULA NO VALIDA", opciones1, 2);
									switch (opcMN) {
									case 1: {
										std::system("cls");
										repetirCedula = false;

										break;
									}
									case 2: {
										std::system("cls");
										repetirCedula = true;

										break;
									}
									}
								}

							} while (!repetirCedula);

							if (validacion.validarCedula(cedula)) {
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoCedula(aux, listaEmpleados->getPosicion(i));
								}
								arbol.buscar(aux, cedula);
								if(listaRegistrosR->Recuperar(cedula).getEntrada().getAnio() != 0)
									listaRegistrosR->Recuperar(cedula).imprimir();
							}

							
							std::system("pause");
							break;
						}
						case 5: {
							std::system("cls");
							int op = menu("Tipos de ordenamiento",opciones4,5);
							switch (op)
							{
							case 1: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoCedula(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 2: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoNombre(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 3: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoApellido(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 4: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoFecha(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							case 5: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoSueldo(aux, listaEmpleados->getPosicion(i));
								}
								arbol.inOrden(aux);
								std::system("pause");
								break;
							}
							}
							break;
						}
						case 6: {
							std::system("cls");
							ListaEmpleados* listaEmpleadosPDF = new ListaEmpleados();

							int op = menu("Generar PDF", opciones7, 6);
							switch (op)
							{
							case 1: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoCedula(aux, listaEmpleados->getPosicion(i));
								}
								listaEmpleadosPDF = arbol.generarLista(aux, listaEmpleadosPDF);
								objArc.generarPDF(listaEmpleadosPDF);

								std::system("pause");
								break;
							}
							case 2: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoNombre(aux, listaEmpleados->getPosicion(i));
								}
								listaEmpleadosPDF = arbol.generarLista(aux, listaEmpleadosPDF);

								objArc.generarPDF(listaEmpleadosPDF);

								std::system("pause");
								break;
							}
							case 3: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoApellido(aux, listaEmpleados->getPosicion(i));
								}
								listaEmpleadosPDF = arbol.generarLista(aux, listaEmpleadosPDF);

								objArc.generarPDF(listaEmpleadosPDF);

								std::system("pause");
								break;
							}
							case 4: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoFecha(aux, listaEmpleados->getPosicion(i));
								}
								listaEmpleadosPDF = arbol.generarLista(aux, listaEmpleadosPDF);

								objArc.generarPDF(listaEmpleadosPDF);

								std::system("pause");
								break;
							}
							case 5: {
								Arbol arbol;
								Nodo* aux = arbol.getArbol();
								for (int i = 0; i < listaEmpleados->dimencion(); i++) {
									arbol.insertarNodoSueldo(aux, listaEmpleados->getPosicion(i));
								}
								listaEmpleadosPDF = arbol.generarLista(aux, listaEmpleadosPDF);

								objArc.generarPDF(listaEmpleadosPDF);
								std::system("pause");
								break;
							}
							case 6: {
								objArc.generarPDFRegisrtos(listaRegistros);
								std::system("pause");
								break;
							}
							}
							break;




							break;
						}
						case 7: {
							std::system("cls");
							bool repR = true;
							int opRe;
							do {
								opRe = menu("OPCIONES", opciones8, 3);
								switch (opRe)
								{
								case 1: {
									std::system("cls");
									Fecha aux = validacion.ingresarFechaA();
									ListaRegistro* auxLista = new ListaRegistro();
									auxLista = objArc.leerListaRegistro(aux.getAnio(),aux.getMes(),aux.getDia());
									for (int i = 0; i < auxLista->dimencion(); i++) {
										std::cout << "############################################" << std::endl;
										auxLista->getPosicion(i).getEmpleado().imprimir();
										auxLista->getPosicion(i).imprimir();
										std::cout << "############################################" << std::endl;
									}
									std::system("pause");
									break;
								}
								case 2: {
									std::system("cls");
									ListaRegistro* auxLista = new ListaRegistro();
									auxLista = objArc.leerListaRegistro();
									for (int i = 0; i < auxLista->dimencion(); i++) {
										std::cout << "############################################" << std::endl;
										auxLista->getPosicion(i).getEmpleado().imprimir();
										auxLista->getPosicion(i).imprimir();
										std::cout << "############################################" << std::endl;
									}
									std::system("pause");
									break;
								}
								case 3: {
									std::system("cls");
									repR = false;
									break;
								}
								}

							} while (repR);

							break;
						}
						case 8: {
							std::system("cls");
							std::vector<std::string> filesToCopy = { "Empleado.txt", "Registro.txt" };
							std::string targetFolder = "BackUp";
							objArc.moverArchivos(filesToCopy, targetFolder);
							std::cout << "Back up hecho con exito" << std::endl;
							std::system("pause");
							break;
						}
						case 9: {
							std::system("cls");
							repetirL2 = true;

							break;
						}
						}
					} while (!repetirL2);
				}

			} while (!repetirLI);

			


			break;
		}
		case 3: {
			bool com = true;
			do {
				opcMN = menu("OPCIONES ADICIONALES", opciones5, 5);
				switch (opcMN) {
				case 1: {
					Archivos a;
					a.imprimirImagen();
					
					break;
				}
				case 2: {
					HINSTANCE result = ShellExecute(NULL, L"open", L"Ayuda.chm", NULL, NULL, SW_SHOWNORMAL);
					break;
				}
				case 3: {
					std::system("cls");
					std::cout << "************ VERSION ************" << endl;
					std::cout << "ProyectoRegistroPersonalV3.0" << endl;
					std::system("pause");

					break;
				}
				case 4: {
					bool conti = true;
					do {
						std::system("cls");
						op = menu("BIG O", opciones9, 36);


						switch (op) {
						case 1: {
							bigO.insertarNodoCedulaBigO();
							break;
						}
						case 2: {
							bigO.insertarNodoNombreBigO();

							break;
						}
						case 3: {
							bigO.insertarNodoApellidoBigO();

							break;
						}
						case 4: {
							bigO.insertarNodoSueldoBigO();

							break;
						}
						case 5: {
							bigO.insertarNodoFechaBigO();

							break;
						}
						case 6: {
							bigO.inOrdenBigO();

							break;
						}
						case 7: {
							bigO.buscarBigO();

							break;
						}
						case 8: {
							bigO.eliminarNodoBigO();

							break;
						}
						case 9: {
							bigO.generarListaBigO();

							break;
						}
						case 10: {
							bigO.insertarListaEmpleadosBigO();

							break;
						}
						case 11: {
							bigO.eliminarListaEmpleadosBigO();

							break;
						}
						case 12: {
							bigO.mostrarListaEmpleadosBigO();

							break;
						}
						case 13: {
							bigO.buscarListaEmpleadosBigO();

							break;
						}
						case 14: {
							bigO.dimencionListaEmpleadosBigO();

							break;
						}
						case 15: {
							bigO.getPosicionListaEmpleadosBigO();

							break;
						}
						case 16: {
							bigO.setPosicionListaEmpleadosBigO();

							break;
						}
						case 17: {
							bigO.RecuperarListaEmpleadosBigO();

							break;
						}
						case 18: {
							bigO.insertarListaRegistroBigO();

							break;
						}
						case 19: {
							bigO.eliminarListaRegistroBigO();

							break;
						}
						case 20: {
							bigO.mostrarListaRegistroBigO();

							break;
						}
						case 21: {
							bigO.buscarListaRegistroBigO();

							break;
						}
						case 22: {
							bigO.dimencionListaRegistroBigO();

							break;
						}
						case 23: {
							bigO.getPosicionListaRegistroBigO();

							break;
						}
						case 24: {
							bigO.setPosicionListaRegistroBigO();

							break;
						}
						case 25: {
							bigO.RecuperarListaRegistroBigO();

							break;
						}
						case 26: {
							bigO.insertarListaEnterosBigO();

							break;
						}
						case 27: {
							bigO.dimencionListaEnterosBigO();

							break;
						}
						case 28: {
							bigO.getPosicionListaEnterosBigO();

							break;
						}
						case 29: {
							bigO.guardarListaRegistroBigO();

							break;
						}
						case 30: {
							bigO.leerListaRegistroBigO();

							break;
						}
						case 31: {
							bigO.leerListaRegistroFechaBigO();

							break;
						}
						case 32: {
							bigO.guardarListaEmpleadosBigO();

							break;
						}
						case 33: {
							bigO.leerListaEmpleadosBigO();

							break;
						}
						case 34: {
							bigO.generarPDFBigO();

							break;
						}
						case 35: {
							bigO.generarPDFRegisrtosBigO();

							break;
						}
						case 36: {
							conti = false;
							break;
						}
						}
					} while (conti);
					break;
				}
				case 5: {
					com = false;
					break;
				}
				}
			} while (com);

			

			break;
		}
		}
	} while (repetir);
}


/**
*
* Controla los punteros de movimiento en el menu de opciones
*
* @param const char* titulo. El titulo de la pestaña del menu
* @param const char* opciones[]. Un arreglo con las opciones del menu
* @param int n. lA opciones que quiere que se inprima en la pantalla
*
* @return int. La opcion seleccionada
**/
int Menu::menu(const char* titulo, const char** opciones, int n) {
	int opcSeleccionada = 1;
	int tecla;
	bool repetir = true;
	do {
		std::system("cls");
		gotoxy(5, 3 + opcSeleccionada); std::cout << "-->";
		gotoxy(15, 2); std::cout << titulo;
		for (int i = 0; i < n; i++) {
			if (i + 1 == opcSeleccionada) {
				gotoxy(10, 4 + i); std::cout << "\033[47m\033[30m" << i + 1 << "." << *(opciones + i) << "\033[0m";
			}
			else {
				gotoxy(10, 4 + i); std::cout << i + 1 << "." << *(opciones + i);
			}
		}

		do {
			tecla = _getch();
		} while (tecla != Tecla_Arriba && tecla != Tecla_Abajo && tecla != Enter);

		switch (tecla)
		{
		case Tecla_Arriba:
			opcSeleccionada--;
			if (opcSeleccionada < 1) {
				opcSeleccionada = n;
			}
			break;
		case Tecla_Abajo:
			opcSeleccionada++;
			if (opcSeleccionada > n) {
				opcSeleccionada = 1;
			}
			break;
		case Enter:
			repetir = false;
			break;
		}
	} while (repetir);


	return opcSeleccionada;

}

/**
*
* Gestiona la posicion donde se imprime lineas de texto dentro de la consola
*
* @param int x. Posicicion en x.
* @param int y. Posicicion en y.
*
**/
void Menu::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


