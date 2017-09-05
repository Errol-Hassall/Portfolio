#include "DoublyLinkedNode.h"
#include <iostream>
#include <string>
#include "DoublyLinkedNodeIterator.h"
using namespace std;

void test1()
{
	string s1("One");
	string s2("Two");
	string s3("Three");
	string s4("Four");
	typedef DoublyLinkedNode<string>::Node StringNode;
	StringNode n1(s1);
	StringNode n2(s2);
	StringNode n3(s3);
	StringNode n4(s4);
	cout << "Test append:" << endl;
	n1.append(n4);
	n1.append(n3);
	n1.append(n2);
	cout << "Three elements:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
	n2.remove();
	cout << "Two elements:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
}

void test2()
{
	string s1("One");
	string s2("Two");
	string s3("Three");
	string s4("Four");
	typedef DoublyLinkedNode<string>::Node StringNode;
	StringNode n1(s1);
	StringNode n2(s2);
	StringNode n3(s3);
	StringNode n4(s4);
	cout << "Test prepend:" << endl;
	n4.prepend(n1);
	n4.prepend(n2);
	n4.prepend(n3);
	cout << "Three elements:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
	n3.remove();
	cout << "Two elements:" << endl;
	for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = &pn->getNext())
	{
		cout << "(";
		if (&pn->getPrevious() != &StringNode::NIL)
			cout << pn->getPrevious().getValue();
		else
			cout << "<NULL>";
		cout << "," << pn->getValue() << ",";
		if (&pn->getNext() != &StringNode::NIL)
			cout << pn->getNext().getValue();
		else
			cout << "<NULL>";
		cout << ")" << endl;
	}
}

void testDoublyLinkedNodeIterator()
{
	typedef DoublyLinkedNode<int>::Node IntNode;
	IntNode n1(1);
	IntNode n2(2);
	IntNode n3(3);
	IntNode n4(4);
	IntNode n5(5);
	IntNode n6(6);
	n1.append(n6);
	n1.append(n5);
	n1.append(n4);
	n1.append(n3);
	n1.append(n2);
	DoublyLinkedNodeIterator<int> iter(n1);
	iter--;
	cout << "Forward iteration I:" << endl;
	for (iter++; iter != iter.end(); iter++)
		cout << *iter << endl;
	cout << "Backward iteration I:" << endl;
	for (iter--; iter != iter.rend(); iter--)
		cout << *iter << endl;
	cout << "Forward iteration II:" << endl;
	for (iter = iter.begin(); iter != iter.end(); ++iter)
		cout << *iter << endl;
	cout << "Backward iteration II:" << endl;
	for (iter = iter.rbegin(); iter != iter.rend(); --iter)
		cout << *iter << endl;
	DoublyLinkedNodeIterator<int> iter2(DoublyLinkedNode<int>::NIL);

	if (iter2 == iter2.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (iter2.begin() == iter2.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	if (iter2.rbegin() == iter2.rend())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	//test1();

	//test2();

	testDoublyLinkedNodeIterator();

	return 0;
}