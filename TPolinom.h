#pragma once
#include <string>
#include <vector>
#include "Number.h"

class TPolinom
{
public:
	TPolinom();

	void setPolinom(number a, number b, number c);
	void setIsPolinomFilled(bool flag);

	std::vector<number> getPolinom();
	std::vector<number> getCalculatedPolinom();

	bool getIsPolinomFilled();
	bool Calculate();
	number CalculatePolinomWithArgument(number argument);
	
private:
	number a, b, c;
	std::vector<number> CalculatedValues;
	bool bisPolinomFilled;
};

