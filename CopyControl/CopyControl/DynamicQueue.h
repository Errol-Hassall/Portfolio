#pragma once
#include "List.h"
#include <stdexcept>
template<class T>
class DynamicQueue
{
private:
	List<T> fElements;
public:
	//checks if the queue is empty
	bool isEmpty() const {
		return fElements.isEmpty();
	}
	//returns the size of the queue
	int size() const {
		return fElements.size();
	}
	//adds an element to the queue
	void enqueue(const T& aElement) {
		fElements.push_back(aElement);
	}
	//takes an element off the queue
	void dequeue() {
		if (isEmpty()) {
			throw std::underflow_error("Queue is empty");
		}
		fElements.remove(top());
	}
	//returns the top element of the queue
	const T& top() const {
		if (isEmpty()) {
			throw std::underflow_error("Queue is empty");
		}
		return *fElements.getIterator();
	}
};