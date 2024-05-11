/***********************************************************************
 * Module:  BigO.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class BigO
 ***********************************************************************/
#include "BigO.h"

/**
* Guarda dentro de un .txt los puntos para graficar el bigO
*
* @param ListaEnteros datos, ListaEnteros duracion
*
* @return void
**/
void BigO::guardar(ListaEnteros datos, ListaEnteros duracion) {
    std::ofstream archivo("BIG O.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < datos.dimencion(); i++) {
            archivo << datos.getPosicion(i) << " " << duracion.getPosicion(i) << std::endl;
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

/**
* Grafica los puntos dentro de un plano carteciano utilizando R, Matlab, C++
*
* @return void
**/
void BigO::graficar() {
    ifstream archivo("BIG O.txt");
    ofstream gnuplot("graficoC++.plt");
    gnuplot << "plot 'BIG O.txt' with linespoints" << endl;

    int x, y;
    while (archivo >> x >> y) {
        gnuplot << x << " " << y << endl;
    }
    archivo.close();
    gnuplot.close();
    //std::system("gnuplot graficoC.plt");

    std::string cmd = "Rscript Grafico.R > graficos.Rout";
    int result = std::system(cmd.c_str());

    std::system("matlab -batch \"Grafico\"");

    std::system("graficoC++.plt");
    std::system("graficoR.pdf");
    std::system("graficoMathlab.pdf");

    std::system("pause");
}

/**
* Genera y grafica los puntos de la funcion insertarNodoCedula() de la clase Arboles
*
* @return void
**/
void BigO::insertarNodoCedulaBigO() {
    
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;


    ListaEnteros datos;
    ListaEnteros duracion;

    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            Arbol arbol;
            Nodo* aux = arbol.getArbol();
            Empleado empleadoArbol;
            empleadoArbol = listaEmpleados->getPosicion(j);
            arbol.insertarNodoCedula(aux, empleadoArbol);

        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion insertarNodoNombre() de la clase Arboles
*
* @return void
**/
void BigO::insertarNodoNombreBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;

    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";



    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);
        
        Arbol arbol;
        Nodo* aux = arbol.getArbol();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            
            Empleado empleadoArbol;
            empleadoArbol = listaEmpleados->getPosicion(j);
            arbol.insertarNodoNombre(aux, empleadoArbol);

        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion insertarNodoApellid() de la clase Arboles
*
* @return void
**/
void BigO::insertarNodoApellidoBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;

    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        Arbol arbol;
        Nodo* aux = arbol.getArbol();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            
            Empleado empleadoArbol;
            empleadoArbol = listaEmpleados->getPosicion(j);
            arbol.insertarNodoApellido(aux, empleadoArbol);

        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion insertarNodoSueldo() de la clase Arboles
*
* @return void
**/
void BigO::insertarNodoSueldoBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;

    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        Arbol arbol;
        Nodo* aux = arbol.getArbol();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            
            Empleado empleadoArbol;
            empleadoArbol = listaEmpleados->getPosicion(j);
            arbol.insertarNodoSueldo(aux, empleadoArbol);

        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion insertarNodoFecha() de la clase Arboles
*
* @return void
**/
void BigO::insertarNodoFechaBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;

    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        Arbol arbol;
        Nodo* aux = arbol.getArbol();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            
            Empleado empleadoArbol;
            empleadoArbol = listaEmpleados->getPosicion(j);
            arbol.insertarNodoFecha(aux, empleadoArbol);

        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion inOrden() de la clase Arboles
*
* @return void
**/
void BigO::inOrdenBigO() {
    Arbol arbol;
    Nodo* aux = arbol.getArbol();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        arbol.insertarNodoFecha(aux, empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        arbol.inOrden(aux);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion buscar() de la clase Arboles
*
* @return void
**/
void BigO::buscarBigO() {
    Arbol arbol;
    Nodo* aux = arbol.getArbol();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {

        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        arbol.insertarNodoFecha(aux, empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        arbol.buscar(aux,cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion eliminarNodo() de la clase Arboles
*
* @return void
**/
void BigO::eliminarNodoBigO() {
    Arbol arbol;
    Nodo* aux = arbol.getArbol();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        arbol.insertarNodoFecha(aux, empleado);

    }

    
    
    for (int i = 99; i >= 0; i--) {
        cedula = std::to_string(i);

        auto inicio = std::chrono::high_resolution_clock::now();
        arbol.eliminarNodo(aux, cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
        datos.insertar(i+1);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion generarLista() de la clase Arboles
*
* @return void
**/
void BigO::generarListaBigO() {
    Arbol arbol;
    Nodo* aux = arbol.getArbol();
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        arbol.insertarNodoFecha(aux, empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        arbol.generarLista(aux, listaEmpleados);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();

}

/**
* Genera y grafica los puntos de la funcion insertar() de la clase ListaEmpleados
*
* @return void
**/
void BigO::insertarListaEmpleadosBigO() {

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        ListaEmpleados* lista = new ListaEmpleados();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEmpleados->dimencion(); j++) {
            Empleado nuevoEmpleado;
            nuevoEmpleado = listaEmpleados->getPosicion(j);
            lista->insertar(nuevoEmpleado);
        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion eliminar() de la clase ListaEmpleados
*
* @return void
**/
void BigO::eliminarListaEmpleadosBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);
    }
    
    for (int i = 99; i >= 0; i--) {
        cedula = std::to_string(i);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->eliminar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(i+1);
        duracion.insertar(tiempo);  
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion mostrar() de la clase ListaEmpleados
*
* @return void
**/
void BigO::mostrarListaEmpleadosBigO() {

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->mostrar();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion buscar() de la clase ListaEmpleados
*
* @return void
**/
void BigO::buscarListaEmpleadosBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        ListaEmpleados* lista = new ListaEmpleados();

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->buscar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion dimencion() de la clase ListaEmpleados
*
* @return void
**/
void BigO::dimencionListaEmpleadosBigO() {

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);


        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->dimencion();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion getPosicion() de la clase ListaEmpleados
*
* @return void
**/
void BigO::getPosicionListaEmpleadosBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->getPosicion(i);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion setPosicion() de la clase ListaEmpleados
*
* @return void
**/
void BigO::setPosicionListaEmpleadosBigO() {
    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEmpleados->setPosicion(empleado,i);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion Recuperar() de la clase ListaEmpleados
*
* @return void
**/
void BigO::RecuperarListaEmpleadosBigO() {

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        ListaEmpleados* lista = new ListaEmpleados();

        auto inicio = std::chrono::high_resolution_clock::now();
        Empleado aux = listaEmpleados->Recuperar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion insertar() de la clase ListaRegistro
*
* @return void
**/
void BigO::insertarListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1,1,1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(empleado);

        ListaRegistro* lista = new ListaRegistro();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaRegistro->dimencion(); j++) {
            Registro nuevoRegistro;
            nuevoRegistro = listaRegistro->getPosicion(j);
            lista->insertar(nuevoRegistro);
        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion eliminar() de la clase ListaRegistro
*
* @return void
**/
void BigO::eliminarListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);
    }

    for (int i = 99; i >= 0; i--) {
        cedula = std::to_string(i);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->eliminar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(i + 1);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion mostrar() de la clase ListaRegistro
*
* @return void
**/
void BigO::mostrarListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);


        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->mostrar();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion buscar() de la clase ListaRegistro
*
* @return void
**/
void BigO::buscarListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);

        ListaEmpleados* lista = new ListaEmpleados();

        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->buscar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion dimencion() de la clase ListaRegistro
*
* @return void
**/
void BigO::dimencionListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);


        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->dimencion();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion getPosicion() de la clase ListaRegistro
*
* @return void
**/
void BigO::getPosicionListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->getPosicion(i);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion setPosicion() de la clase ListaRegistro
*
* @return void
**/
void BigO::setPosicionListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 1000; i++) {
        cedula = std::to_string(i);
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaRegistro->setPosicion(empleado, i);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion Recuperar() de la clase ListaRegistro
*
* @return void
**/
void BigO::RecuperarListaRegistroBigO() {
    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        cedula = std::to_string(i);

        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(registro);

        ListaEmpleados* lista = new ListaEmpleados();

        auto inicio = std::chrono::high_resolution_clock::now();
        Registro aux = listaRegistro->Recuperar(cedula);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion insertar() de la clase ListaEnteros
*
* @return void
**/
void BigO::insertarListaEnterosBigO() {
    ListaEnteros* listaEnteros = new ListaEnteros();
    int contDatos = 0;

    ListaEnteros datos;
    ListaEnteros duracion;

    for (int i = 0; i < 100; i++) {
        contDatos++;
        listaEnteros->insertar(i);

        ListaEnteros* lista = new ListaEnteros();

        auto inicio = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < listaEnteros->dimencion(); j++) {
            int nuevoRegistro;
            nuevoRegistro = listaEnteros->getPosicion(j);
            lista->insertar(j);
        }
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion dimencion() de la clase ListaEnteros
*
* @return void
**/
void BigO::dimencionListaEnterosBigO() {
    ListaEnteros* listaEnteros = new ListaEnteros();
    int contDatos = 0;

    ListaEnteros datos;
    ListaEnteros duracion;

    for (int i = 0; i < 1000; i++) {
        contDatos++;
        listaEnteros->insertar(i);


        auto inicio = std::chrono::high_resolution_clock::now();
        listaEnteros->dimencion();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion getPosicion() de la clase ListaEnteros
*
* @return void
**/
void BigO::getPosicionListaEnterosBigO() {
    ListaEnteros* listaEnteros = new ListaEnteros();
    int contDatos = 0;

    ListaEnteros datos;
    ListaEnteros duracion;

    for (int i = 0; i < 1000; i++) {
        contDatos++;
        listaEnteros->insertar(i);

        auto inicio = std::chrono::high_resolution_clock::now();
        listaEnteros->getPosicion(i);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion guardarListaRegistro() de la clase Archivos
*
* @return void
**/
void BigO::guardarListaRegistroBigO() {
    Archivos arc;
    ListaRegistro* listaRegistroBackUp = new ListaRegistro();
    listaRegistroBackUp = arc.leerListaRegistro();

    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(empleado);


        auto inicio = std::chrono::high_resolution_clock::now();
        arc.guardarListaRegistro(listaRegistro);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    arc.guardarListaRegistro(listaRegistroBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion leerListaRegistro() de la clase Archivos
*
* @return void
**/
void BigO::leerListaRegistroBigO() {
    Archivos arc;
    ListaRegistro* listaRegistroBackUp = new ListaRegistro();
    listaRegistroBackUp = arc.leerListaRegistro();

    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(empleado);

        arc.guardarListaRegistro(listaRegistro);

        auto inicio = std::chrono::high_resolution_clock::now();
        arc.leerListaRegistro();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    arc.guardarListaRegistro(listaRegistroBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion LeerListaRegistroFecha() de la clase Archivos
*
* @return void
**/
void BigO::leerListaRegistroFechaBigO() {
    Archivos arc;
    ListaRegistro* listaRegistroBackUp = new ListaRegistro();
    listaRegistroBackUp = arc.leerListaRegistro();

    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(empleado);

        arc.guardarListaRegistro(listaRegistro);

        auto inicio = std::chrono::high_resolution_clock::now();
        arc.leerListaRegistro(1,1,1);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    arc.guardarListaRegistro(listaRegistroBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion guardarListaEmpleados() de la clase Archivos
*
* @return void
**/
void BigO::guardarListaEmpleadosBigO() {
    Archivos arc;
    ListaEmpleados* listaEmpleadosBackUp = new ListaEmpleados();
    listaEmpleadosBackUp = arc.leerListaEmpleados();

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);


        auto inicio = std::chrono::high_resolution_clock::now();
        arc.guardarListaEmpleados(listaEmpleados);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    arc.guardarListaEmpleados(listaEmpleadosBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion leerListaEmpleados() de la clase Archivos
*
* @return void
**/
void BigO::leerListaEmpleadosBigO() {
    Archivos arc;
    ListaEmpleados* listaEmpleadosBackUp = new ListaEmpleados();
    listaEmpleadosBackUp = arc.leerListaEmpleados();



    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        arc.guardarListaEmpleados(listaEmpleados);

        auto inicio = std::chrono::high_resolution_clock::now();
        arc.leerListaEmpleados();
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);
    }

    arc.guardarListaEmpleados(listaEmpleadosBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion generarPDF() de la clase Archivos
*
* @return void
**/
void BigO::generarPDFBigO() {
    Archivos arc;
    ListaEmpleados* listaEmpleadosBackUp = new ListaEmpleados();
    listaEmpleadosBackUp = arc.leerListaEmpleados();

    ListaEmpleados* listaEmpleados = new ListaEmpleados();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        contDatos++;
        listaEmpleados->insertar(empleado);

        auto inicio = std::chrono::high_resolution_clock::now();
        arc.generarPDF(listaEmpleados);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    arc.generarPDF(listaEmpleadosBackUp);
    guardar(datos, duracion);

    graficar();
}

/**
* Genera y grafica los puntos de la funcion generarPDFRegisrtos() de la clase Archivos
*
* @return void
**/
void BigO::generarPDFRegisrtosBigO(){
    Archivos arc;
    ListaRegistro* listaRegistroBackUp = new ListaRegistro();
    listaRegistroBackUp = arc.leerListaRegistro();

    ListaRegistro* listaRegistro = new ListaRegistro();

    string cedula, nombre, apellido;
    Fecha nacimiento(1, 1, 1);
    Fecha entrada(1, 1, 1);
    Fecha salidaAlmauerzo(1, 1, 1);
    Fecha entradaAlmuerzo(1, 1, 1);
    Fecha salida(1, 1, 1);

    double sueldo = 0.0;

    ListaEnteros datos;
    ListaEnteros duracion;
    int contDatos = 0;

    cedula = "------";
    nombre = "------";
    apellido = "------";

    for (int i = 0; i < 100; i++) {
        Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
        Registro registro(empleado, entrada, salidaAlmauerzo, entradaAlmuerzo, salida);
        contDatos++;
        listaRegistro->insertar(empleado);


        auto inicio = std::chrono::high_resolution_clock::now();
        arc.generarPDFRegisrtos(listaRegistro);
        auto fin = std::chrono::high_resolution_clock::now();
        int tiempo = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

        datos.insertar(contDatos);
        duracion.insertar(tiempo);

    }

    arc.generarPDFRegisrtos(listaRegistroBackUp);
    guardar(datos, duracion);

    graficar();
}