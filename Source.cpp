#include <iostream>
#include <Windows.h>
#include "TApplication.h"


int main()
{
	TApplication mainWindow;

	HANDLE  hout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD  size;
	size.X = 200;     // ���-�� �������� �� ������
	size.Y = 1001;  // ����������� �� 1000 - �����, ����� ���� 2000
	SetConsoleScreenBufferSize(hout, size);
	setlocale(0, ""); // �����������
	SetConsoleCP(1251); // ����������� ����� ������
	SetConsoleOutputCP(1251); // ����������� ������ ������

	mainWindow.ShowMenu();

}
