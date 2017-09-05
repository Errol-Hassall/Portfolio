#include "FibonaccIIterator.h"

//The constructor for the class
//takes in a max num of iterations
//sets fCurrentN, fCurrent to 1 
//fPrevious to 0
FibonacciIterator::FibonacciIterator(long aMaxN)
{
	fMaxN = aMaxN;
	fCurrentN = 1;
	fCurrent = 1;
	fPrevious = 0;
}

//Returns the fCurrent value
const long & FibonacciIterator::operator*() const
{
	return fCurrent;
}

//Prefix iterator
//This is the algorithm for the fibonacci sequence
FibonacciIterator & FibonacciIterator::operator++()
{
	long lNext = fPrevious + fCurrent;
	fPrevious = fCurrent;
	fCurrent = lNext;
	fCurrentN++;
	return *this;
}

//Postfix iterator
//This iterator uses the same prefix operator but
//returns the value before it is incremented
FibonacciIterator FibonacciIterator::operator++(int)
{
	FibonacciIterator temp = *this;
	++(*this);
	return temp;
}

//Compares two objects fCurrentN fields for equality
bool FibonacciIterator::operator==(const FibonacciIterator & aOther) const
{
	return fCurrentN == aOther.fCurrentN;
}

//Compares two objects fCurrentN fields for inequality
bool FibonacciIterator::operator!=(const FibonacciIterator & aOther) const
{
	return !(*this == aOther);
}

//returns a new FibonacciIterator object
FibonacciIterator FibonacciIterator::begin() const
{
	return FibonacciIterator(fMaxN);
}

//Returns a FibonacciIterator object
//with an fMaxN one greater than created at the begining of the program
FibonacciIterator FibonacciIterator::end() const
{
	FibonacciIterator temp = *this;
	temp.fCurrentN = fMaxN + 1;
	return temp;
}
