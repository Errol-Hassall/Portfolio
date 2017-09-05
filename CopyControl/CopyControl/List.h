
// COS30008, Problem Set 6, 2017

#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"                         
                            // your solution PS6

#include <stdexcept>

template<class T> 
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fTop;		// the first element in the list
	Node* fLast;	// the last element in the list
	int fCount;		// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    typedef DoublyLinkedNodeIterator<T> Iterator;
    
	List()
	{
		fTop = &Node::NIL;					// initialize top
		fLast = &Node::NIL;					// initialize last
		fCount = 0;							// initialize count
	}// default constructor - creates empty list
	~List() {
		while (fTop != &Node::NIL)
		{
			Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
			fTop->remove();                         // move first node
			delete fTop;							// free node memory
			fTop = temp;	// make temp the new top
		}
	}// destructor - frees all nodes

    //copy constructor deep copies one list to another if the object has not 
	//been created yet
	List(const List& aOtherList)
	{
		// initialize this list
		fTop = &Node::NIL;					// initialize top                           // 2
		fLast = &Node::NIL;					// initialize last                          // 2
		fCount = 0;							// initialize count                         // 1

											// copy aOtherList
		for (Iterator iter = aOtherList.getIterator(); iter != iter.end(); iter++)
			push_back(*iter);                                                         // 5/10
	}
	// copy constructor deep copies one list to another if the object has been created
	List<T>& operator=(const List& aOtherList)
	{
		if (&aOtherList != this)                                                      // 2
		{
			// delete this list
			while (fTop != &Node::NIL)
			{
				Node* temp = (Node *)&fTop->getNext();  // get next node (to become top)
				fTop->remove();                         // move first node
				delete fTop;							// free node memory
				fTop = temp;							// make temp the new top
			}                                                                           // 5

																						// initialize this list
			fTop = &Node::NIL;					// initialize top
			fLast = &Node::NIL;					// initialize last
			fCount = 0;							// initialize count

												// copy aOtherList
			for (Iterator iter = aOtherList.getIterator(); iter != iter.end(); iter++)
				push_back(*iter);                                                     // 5
		}

		return *this;                                                                   // 1/13
	}


	bool isEmpty() const
	{
		return fTop == &Node::NIL;
	}// Is list empty?
	int size() const
	{
		return fCount;
	}		// list size

	void push_front( const T& aElement )
	{
		Node* lNewElement = new Node(aElement);	// create a new node

		if (fTop == &Node::NIL)					// Is this the first node?
		{
			fTop = lNewElement;						// make lNewNode first node
			fLast = lNewElement;					// make lNewNode last node as well
		}
		else
		{
			fTop->prepend(*lNewElement);          // make lNewElement previous of top
			fTop = lNewElement;						// make lNewNode first node
		}

		fCount++;									// increment count
	}												// adds a node initialized with aElement at front
	void push_back( const T& aElement )
	{
		Node* lNewElement = new Node(aElement);	// create a new node

		if (fTop == &Node::NIL)					// Is this the first node?
		{
			fTop = lNewElement;						// make lNewNode first node
			fLast = lNewElement;					// make lNewNode last node as well
		}
		else
		{
			fLast->append(*lNewElement);          // make lNewElement next of last
			fLast = lNewElement;					// make lNewNode last node
		}

		fCount++;									// increment count
	}												// adds a node initialized with aElement at back
	
	void remove( const T& aElement )
	{
		Node* lNode = fTop;							// start from the top

		while (lNode != &Node::NIL)				// Are there still nodes available?
		{
			if (lNode->getValue() == aElement)	// Have we found the node?
				break;								// stop the search
			lNode = (Node *)&lNode->getNext();      // move to next node
		}

		// At this point we have either reached the end or found the node.
		if (lNode != &Node::NIL)						// We have found the node.
		{
			if (lNode == fTop)						// Was it the first node?
			{
				fTop = (Node *)&lNode->getNext();		// set top to next of node
			}
			if (lNode == fLast)						// Was it the last node?
			{
				fLast = (Node *)&lNode->getPrevious();	// set last to previous of node
			}

			lNode->remove();							// isolate node
			delete lNode;								// release node's memory
			fCount--;									// decrement count
		}
	}													// remove node that matches aElement from list

	const T& operator[]( unsigned int aIndex ) const
	{
		if (aIndex < fCount)                                  // Is index within bounds?
		{
			Node* lNode = fTop;									// start from the top
			while (aIndex)									// Have we reached the index?
			{
				// No
				aIndex--;										// decrement index
				lNode = (Node*)&lNode->getNext();				// move to next node
			}
			// Yes
			return lNode->getValue();							// return node value
		}
		else
		{
			throw std::range_error("Index out of bounds.");	// signal error
		}
	}														// list indexer
	
	Iterator getIterator() const
	{
		return Iterator(*fTop);					// return a node iterator
	}											// return an iterator for the nodes of the list
};


