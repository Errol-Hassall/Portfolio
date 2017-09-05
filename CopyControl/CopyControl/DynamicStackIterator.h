#pragma once
#include "DynamicStack.h"
template<class T>
class DynamicStackIterator
{
private:
	DynamicStack<T> fStack;
public:
	//copies the arugment stack to the field stack 
	DynamicStackIterator(const DynamicStack<T>& aStack) {
		fStack = aStack;
	}
	//dereference operator returns the top of the stack
	const T& operator*() const {
		return fStack.top();
	}
	//prefix increment pops an item off the stack
	DynamicStackIterator& operator++() {
		fStack.pop();
		return *this;
	} 
	//postfix increment 
	DynamicStackIterator operator++(int) {
		DynamicStackIterator temp = *this;
		++(*this);
		return temp;
	} 
	//compares the two stacks for equality
	bool operator==(const DynamicStackIterator& aOtherIter) const {
		return (fStack.size() == aOtherIter.fStack.size());
	}
	//compares the two stacks for inequality
	bool operator!=(const DynamicStackIterator& aOtherIter) const {
		return !(*this == aOtherIter);
	}
	//creates a new stack after the last element
	DynamicStackIterator end() const {
		DynamicStackIterator temp = *this;
		temp.fStack = DynamicStack<T>();
		return temp;
	} 
};