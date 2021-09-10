#include <iostream>
#include <Windows.h>
#include "TApplication.h"


int main()
{
	TApplication mainWindow;

	HANDLE  hout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD  size;
	size.X = 200;     // кол-во символов на строку
	size.Y = 1001;  // увеличиваем до 1000 - строк, можно хоть 2000
	SetConsoleScreenBufferSize(hout, size);
	setlocale(0, ""); // локализация
	SetConsoleCP(1251); // локализация ввода строки
	SetConsoleOutputCP(1251); // локализация вывода строки

	mainWindow.ShowMenu();

}
