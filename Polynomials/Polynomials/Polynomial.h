#pragma once

#include <iostream>


#define MAX_DEGREE 20+1+1 // max degree = 10 + 10 + 1, 0 to 20

class Polynomial {
private:
	int fDegree; // the maximum degreee of the polynomial
	double fCoeffs[MAX_DEGREE]; // the coeffecients (0...10, 0..20)

public:
	//The default constructor (intializes all member variables)
	Polynomial();

	//binary operator* to multiply two polynomials
	//arguments are read-only, signified by const
	//the operator* returns a fresh polynomial with degree i+j
	Polynomial operator*(const Polynomial& aRight) const;

	//input operator for polynomials
	friend std::istream& operator>>(std::istream& aIStream, Polynomial& aObject);

	//outout operator for polynomials
	friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject);

	//new methods in porblem set 1

	//call operator to calculate polynomial for a given x
	double operator()(double aX)const;

	// build indefinite integral
	// the indefinite integral is a fresh polynomial with degree fDegree+1
	// the method does not change the current object
	Polynomial buildIndefiniteIntegral() const;

	// build definite integral
	// the method does not change the current object
	// the method computes the indefinite integral and then calculates it
	// for xlow and xhigh and returns the difference
	double buildDefiniteIntegral(double aXLow, double aXHigh) const;
};