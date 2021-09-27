#include "TPolinom.h"

TPolinom::TPolinom()
{
	a = 1;
	b = 1;
	c = 1;
	bisPolinomFilled = false;
	for (int i = 0; i < 2 ; i++)
		CalculatedValues.push_back(0);
}

void TPolinom::setPolinom(number a, number b, number c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void TPolinom::setIsPolinomFilled(bool flag)
{
	this->bisPolinomFilled = flag;
}

std::string TPolinom::getPolinom()
{
	std::string polinom;
	if (this->a != 0) 
	{
		std::string a = std::to_string(this->a);
		while (a.back() == '0' || a.back() == ',') a.pop_back();
		polinom.append(a);

		polinom.append("x^2 ");
	}
	if (this->b != 0)
	{
		if (this->b > 0 && this->a != 0)
			polinom.append("+ ");
		std::string b = std::to_string(this->b);
		while (b.back() == '0' || b.back() == ',') b.pop_back();
		polinom.append(b);

		polinom.append("x ");
	}
	if (this->c != 0)
	{
		if (this->c > 0 && (this->a != 0 || this->b != 0))
			polinom.append("+ ");
		std::string с = std::to_string(this->c);
		while (с.back() == '0' || с.back() == ',') с.pop_back();
		polinom.append(с);
	}
	return polinom;
}

std::vector<number> TPolinom::getCalculatedPolinom()
{
	return this->CalculatedValues;
}

bool TPolinom::getIsPolinomFilled()
{
	return this->bisPolinomFilled;
}

bool TPolinom::Calculate()
{
	bool success;
	number discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
	{
		CalculatedValues[0] = ((b * (-1)) + sqrt(discriminant)) / (a * 2);
		CalculatedValues[1] = ((b * (-1))  - sqrt(discriminant)) / (a * 2);
		success = true;
	}
	if (discriminant == 0) // Условие для дискриминанта равного нулю
	{
		CalculatedValues[0] = -(b / (2 * a));
		CalculatedValues[1] = CalculatedValues[0];
		success = true;
	}
	if (discriminant < 0) // Условие при дискриминанте меньше нуля
		success = false;

	return success;
}

number TPolinom::CalculatePolinomWithArgument(number argument)
{
	number calculatedValue;

	calculatedValue = (this->a * (argument * argument)) + (this->b * argument) + this->c;

	return calculatedValue;
}


