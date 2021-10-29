#include "TApplication.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

void SetColor(int text, int bg) //Функция смены цвета, взятая из Интернета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

const int NotUsed = system("color 70"); // изменения цвета консоли в серый 


void TApplication::ConfirmMenuItem() // выбор после подтверждения в зависимости от значения текущего
{
	switch (this->currentMenuItem)
	{
	case 0:
		SetPolinomCoefs();
		break;
	case 1:
		if (CanCalculatePolinom())
		{
			if (currentPolinom.Calculate())
				PrintResultPolinom();
			else
			{
				SetColor(4, 7);
				std::cout << "Дискриминант меньше нуля. Действительных корней не существует" << std::endl;
				SetColor(0, 7);
				system("pause");
			}
		}
		else
		{
			PrintPolinomIsNotFill();
			system("pause");
		}
		break;
	case 2:
		if (CanCalculatePolinom())
		{
			CalculatePolinomWithArgument();
		}
		else
		{
			PrintPolinomIsNotFill();
			system("pause");
		}
		break;
	case 3:
		if (CanCalculatePolinom())
		{
			system("cls");
			std::cout << "-----Вывод полинома-----" << std::endl;
			SetColor(2, 7);
			PrintPolinomText();
			std::cout << std::endl;
			SetColor(0, 7);
			system("pause");
		}
		else
		{
			PrintPolinomIsNotFill();
			system("pause");
		}
		break;
	case 4:
		SetColor(7, 7);
		exit(0);
		break;
	default:
		break;
	}

	ShowMenu();
}

void TApplication::ShowMenu() // меню
{
	system("cls"); // очищаем консоль
	std::cout << "-----Основное меню-----" << std::endl;
	for (int i = 0; i < MenuOptions.size(); i++)
	{
		if (i == this->currentMenuItem)
			SetColor(5, 7);

		std::cout << MenuOptions[i] << std::endl;
		SetColor(0, 7);
	}
	ChoiceMenuItem();
}

void TApplication::SetPolinomCoefs()
{
	system("cls");
	std::cout << "-----Ввод параметров полинома-----" << std::endl;
	std::cout << "a*x^2 + b * x + c " << std::endl;
	number a, b, c;
	a = InputParameter("a");
	b = InputParameter("b");
	c = InputParameter("c");
	
	currentPolinom.setPolinom(a, b, c);
	currentPolinom.setIsPolinomFilled(true);

	std::cout << "Данные успешно введены" << std::endl;
	system("cls");

	ShowMenu();
}

number TApplication::InputParameter(std::string ParameterText)
{
	bool bIsCorrectValue = false;
	number tempValue;
	std::cout << "Введите параметр " << ParameterText << " (действительная и мнимая часть через пробел) : ";
	while (!bIsCorrectValue)
	{
		std::cin >> tempValue;

		if (std::cin.fail()) // ecли предыдущее извелечение оказлось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в обычный режим работы
			std::cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
			std::cout << "Недопустимое заданное число. Введите число правильно" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем из буфера значения предыдущего ввода
			bIsCorrectValue = true;
		}
	}
	return tempValue;
}

bool TApplication::CanCalculatePolinom()
{
	return currentPolinom.getIsPolinomFilled();
}

void TApplication::CalculatePolinomWithArgument()
{
	system("cls");
	number tempArgument;
	std::cout << "-----Вычисление полинома с введенным аргументом-----" << std::endl;
	std::cout << "Полином: ";
	PrintPolinomText();
	std::cout << std::endl;
	tempArgument = InputParameter("аргумента");
	std::cout << "Результат равен: " << currentPolinom.CalculatePolinomWithArgument(tempArgument) << std::endl;

	system("pause");
	ShowMenu();
}

void TApplication::PrintResultPolinom()
{
	system("cls");
	std::cout << "Полученный результат полинома ";
	PrintPolinomText();
	std::cout << std::endl;
	std::vector<number> tempResults = currentPolinom.getCalculatedPolinom();
	std::cout << "x_1 = " << tempResults[0] << "   " << "x_2 = " << tempResults[1] << std::endl;

	system("pause");
	ShowMenu();
}

void TApplication::PrintPolinomIsNotFill()
{
	SetColor(4, 7);
	std::cout << "Не заполнены коэффициенты полинома. Заполните коэффициенты и попробуйте снова." << std::endl;
	SetColor(0, 7);
}

void TApplication::PrintPolinomText()
{
	std::vector<number> resultPolinom = currentPolinom.getPolinom();
	if (resultPolinom[0] != number(0))
	{
		std::cout << resultPolinom[0] << "*x^2 ";
	}
	if (resultPolinom[1] != number(0))
	{
		if (resultPolinom[1] > 0 && resultPolinom[0] != 0)
			std::cout << " + ";
		std::cout << resultPolinom[1] << "*x";
	}
	if (resultPolinom[2] != number(0))
	{
		if (resultPolinom[2] > 0 && (resultPolinom[0] != 0 || resultPolinom[1] != 0))
			std::cout << " + ";
		std::cout << resultPolinom[2];
	}

}

void TApplication::ChoiceMenuItem() // в зависимости от стрелок изменяем меню
{
	int k1;
	k1 = _getch(); // получаем символ стрелки без вывода знака
	if (k1 == 0xE0) // если стрелки
	{
		switch (k1)
		{
		case 0x48: // стрелка вверх
			this->currentMenuItem--;
			if (this->currentMenuItem < 0) this->currentMenuItem = 0;
			ShowMenu();
			break;

		case 0x50: // стрелка вниз
			this->currentMenuItem++;
			if (this->currentMenuItem > MenuOptions.size() - 1) this->currentMenuItem = MenuOptions.size() - 1;
			ShowMenu();
			break;
		case 0xD: // подтвердить
			ConfirmMenuItem();
			break;
		default:
			ChoiceMenuItem();
		}
	}
	switch (k1)
	{
	case 0x48: // стрелка вверх
		this->currentMenuItem--;
		if (this->currentMenuItem < 0) this->currentMenuItem = 0;
		ShowMenu();
		break;

	case 0x50: // стрелка вниз
		this->currentMenuItem++;
		if (this->currentMenuItem > MenuOptions.size() - 1) this->currentMenuItem = MenuOptions.size() - 1;
		ShowMenu();
		break;
	case 0xD: // подтвердить
		ConfirmMenuItem();
		break;
	default:
		ChoiceMenuItem();
	}
}