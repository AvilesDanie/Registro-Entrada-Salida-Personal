/***********************************************************************
 * Module:  Archivos.cpp
 * Authors:  Aviles, Reyes
 * Modified: miércoles, 22 de junio de 2023
 * Purpose: Declaration of the class Archivos
 ***********************************************************************/
#include "Archivos.h"
#include <ctime>
#include <direct.h>
#include <hpdf.h>
#include <hpdf.h>

/**
* Genera el pdf en base a una lista de empleados.
*
* @param ListaEmpleados* empleados
*
* @return void
**/
void Archivos::generarPDF( ListaEmpleados* empleados) {
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;

    pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Error: No se pudo inicializar la librería Haru." << std::endl;
        return;
    }

    page = HPDF_AddPage(pdf);

    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont(pdf, "Helvetica", NULL);

    const int cellWidth = 100;
    const int cellHeight = 20;

    int startX = 50;
    int startY = HPDF_Page_GetHeight(page) - 50;

    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, font, 12);
    HPDF_Page_TextOut(page, startX, startY, "Cedula");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Nombre");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Apellido");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Nacimiento");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Salario");
    HPDF_Page_EndText(page);

    HPDF_Page_MoveTo(page, startX, startY - cellHeight);
    HPDF_Page_LineTo(page, startX + 5 * cellWidth, startY - cellHeight);
    HPDF_Page_Stroke(page);

    HPDF_Page_SetFontAndSize(page, font, 10);

    int numEmpleados = empleados->dimencion();
    for (int i = 0; i < numEmpleados; i++) {
        Empleado empleado = empleados->getPosicion(i);

        HPDF_Page_BeginText(page);
        HPDF_Page_MoveTextPos(page, startX, startY - (i + 2) * cellHeight); 
        HPDF_Page_ShowText(page, empleado.getCedula().c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        HPDF_Page_ShowText(page, empleado.getNombre().c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        HPDF_Page_ShowText(page, empleado.getApellido().c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        std::string fechaNacimiento = std::to_string(empleado.getFecha().getDia()) + "/" + std::to_string(empleado.getFecha().getMes()) + "/" + std::to_string(empleado.getFecha().getAnio());
        HPDF_Page_ShowText(page, fechaNacimiento.c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        HPDF_Page_ShowText(page, std::to_string(empleado.getSalario()).c_str());
        HPDF_Page_EndText(page);

        HPDF_Page_MoveTo(page, startX, startY - (i + 3) * cellHeight);
        HPDF_Page_LineTo(page, startX + 5 * cellWidth, startY - (i + 3) * cellHeight);
        HPDF_Page_Stroke(page);
    }

    HPDF_SaveToFile(pdf, "Lista de Empleados.pdf");

    HPDF_Free(pdf);
}

/**
* Genera el pdf en base a una lista de registros.
*
* @param ListaRegistro* registros
*
* @return void
**/
void Archivos::generarPDFRegisrtos(ListaRegistro* registros) {
    HPDF_Doc pdf;
    HPDF_Page page;
    HPDF_Font font;

    pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Error: No se pudo inicializar la librería Haru." << std::endl;
        return;
    }

    page = HPDF_AddPage(pdf);

    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont(pdf, "Helvetica", NULL);

    const int cellWidth = 100;
    const int cellHeight = 20;

    int startX = 10;
    int startY = HPDF_Page_GetHeight(page) - 50;

    HPDF_Page_BeginText(page);
    HPDF_Page_SetFontAndSize(page, font, 12);
    HPDF_Page_TextOut(page, startX, startY, "Nombre");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Apellido");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Entrada");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Salida Almuelzo");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Entrada Almuerzo");
    HPDF_Page_MoveTextPos(page, cellWidth, 0);
    HPDF_Page_ShowText(page, "Salida");
    HPDF_Page_EndText(page);

    HPDF_Page_MoveTo(page, startX, startY - cellHeight);
    HPDF_Page_LineTo(page, startX + 6 * cellWidth, startY - cellHeight);
    HPDF_Page_Stroke(page);

    HPDF_Page_SetFontAndSize(page, font, 10);

    int numEmpleados = registros->dimencion();
    for (int i = 0; i < numEmpleados; i++) {
        Registro registro = registros->getPosicion(i);

        HPDF_Page_BeginText(page);
        HPDF_Page_MoveTextPos(page, startX, startY - (i + 2) * cellHeight);
        HPDF_Page_ShowText(page, registro.getEmpleado().getNombre().c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        HPDF_Page_ShowText(page, registro.getEmpleado().getApellido().c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);

        std::string fechaEntrada = std::to_string(registro.getEntrada().getDia()) + "/" + std::to_string(registro.getEntrada().getMes()) + "/" + std::to_string(registro.getEntrada().getAnio()) + " - " + std::to_string(registro.getEntrada().getHora()) + ":" + std::to_string(registro.getEntrada().getMinutos());
        HPDF_Page_ShowText(page, fechaEntrada.c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);
        
        std::string fechaSalidaAlmurerso = std::to_string(registro.getSalidaAlmuerzo().getDia()) + "/" + std::to_string(registro.getSalidaAlmuerzo().getMes()) + "/" + std::to_string(registro.getSalidaAlmuerzo().getAnio()) + " - " + std::to_string(registro.getSalidaAlmuerzo().getHora()) + ":" + std::to_string(registro.getSalidaAlmuerzo().getMinutos());
        HPDF_Page_ShowText(page, fechaSalidaAlmurerso.c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);

        std::string fechaEntradaAlmurerso = std::to_string(registro.getEntradaAlmuerzo().getDia()) + "/" + std::to_string(registro.getEntradaAlmuerzo().getMes()) + "/" + std::to_string(registro.getEntradaAlmuerzo().getAnio()) + " - " + std::to_string(registro.getEntradaAlmuerzo().getHora()) + ":" + std::to_string(registro.getEntradaAlmuerzo().getMinutos());
        HPDF_Page_ShowText(page, fechaEntradaAlmurerso.c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);

        std::string fechaSalida = std::to_string(registro.getSalida().getDia()) + "/" + std::to_string(registro.getSalida().getMes()) + "/" + std::to_string(registro.getSalida().getAnio()) + " - " + std::to_string(registro.getSalida().getHora()) + ":" + std::to_string(registro.getSalida().getMinutos());
        HPDF_Page_ShowText(page, fechaSalida.c_str());
        HPDF_Page_MoveTextPos(page, cellWidth, 0);




        HPDF_Page_EndText(page);

        HPDF_Page_MoveTo(page, startX, startY - (i + 3) * cellHeight);
        HPDF_Page_LineTo(page, startX + 6 * cellWidth, startY - (i + 3) * cellHeight);
        HPDF_Page_Stroke(page);
    }
    HPDF_SaveToFile(pdf, "Lista de Registro.pdf");

    HPDF_Free(pdf);
}


/**
* Copia los archivos de una ubicacion a otra ubicacion dentro del directorio seleccionado
*
* @param const std::string& sourceFile, const std::string& targetFile
*
* @return void
**/
void Archivos::copiarArchivos(const std::string& sourceFile, const std::string& targetFile) {
    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream target(targetFile, std::ios::binary);
    target << source.rdbuf();
}

/**
* Crea una carpeta en un directorio seleccionado
*
* @param const std::string& folderPath
*
* @return void
**/
void Archivos::crearCarpeta(const std::string& folderPath) {
    _mkdir(folderPath.c_str());
}

/**
* Realiza el back up de los archivos selecionados
*
* @param const std::vector<std::string>& fileNames, const std::string& targetFolder
*
* @return void
**/
void Archivos::moverArchivos(const std::vector<std::string>& fileNames, const std::string& targetFolder) {
    std::time_t now = std::time(nullptr);
    std::tm tm_now;
    localtime_s(&tm_now, &now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", &tm_now);
    std::string folderName = targetFolder + "/" + buffer;

    crearCarpeta(folderName);

    for (const auto& fileName : fileNames) {
        std::string targetFilePath =  folderName + "/" + fileName;
        copiarArchivos(fileName, targetFilePath);
    }

}

/**
* Guarda dentro de un .txt una lista de registros
*
* @param ListaRegistro* lista
*
* @return void
**/
void Archivos::guardarListaRegistro(ListaRegistro* lista) {
    std::ofstream archivo("Registro.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < lista->dimencion(); i++) {
            archivo << lista->getPosicion(i).getEmpleado().getNombre() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getApellido() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getCedula() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getDia() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getMes() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getFecha().getAnio() << ",";
            archivo << lista->getPosicion(i).getEmpleado().getSalario() << ",";
            archivo << lista->getPosicion(i).getEntrada().getDia() << ",";
            archivo << lista->getPosicion(i).getEntrada().getMes() << ",";
            archivo << lista->getPosicion(i).getEntrada().getAnio() << ",";
            archivo << lista->getPosicion(i).getEntrada().getHora() << ",";
            archivo << lista->getPosicion(i).getEntrada().getMinutos() << ",";
            archivo << lista->getPosicion(i).getEntrada().getSegundos() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getDia() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getMes() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getHora() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getMinutos() << ",";
            archivo << lista->getPosicion(i).getSalidaAlmuerzo().getSegundos() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getDia() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getMes() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getAnio() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getHora() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getMinutos() << ",";
            archivo << lista->getPosicion(i).getEntradaAlmuerzo().getSegundos() << ",";
            archivo << lista->getPosicion(i).getSalida().getDia() << ",";
            archivo << lista->getPosicion(i).getSalida().getMes() << ",";
            archivo << lista->getPosicion(i).getSalida().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalida().getHora() << ",";
            archivo << lista->getPosicion(i).getSalida().getMinutos() << ",";
            archivo << lista->getPosicion(i).getSalida().getSegundos() << endl;
        }
        archivo.close();
        std::cout << "Lista de registros guardada exitosamente en Registro.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para escribir" << std::endl;
    }
}

/**
* Lee un .txt de lista de registros
*
* @return void
**/
ListaRegistro* Archivos::leerListaRegistro() {
    ListaRegistro* lista = new ListaRegistro();
    std::ifstream archivo("Registro.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na, ed, em, ea, eh, emi, es, sad, sam, saa, sah, sami, sas, ead, eam, eaa, eah, eami, eas, sd, sm, sa, sh, smi, ss;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            size_t coma_pos7 = linea.find(",", coma_pos6 + 1);
            size_t coma_pos8 = linea.find(",", coma_pos7 + 1);
            size_t coma_pos9 = linea.find(",", coma_pos8 + 1);
            size_t coma_pos10 = linea.find(",", coma_pos9 + 1);
            size_t coma_pos11 = linea.find(",", coma_pos10 + 1);
            size_t coma_pos12 = linea.find(",", coma_pos11 + 1);
            size_t coma_pos13 = linea.find(",", coma_pos12 + 1);
            size_t coma_pos14 = linea.find(",", coma_pos13 + 1);
            size_t coma_pos15 = linea.find(",", coma_pos14 + 1);
            size_t coma_pos16 = linea.find(",", coma_pos15 + 1);
            size_t coma_pos17 = linea.find(",", coma_pos16 + 1);
            size_t coma_pos18 = linea.find(",", coma_pos17 + 1);
            size_t coma_pos19 = linea.find(",", coma_pos18 + 1);
            size_t coma_pos20 = linea.find(",", coma_pos19 + 1);
            size_t coma_pos21 = linea.find(",", coma_pos20 + 1);
            size_t coma_pos22 = linea.find(",", coma_pos21 + 1);
            size_t coma_pos23 = linea.find(",", coma_pos22 + 1);
            size_t coma_pos24 = linea.find(",", coma_pos23 + 1);
            size_t coma_pos25 = linea.find(",", coma_pos24 + 1);
            size_t coma_pos26 = linea.find(",", coma_pos25 + 1);
            size_t coma_pos27 = linea.find(",", coma_pos26 + 1);
            size_t coma_pos28 = linea.find(",", coma_pos27 + 1);
            size_t coma_pos29 = linea.find(",", coma_pos28 + 1);
            size_t coma_pos30 = linea.find(",", coma_pos29 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1, coma_pos7 - coma_pos6 - 1));
                ed = std::stoi(linea.substr(coma_pos7 + 1, coma_pos8 - coma_pos7 - 1));
                em = std::stoi(linea.substr(coma_pos8 + 1, coma_pos9 - coma_pos8 - 1));
                ea = std::stoi(linea.substr(coma_pos9 + 1, coma_pos10 - coma_pos9 - 1));
                eh = std::stoi(linea.substr(coma_pos10 + 1, coma_pos11 - coma_pos10 - 1));
                emi = std::stoi(linea.substr(coma_pos11 + 1, coma_pos12 - coma_pos11 - 1));
                es = std::stoi(linea.substr(coma_pos12 + 1, coma_pos13 - coma_pos12 - 1));
                sad = std::stoi(linea.substr(coma_pos13 + 1, coma_pos14 - coma_pos13 - 1));
                sam = std::stoi(linea.substr(coma_pos14 + 1, coma_pos15 - coma_pos14 - 1));
                saa = std::stoi(linea.substr(coma_pos15 + 1, coma_pos16 - coma_pos15 - 1));
                sah = std::stoi(linea.substr(coma_pos16 + 1, coma_pos17 - coma_pos16 - 1));
                sami = std::stoi(linea.substr(coma_pos17 + 1, coma_pos18 - coma_pos17 - 1));
                sas = std::stoi(linea.substr(coma_pos18 + 1, coma_pos19 - coma_pos18 - 1));
                ead = std::stoi(linea.substr(coma_pos19 + 1, coma_pos20 - coma_pos19 - 1));
                eam = std::stoi(linea.substr(coma_pos20 + 1, coma_pos21 - coma_pos20 - 1));
                eaa = std::stoi(linea.substr(coma_pos21 + 1, coma_pos22 - coma_pos21 - 1));
                eah = std::stoi(linea.substr(coma_pos22 + 1, coma_pos23 - coma_pos22 - 1));
                eami = std::stoi(linea.substr(coma_pos23 + 1, coma_pos24 - coma_pos23 - 1));
                eas = std::stoi(linea.substr(coma_pos24 + 1, coma_pos25 - coma_pos24 - 1));
                sd = std::stoi(linea.substr(coma_pos25 + 1, coma_pos26 - coma_pos25 - 1));
                sm = std::stoi(linea.substr(coma_pos26 + 1, coma_pos27 - coma_pos26 - 1));
                sa = std::stoi(linea.substr(coma_pos27 + 1, coma_pos28 - coma_pos27 - 1));
                sh = std::stoi(linea.substr(coma_pos28 + 1, coma_pos29 - coma_pos28 - 1));
                smi = std::stoi(linea.substr(coma_pos29 + 1, coma_pos30 - coma_pos29 - 1));
                ss = std::stoi(linea.substr(coma_pos30 + 1));
                Fecha nacimiento(nd, nm, na);
                Fecha entrada(ed, em, ea,eh,emi,es);
                Fecha salidaAlmuerzo(sad, sam, saa,sah,sami,sas);
                Fecha entradoAlmuerzo(ead,eam,eaa,eah,eami,eas);
                Fecha salida(sd, sm, sa,sh,smi,ss);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
                Registro registro(empleado, entrada, salidaAlmuerzo, entradoAlmuerzo, salida);
                
                lista->insertar(registro);
            }
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para leer" << std::endl;
    }
    return lista;
}

/**
* Lee y filtra por fecha un .txt de lista de registros
*
* @param int anio, int mes, int dia
* 
* @return void
**/
ListaRegistro* Archivos::leerListaRegistro(int anio, int mes, int dia) {
    ListaRegistro* lista = new ListaRegistro();
    std::ifstream archivo("Registro.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na, ed, em, ea, eh, emi, es, sad, sam, saa, sah, sami, sas, ead, eam, eaa, eah, eami, eas, sd, sm, sa, sh, smi, ss;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            size_t coma_pos7 = linea.find(",", coma_pos6 + 1);
            size_t coma_pos8 = linea.find(",", coma_pos7 + 1);
            size_t coma_pos9 = linea.find(",", coma_pos8 + 1);
            size_t coma_pos10 = linea.find(",", coma_pos9 + 1);
            size_t coma_pos11 = linea.find(",", coma_pos10 + 1);
            size_t coma_pos12 = linea.find(",", coma_pos11 + 1);
            size_t coma_pos13 = linea.find(",", coma_pos12 + 1);
            size_t coma_pos14 = linea.find(",", coma_pos13 + 1);
            size_t coma_pos15 = linea.find(",", coma_pos14 + 1);
            size_t coma_pos16 = linea.find(",", coma_pos15 + 1);
            size_t coma_pos17 = linea.find(",", coma_pos16 + 1);
            size_t coma_pos18 = linea.find(",", coma_pos17 + 1);
            size_t coma_pos19 = linea.find(",", coma_pos18 + 1);
            size_t coma_pos20 = linea.find(",", coma_pos19 + 1);
            size_t coma_pos21 = linea.find(",", coma_pos20 + 1);
            size_t coma_pos22 = linea.find(",", coma_pos21 + 1);
            size_t coma_pos23 = linea.find(",", coma_pos22 + 1);
            size_t coma_pos24 = linea.find(",", coma_pos23 + 1);
            size_t coma_pos25 = linea.find(",", coma_pos24 + 1);
            size_t coma_pos26 = linea.find(",", coma_pos25 + 1);
            size_t coma_pos27 = linea.find(",", coma_pos26 + 1);
            size_t coma_pos28 = linea.find(",", coma_pos27 + 1);
            size_t coma_pos29 = linea.find(",", coma_pos28 + 1);
            size_t coma_pos30 = linea.find(",", coma_pos29 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1, coma_pos7 - coma_pos6 - 1));
                ed = std::stoi(linea.substr(coma_pos7 + 1, coma_pos8 - coma_pos7 - 1));
                em = std::stoi(linea.substr(coma_pos8 + 1, coma_pos9 - coma_pos8 - 1));
                ea = std::stoi(linea.substr(coma_pos9 + 1, coma_pos10 - coma_pos9 - 1));
                eh = std::stoi(linea.substr(coma_pos10 + 1, coma_pos11 - coma_pos10 - 1));
                emi = std::stoi(linea.substr(coma_pos11 + 1, coma_pos12 - coma_pos11 - 1));
                es = std::stoi(linea.substr(coma_pos12 + 1, coma_pos13 - coma_pos12 - 1));
                sad = std::stoi(linea.substr(coma_pos13 + 1, coma_pos14 - coma_pos13 - 1));
                sam = std::stoi(linea.substr(coma_pos14 + 1, coma_pos15 - coma_pos14 - 1));
                saa = std::stoi(linea.substr(coma_pos15 + 1, coma_pos16 - coma_pos15 - 1));
                sah = std::stoi(linea.substr(coma_pos16 + 1, coma_pos17 - coma_pos16 - 1));
                sami = std::stoi(linea.substr(coma_pos17 + 1, coma_pos18 - coma_pos17 - 1));
                sas = std::stoi(linea.substr(coma_pos18 + 1, coma_pos19 - coma_pos18 - 1));
                ead = std::stoi(linea.substr(coma_pos19 + 1, coma_pos20 - coma_pos19 - 1));
                eam = std::stoi(linea.substr(coma_pos20 + 1, coma_pos21 - coma_pos20 - 1));
                eaa = std::stoi(linea.substr(coma_pos21 + 1, coma_pos22 - coma_pos21 - 1));
                eah = std::stoi(linea.substr(coma_pos22 + 1, coma_pos23 - coma_pos22 - 1));
                eami = std::stoi(linea.substr(coma_pos23 + 1, coma_pos24 - coma_pos23 - 1));
                eas = std::stoi(linea.substr(coma_pos24 + 1, coma_pos25 - coma_pos24 - 1));
                sd = std::stoi(linea.substr(coma_pos25 + 1, coma_pos26 - coma_pos25 - 1));
                sm = std::stoi(linea.substr(coma_pos26 + 1, coma_pos27 - coma_pos26 - 1));
                sa = std::stoi(linea.substr(coma_pos27 + 1, coma_pos28 - coma_pos27 - 1));
                sh = std::stoi(linea.substr(coma_pos28 + 1, coma_pos29 - coma_pos28 - 1));
                smi = std::stoi(linea.substr(coma_pos29 + 1, coma_pos30 - coma_pos29 - 1));
                ss = std::stoi(linea.substr(coma_pos30 + 1));
                Fecha nacimiento(nd, nm, na);
                Fecha entrada(ed, em, ea, eh, emi, es);
                Fecha salidaAlmuerzo(sad, sam, saa, sah, sami, sas);
                Fecha entradoAlmuerzo(ead, eam, eaa, eah, eami, eas);
                Fecha salida(sd, sm, sa, sh, smi, ss);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);
                Registro registro(empleado, entrada, salidaAlmuerzo, entradoAlmuerzo, salida);
                if (anio == ea && mes == em && dia == ed) {
                    lista->insertar(registro);
                }
            }
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo Registro.txt para leer" << std::endl;
    }
    return lista;
}

/**
* Guarda dentro de un .txt una lista de empleados
*
* @param ListaEmpleados* lista
*
* @return void
**/
void Archivos::guardarListaEmpleados(ListaEmpleados* lista) {
    std::ofstream archivo("Empleado.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < lista->dimencion(); i++) {
            archivo << lista->getPosicion(i).getNombre() << ",";
            archivo << lista->getPosicion(i).getApellido() << ",";
            archivo << lista->getPosicion(i).getCedula() << ",";
            archivo << lista->getPosicion(i).getFecha().getDia() << ",";
            archivo << lista->getPosicion(i).getFecha().getMes() << ",";
            archivo << lista->getPosicion(i).getFecha().getAnio() << ",";
            archivo << lista->getPosicion(i).getSalario() << endl;
        }
        archivo.close();
        std::cout << "Lista de empleados guardada exitosamente en Empleado.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Empleado.txt para escribir" << std::endl;
    }
}

/**
* Lee y filtra por fecha un .txt de lista de Empleados
*
* @return void
**/
ListaEmpleados* Archivos::leerListaEmpleados() {
    ListaEmpleados* lista = new ListaEmpleados();
    std::ifstream archivo("Empleado.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::string nombre;
            std::string apellido;
            std::string cedula;
            double sueldo;
            int nd, nm, na;
            size_t coma_pos = linea.find(",");
            size_t coma_pos2 = linea.find(",", coma_pos + 1);
            size_t coma_pos3 = linea.find(",", coma_pos2 + 1);
            size_t coma_pos4 = linea.find(",", coma_pos3 + 1);
            size_t coma_pos5 = linea.find(",", coma_pos4 + 1);
            size_t coma_pos6 = linea.find(",", coma_pos5 + 1);
            if (coma_pos != std::string::npos) {
                nombre = linea.substr(0, coma_pos);
                apellido = linea.substr(coma_pos + 1, coma_pos2 - coma_pos - 1);
                cedula = linea.substr(coma_pos2 + 1, coma_pos3 - coma_pos2 - 1);
                nd = std::stoi(linea.substr(coma_pos3 + 1, coma_pos4 - coma_pos3 - 1));
                nm = std::stoi(linea.substr(coma_pos4 + 1, coma_pos5 - coma_pos4 - 1));
                na = std::stoi(linea.substr(coma_pos5 + 1, coma_pos6 - coma_pos5 - 1));
                sueldo = std::stod(linea.substr(coma_pos6 + 1));
                Fecha nacimiento(nd, nm, na);
                Empleado empleado(cedula, nombre, apellido, nacimiento, sueldo);

                lista->insertar(empleado);
            }
        }
        archivo.close();
        std::cout << "Lista de productos leída exitosamente desde Empleado.txt" << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo Empleado.txt para leer" << std::endl;
    }
    return lista;
}

/**
* Imprime una imagen seleccionada usando la libresia opencv
*
* @return void
**/
void Archivos::imprimirImagen(){
    std::system("cls");
    cv::Mat imagen = cv::imread("t.jpg", cv::IMREAD_COLOR);

    if (imagen.empty()) {
        std::cout << "No se pudo cargar la imagen." << std::endl;
    }
    else {
        int pixelSize = 1;

        cv::Size newSize(imagen.cols / pixelSize, imagen.rows / pixelSize);
        cv::Mat pixelArt;
        cv::resize(imagen, pixelArt, newSize, cv::INTER_NEAREST);

        cv::resize(pixelArt, pixelArt, imagen.size(), cv::INTER_NEAREST);

        cv::imshow("Imagen en Pixel Art", pixelArt);

        cv::waitKey(0);
    }
}