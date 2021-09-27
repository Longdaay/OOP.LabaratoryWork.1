#pragma once
class TComplex
{
public:
	TComplex(double real, double imaginary);
	TComplex();

	TComplex operator+ (double);
	TComplex operator+ (TComplex);
	TComplex operator- (TComplex);
	TComplex operator- (double);

	int operator* ();
	
	TComplex operator* (TComplex);
	TComplex operator* (int);
	//TComplex operator* (TComplex);
	TComplex operator/ (TComplex);
	TComplex operator= (int);
	bool operator== (int);
	bool operator!=(int);
	bool operator>(int);
	bool operator<(int);
	void operator>> (TComplex);
	void operator<< (TComplex);
	
private:
	double real;
	double imaginary;
};

