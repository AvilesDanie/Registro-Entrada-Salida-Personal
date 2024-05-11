/***********************************************************************
 * Module:  Menu.h
 * Authors:  Aviles, Reyes
 * Modified: mi�rcoles, 3 de julio de 2023
 * Purpose: Declaration of the class Menu
 ***********************************************************************/
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
class Menu {
public:
	void menuPrincipal();
	int menu(const char* titulo, const char** opciones, int n);
	void gotoxy(int x, int y);
};