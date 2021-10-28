#include "TPolinom.h"

TPolinom::TPolinom()
{
	a = 1;
	b = 1;
	c = 1;
	bisPolinomFilled = false;
	for (int i = 0; i < 2 ; i++)
		CalculatedValues.push_back(number(0.0));
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

std::vector<number> TPolinom::getPolinom()
{
	return { this->a, this->b, this->c };
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
	number discriminant = b * b - a * 4.0 * c;

	CalculatedValues[0] = ((b * (-1.0)) + sqrt(discriminant)) / (a * 2.0);
	CalculatedValues[1] = ((b * (-1.0)) - sqrt(discriminant)) / (a * 2.0);
	success = true;

	return true;
}

number TPolinom::CalculatePolinomWithArgument(number argument)
{
	number calculatedValue;

	calculatedValue = (this->a * (argument * argument)) + (this->b * argument) + this->c;

	return calculatedValue;
}


