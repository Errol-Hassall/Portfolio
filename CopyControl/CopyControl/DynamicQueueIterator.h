#pragma once
#include "DynamicQueue.h"
template<class T>
class DynamicQueueIterator
{
private:
	DynamicQueue<T> fQueue;
public:
	//Constructor copies the queue to the other queue
	DynamicQueueIterator(const DynamicQueue<T>& aQueue) {
		fQueue = aQueue;
	}
	//dereference operator returns the top of the queue
	const T& operator*() {
		return fQueue.top();
	}
	//prefix increment
	DynamicQueueIterator& operator++() {
		fQueue.dequeue();
		return *this;
	}
	//postfix increment
	DynamicQueueIterator operator++(int) {
		DynamicQueueIterator temp = *this;
		++(*this);
		return temp;
	}
	//compares the two queues size for equality
	bool operator==(const DynamicQueueIterator& aOtherIter) const {
		return (fQueue.size() == aOtherIter.fQueue.size());
	}
	//compares the two quques sizes for inequality
	bool operator!=(const DynamicQueueIterator& aOtherIter) const {
		return !(*this == aOtherIter);
	}
	//returns a new queue positioned after the last element 
	DynamicQueueIterator end() const {
		DynamicQueueIterator temp = *this;
		temp.fQueue = DynamicQueue<T>();
		return temp;
	}
};