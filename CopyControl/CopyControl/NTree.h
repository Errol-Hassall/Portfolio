
// COS30008, Problem Set 7, 2017

#pragma once

#include <stdexcept>

#include "TreeVisitor.h"
#include "DynamicQueue.h"

template<class T, int N>
class NTree
{
private:
	const T* fKey;              // 0 for empty NTree
	NTree<T, N>* fNodes[N];      // N subtress of degree N

	NTree();                    // sentinel constructor

public:
	static NTree<T, N> NIL;      // sentinel

	NTree(const T& aKey);     // a simple NTree with key and N subtrees of degree N

	bool isEmpty() const;       // is tree empty
	const T& key() const;       // get key (node value)

								// indexer (allow for result modification by client - no const in result)
	NTree& operator[](unsigned int aIndex) const;

	// tree manipulators (using constant references)
	void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree);
	const NTree& detachNTree(unsigned int aIndex);

	// depth-first traversal
	void traverseDepthFirst(const TreeVisitor<T>& aVisitor) const;

	// Copy Control
	NTree(const NTree& aOtherNTree) {
		fKey = aOtherNTree.fKey;
		for (int i = 0; i < N; i++)
		{
			if (aOtherNTree.fNodes[i] != &NIL) {
				fNodes[i] = new NTree<T, N>(*aOtherNTree.fNodes[i]);
			}
			else
			{
				fNodes[i] = &NIL;
			}
		}
	}
	//Deconstructor for NTree
	~NTree() {
		for (int i = 0; i < N; i++)
		{
			if (fNodes[i] != &NIL) {
				delete fNodes[i];
			}
		}
	}
	//Comparison operator
	NTree& operator=(const NTree& aOtherNTree) {
		if (this != &aOtherNTree)
		{
			for (int i = 0; i < N; i++) {
				if (fNodes[i] != &NIL)
				{
					delete fNodes[i];
				}
			}
			fKey = aOtherNTree.fKey;
			for (int i = 0; i < N; i++)
			{
				if (aOtherNTree.fNodes[i] != &NIL) {
					fNodes[i] = new NTree<T, N>(*aOtherNTree.fNodes[i]);
				}
				else
				{
					fNodes[i] = &NIL;
				}
			}
		}
	}

	// breadth-first traversal
	//Uses pointers to avoid deep copies
	//It will then start with the root node 
	//working its way out checking for unvisited nodes
	void traverseBreadthFirst(const TreeVisitor<T>& aVisitor) const {
		DynamicQueue<const NTree<T, N>*> lQueue;
		if (!isEmpty())
		{
			lQueue.enqueue(this);
		}

		while (!lQueue.isEmpty())
		{
			const NTree<T, N>* head = lQueue.top();
			lQueue.dequeue();
			if (!head->isEmpty())
			{
				aVisitor.visit(head->key());

				for (unsigned i = 0; i < N; i++)
				{
					if (head->fNodes[i] != &NIL) {
						lQueue.enqueue((const NTree<T, N>*)head->fNodes[i]);
					}
				}
			}
		}
	}
};


// implementation

template<class T, int N>
NTree<T, N> NTree<T, N>::NIL;


// sentinel constructor
template<class T, int N>
NTree<T, N>::NTree()
{
	fKey = (T*)0;
	for (int i = 0; i < N; i++)
		fNodes[i] = &NIL;
}

// node constructor
template<class T, int N>
NTree<T, N>::NTree(const T& aKey)
{
	fKey = &aKey;
	for (int i = 0; i < N; i++)
		fNodes[i] = &NIL;
}

// isEmpty
template<class T, int N>
bool NTree<T, N>::isEmpty() const
{
	return this == &NIL;
}

// key
template<class T, int N>
const T& NTree<T, N>::key() const
{
	if (!isEmpty())
		return *fKey;
	else
		throw std::domain_error("Empty NTree.");
}

// indexer
template<class T, int N>
NTree<T, N>& NTree<T, N>::operator[](unsigned int aIndex) const
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");

	if (aIndex < N && fNodes[aIndex] != &NIL)
	{
		return *fNodes[aIndex];		// return reference to subtree			
	}
	else
		throw std::out_of_range("Illegal subtree index!");
}

// tree manipulators
template<class T, int N>
void NTree<T, N>::attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");

	if (aIndex < N)
	{
		if (fNodes[aIndex] != &NIL)
			throw std::domain_error("Non-empty subtree present!");

		fNodes[aIndex] = (NTree<T, N>*)&aNTree;
	}
	else
		throw std::out_of_range("Illegal subtree index!");
}

template<class T, int N>
const NTree<T, N>& NTree<T, N>::detachNTree(unsigned int aIndex)
{
	if (isEmpty())
		throw std::domain_error("Empty NTree!");

	if ((aIndex < N) && fNodes[aIndex] != &NIL)
	{
		const NTree<T, N>& Result = *fNodes[aIndex]; // obtain reference to subtree
		fNodes[aIndex] = &NIL;						// set to NIL
		return Result;                              // return subtree (reference)
	}
	else
		throw std::out_of_range("Illegal subtree index!");
}


template<class T, int N>
void NTree<T, N>::traverseDepthFirst(const TreeVisitor<T>& aVisitor) const
{
	// visit every subtree (no invisit)
	if (!isEmpty())
	{
		aVisitor.preVisit(key());
		for (unsigned int i = 0; i < N; i++)
		{
			fNodes[i]->traverseDepthFirst(aVisitor);
		}
		aVisitor.postVisit(key());
	}
}


