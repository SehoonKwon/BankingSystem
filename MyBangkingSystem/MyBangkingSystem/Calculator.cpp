#include <iostream>
#include "Calculator.h"
using namespace std;

void Calculator::Init()
{
	Calculator::Addcnt = 0;
	Calculator::Divcnt = 0;
	Calculator::Mincnt = 0;
	Calculator::Mulcnt = 0;
}

double Calculator::Add(double A, double B)
{
	Calculator::Addcnt++;
	return A + B;
}

double Calculator::Min(double A, double B)
{
	Calculator::Mincnt++;
	return A - B;
}

double Calculator::Mul(double A, double B)
{
	Calculator::Mulcnt++;
	return A*B;
}

double Calculator::Div(double A, double B)
{
	Calculator::Divcnt++;
	return A / B;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À »¬¼À °ö¼À ³ª´°¼À = :" << Calculator::Addcnt << " " << Calculator::Mincnt << " " << Calculator::Mulcnt << " " << Calculator::Divcnt << "\n";
}