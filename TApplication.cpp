#include "TApplication.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

void SetColor(int text, int bg) //������� ����� �����, ������ �� ���������
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

const int NotUsed = system("color 70"); // ��������� ����� ������� � ����� 


void TApplication::ConfirmMenuItem() // ����� ����� ������������� � ����������� �� �������� ��������
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
				std::cout << "������������ ������ ����. �������������� ������ �� ����������" << std::endl;
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
			std::cout << "-----����� ��������-----" << std::endl;
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

void TApplication::ShowMenu() // ����
{
	system("cls"); // ������� �������
	std::cout << "-----�������� ����-----" << std::endl;
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
	std::cout << "-----���� ���������� ��������-----" << std::endl;
	std::cout << "a*x^2 + b * x + c " << std::endl;
	number a, b, c;
	a = InputParameter("a");
	b = InputParameter("b");
	c = InputParameter("c");
	
	currentPolinom.setPolinom(a, b, c);
	currentPolinom.setIsPolinomFilled(true);

	std::cout << "������ ������� �������" << std::endl;
	system("cls");

	ShowMenu();
}

number TApplication::InputParameter(std::string ParameterText)
{
	bool bIsCorrectValue = false;
	number tempValue;
	std::cout << "������� �������� " << ParameterText << " (�������������� � ������ ����� ����� ������) : ";
	while (!bIsCorrectValue)
	{
		std::cin >> tempValue;

		if (std::cin.fail()) // ec�� ���������� ����������� �������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � ������� ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
			std::cout << "������������ �������� �����. ������� ����� ���������" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ������� �� ������ �������� ����������� �����
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
	std::cout << "-----���������� �������� � ��������� ����������-----" << std::endl;
	std::cout << "�������: ";
	PrintPolinomText();
	std::cout << std::endl;
	tempArgument = InputParameter("���������");
	std::cout << "��������� �����: " << currentPolinom.CalculatePolinomWithArgument(tempArgument) << std::endl;

	system("pause");
	ShowMenu();
}

void TApplication::PrintResultPolinom()
{
	system("cls");
	std::cout << "���������� ��������� �������� ";
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
	std::cout << "�� ��������� ������������ ��������. ��������� ������������ � ���������� �����." << std::endl;
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

void TApplication::ChoiceMenuItem() // � ����������� �� ������� �������� ����
{
	int k1;
	k1 = _getch(); // �������� ������ ������� ��� ������ �����
	if (k1 == 0xE0) // ���� �������
	{
		switch (k1)
		{
		case 0x48: // ������� �����
			this->currentMenuItem--;
			if (this->currentMenuItem < 0) this->currentMenuItem = 0;
			ShowMenu();
			break;

		case 0x50: // ������� ����
			this->currentMenuItem++;
			if (this->currentMenuItem > MenuOptions.size() - 1) this->currentMenuItem = MenuOptions.size() - 1;
			ShowMenu();
			break;
		case 0xD: // �����������
			ConfirmMenuItem();
			break;
		default:
			ChoiceMenuItem();
		}
	}
	switch (k1)
	{
	case 0x48: // ������� �����
		this->currentMenuItem--;
		if (this->currentMenuItem < 0) this->currentMenuItem = 0;
		ShowMenu();
		break;

	case 0x50: // ������� ����
		this->currentMenuItem++;
		if (this->currentMenuItem > MenuOptions.size() - 1) this->currentMenuItem = MenuOptions.size() - 1;
		ShowMenu();
		break;
	case 0xD: // �����������
		ConfirmMenuItem();
		break;
	default:
		ChoiceMenuItem();
	}
}