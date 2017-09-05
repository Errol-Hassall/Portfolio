//PolynomialPS1.cpp DSP assignment 1
#include "Polynomial.h"
#include <cmath>
using namespace std;

double Polynomial::operator()(double aX)const {
	double lResult = 0;

	for (int i = 0; i <= fDegree; i++)
	{
		lResult += fCoeffs[i] * pow(aX, i);
	}

	return lResult;
}

Polynomial Polynomial::buildIndefiniteIntegral() const{
	Polynomial lResult;
	lResult.fDegree = fDegree + 1;
	lResult.fCoeffs[0] = 0.0;

	for (int i = 1; i <= lResult.fDegree; i++)
	{
		lResult.fCoeffs[i] = fCoeffs[i - 1] / i;
	}

	return lResult;
}

double Polynomial::buildDefiniteIntegral(double aXLow, double aXHigh) const {
	Polynomial lResult = buildIndefiniteIntegral();
	return lResult(aXHigh) - lResult(aXLow);
}