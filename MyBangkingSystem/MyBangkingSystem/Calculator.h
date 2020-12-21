#pragma once

class Calculator
{
private:
	int Addcnt;
	int Divcnt;
	int Mincnt;
	int Mulcnt;
public:
	void Init();
	double Add(double A, double B);
	double Div(double A, double B);
	double Min(double A, double B);
	double Mul(double A, double B);
	void ShowOpCount();
};
