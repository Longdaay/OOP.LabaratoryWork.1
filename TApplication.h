#pragma once
#include <vector>
#include <string>
#include "TPolinom.h"

class TApplication
{
public:
	void ConfirmMenuItem();
	void ChoiceMenuItem();
	void ShowMenu();

	void SetPolinomCoefs();
	number InputParameter(std::string ParameterText);
	bool CanCalculatePolinom();
	void CalculatePolinomWithArgument();

	void PrintResultPolinom();
	void PrintPolinomIsNotFill();
	void PrintPolinomText();
private:
	int currentMenuItem = 0;
	std::vector<std::string> MenuOptions{ "������ ������������ ��������", "��������� �����", "��������� �������� �������� � ������ �������� ��������", "������� �������", "�����" };
	TPolinom currentPolinom;
};

