#pragma once

#include "List.h"
#include <stdexcept>

template<class T>
class DynamicStack
{
private:
	List<T> fElements;
public:
	//checks to see if the stack is empty
	bool isEmpty() const {
		return fElements.isEmpty();
	}
	//returns the size of the list
	int size() const {
		return fElements.size();
	}
	//pushes an item onto the list
	void push(const T& aItem) {
		fElements.push_front(aItem);
	}
	//pops an item off the list
	void pop() {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		fElements.remove(top());
	}
	//returns the top element of the list
	const T& top() const {
		if (isEmpty()) {
			throw std::underflow_error("Stack is empty");
		}
		return *fElements.getIterator();
	}
};