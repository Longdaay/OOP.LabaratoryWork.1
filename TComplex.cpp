#include "TComplex.h"
#include <iostream>

TComplex::TComplex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

TComplex::TComplex()
{
	real = 0;
	imaginary = 0;
}

TComplex TComplex::operator+(double real)
{
	return { real + this->real, this->imaginary };
}

TComplex TComplex::operator+(TComplex complex)
{
	return { this->real + complex.real, this->imaginary };
}

TComplex TComplex::operator-(TComplex complex)
{
	return { this->real - complex.real, this->imaginary - complex.imaginary };
}

TComplex TComplex::operator-(double value)
{
	return { this->real - value, this->imaginary };
}

int TComplex::operator*()
{
	return int();
}

TComplex TComplex::operator*(TComplex complex)
{
	return { (this->real * complex.real - this->imaginary * complex.imaginary), (this->real * complex.imaginary - complex.real * this->imaginary) };
}

TComplex TComplex::operator*(int value)
{
	return { this->real * value, this->imaginary * value };
}

TComplex TComplex::operator/(TComplex)
{
	return {};
}

TComplex TComplex::operator=(int value)
{
	return { value, 0.0 };
}

bool TComplex::operator==(int value)
{
	return (this->real == value ? true : false);;
}

bool TComplex::operator!=(int value)
{
	return (this->real != value ? true : false);
}

bool TComplex::operator>(int value)
{
	return (this->real > value ? true : false);
}

bool TComplex::operator<(int value)
{
	return (this->real < value ? true : false);
}

void TComplex::operator>>(TComplex complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;
}

void TComplex::operator<<(TComplex complex)
{
	std::cout << complex.real << (complex.imaginary >= 0.0 ? '+' : '\0') << complex.imaginary << "*i" << std::endl;
}
