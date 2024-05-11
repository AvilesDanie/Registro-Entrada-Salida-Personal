/***************************************************
Universidad de las Fuerzas Armadas ESPE
Autores: Daniel Aviles, Ariel Reyes
Fechas de Creacion: 07/07/2023
Fecha de modificacion: 24/08/2023
Menu de registro
****************************************************/
#include "Menu.h"
#include <iostream>
#include "Archivos.h"
#include "ListaEmpleados.h"
#include <vector>

using namespace std;

/**
* Cronometro para realizar el back up a una hora en especifico
*
* @param int horaEjecucion, int minutosEjecucion
*
* @return void
**/
void esperarMomentoEspecifico(int horaEjecucion, int minutosEjecucion)
{
    while (true)
    {
        std::time_t currentTime;
        std::tm timeInfo;
        std::time(&currentTime);
        localtime_s(&timeInfo, &currentTime);
        int horaActual = timeInfo.tm_hour;
        int minutosActuales = timeInfo.tm_min;

        if (horaActual > horaEjecucion || (horaActual == horaEjecucion && minutosActuales >= minutosEjecucion))
        {
            Archivos arc;
            std::vector<std::string> filesToCopy = { "Empleado.txt", "Registro.txt" };
            std::string targetFolder = "BackUp";

            arc.moverArchivos(filesToCopy, targetFolder);
            break;
        }

        int minutosRestantes = (horaEjecucion - horaActual) * 60 + (minutosEjecucion - minutosActuales);
        if (minutosRestantes <= 0) minutosRestantes += 24 * 60;

        std::this_thread::sleep_for(std::chrono::minutes(minutosRestantes));
    }
}

int main(){


    int horaEjecucion = 8;
    int minutosEjecucion = 40;

    std::thread threadEspera(esperarMomentoEspecifico, horaEjecucion, minutosEjecucion);


	Menu objM;
	objM.menuPrincipal();


    threadEspera.join();
	return 0;
}





