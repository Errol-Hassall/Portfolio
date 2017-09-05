#include "Polynomial.h"

Polynomial::Polynomial() {
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++) {
		fCoeffs[i] = 0;
	}
}

Polynomial Polynomial::operator*(const Polynomial & aRight) const
{
	Polynomial lResult;
	lResult.fDegree = fDegree + aRight.fDegree;
	for (int i = fDegree; i >= 0; i--)
	{
		for (int j = aRight.fDegree; j >= 0; j--) {
			lResult.fCoeffs[j+i] += fCoeffs[i] * aRight.fCoeffs[j];
		}
	}
	return lResult;
}


std::istream & operator >> (std::istream & aIStream, Polynomial & aObject)
{
	aIStream >> aObject.fDegree;
	for (int i = 0; i < aObject.fDegree+1; i++)
	{
		aIStream >> aObject.fCoeffs[i];
	}
	return aIStream;
}

std::ostream & operator<<(std::ostream & aOStream, const Polynomial & aObject)
{
	for (int i = 0; i <= aObject.fDegree; i++)
	{
		if (aObject.fCoeffs[i]!=0.0)
		{
			aOStream << aObject.fCoeffs[i] << "x^" << i;
			if (i != aObject.fDegree)
			{
				aOStream << " + ";
			}
		}
	}
	return aOStream;
}
