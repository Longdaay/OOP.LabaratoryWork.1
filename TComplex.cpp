#include "TComplex.h"
#include <iostream>

TComplex::TComplex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

TComplex::TComplex(double real)
{
	this->real = real;
	this->imaginary = 0;
}

TComplex::TComplex()
{
	this->real = 0;
	this->imaginary = 0;
}

void TComplex::operator=(int value)
{
	this->real = double(value);
	this->imaginary = 0;

}

bool TComplex::operator!=(TComplex value)
{
	return (this->real != value.real);
}

bool TComplex::operator>(TComplex value)
{
	return (this->real > value.real);
}

bool TComplex::operator<(TComplex value)
{
	return (this->real < value.real);
}

bool TComplex::operator==(TComplex value)
{
	return (this->real == value.real);
}

TComplex TComplex::operator*(TComplex value)
{
	return { (this->real * value.real - this->imaginary * value.imaginary), (this->real * value.imaginary - value.real * this->imaginary) };
}

TComplex TComplex::operator*(double value)
{
	return { (this->real * value), (this->imaginary * value) };
}

TComplex TComplex::operator-(TComplex value)
{
	return { (this->real - value.real), (this->imaginary - value.imaginary) };
}

TComplex TComplex::operator/(TComplex value)
{
	double resultReal, resultImaginary;
	resultReal = (this->real * value.real + this->imaginary * value.imaginary) / (value.real * value.real + value.imaginary * value.imaginary);
	resultImaginary = (this->imaginary * value.real - this->real * value.imaginary) / (value.real * value.real + value.imaginary * value.imaginary);
	return {resultReal, resultImaginary};
}

TComplex TComplex::operator+(TComplex value)
{
	return { (this->real + value.real), (this->imaginary + value.imaginary) };
}

std::ostream& operator<<(std::ostream& os, const TComplex& value)
{
	os << value.real << (value.imaginary < 0 ? "" : "+") << value.imaginary << "i";
	return os;
}

std::istream& operator>>(std::istream& in, TComplex& value)
{
	in >> value.real;
	in >> value.imaginary;
	return in;
}

TComplex sqrt(const TComplex& complex)
{
	if (complex.imaginary == 0.0)
	{
		if (complex.real >= 0.0)
		{
			return { std::sqrt(complex.real), 0.0 };
		}
		else
		{
			return { 0.0, std::sqrt(-complex.real) };
		}
	}
	const double modulus = std::sqrt(complex.real * complex.real + complex.imaginary * complex.imaginary);

	return { std::sqrt((modulus + complex.real) / 2), (std::signbit(complex.imaginary) ? -1 : 1) * std::sqrt((modulus - complex.real) / 2) };

}
