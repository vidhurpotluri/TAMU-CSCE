#pragma once

#include "Node.h"
#include <assert.h>

template <class Type> // Template for any class of numbers
class Deque {
private:
    int s; // size of deque
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
    // Constructor function
	Deque() {
        firstNode = NULL;
        lastNode = NULL;
        s = 0;
	}

    //Destructor function
	~Deque() {
        delete firstNode;
        delete lastNode;
       	s = 0;
	}
	
    // Returns 1 if deque is empty
	bool isEmpty() {
        //assert(false);
        return (s == 0);
	}

    // Returns size of the deque
	int size() {
        //assert(false);
        return s;
	}

    // Returns first node
	Type first() {
        assert(s != 0);
        return firstNode->getData();
	}

    //Returns last node
	Type last() {
        assert(s != 0);
        return lastNode -> getData();
	}

    // Inserts number at the beginning of the deque
	void insertFirst(Type o) {

        if (s == 0) // first element in the deque
        {
        	Node<Type>* temp = new Node<Type>(o); // new temporary pointer with data o
        	firstNode = temp;
        	lastNode = temp;
        	s++;
        }
        else // if deque isn't empty
        {
        	Node<Type>* temp = new Node<Type>(o); // new temporary pointer with data o
        	temp->setNext(firstNode);
        	firstNode->setPrev(temp);
        	firstNode = temp;
        	s++;
        }
	}

    // Inserts number at the end of the deque
	void insertLast(Type o) {
        //assert(false);
        if (s == 0) // first element in the deque
        {
			Node<Type>* temp = new Node<Type>(o); // new temporary pointer with data o
        	firstNode = temp;
        	lastNode = temp;
        	s++;
        }
        else // if deque isn't empty
        {
        	Node<Type>* temp = new Node<Type>(o); // new temporary pointer with data o 
        	temp->setPrev(lastNode);
        	lastNode->setNext(temp);
        	lastNode = temp;
        	s++;
        }

	}
	
    // Removes node at the front of the deque
	Type removeFirst() {
        assert(s != 0); // checks if deque is empty
        Node<Type>* temp = new Node<Type>(firstNode->getData());
		if (s == 1) // if there's only 1 node in deque
		{
			firstNode = NULL;
		}
		else
		{
			firstNode = firstNode->getNext();
			firstNode->setPrev(NULL);
		}
		s--;
        //cout << temp->getData() << endl; // Debugging
		return temp->getData();      
	}

    // Removes node at the end of the deque
	Type removeLast() {
        assert(s != 0); // checks if deque is empty
		Node<Type>* temp = new Node<Type>(lastNode->getData());
		if (s == 1) // if there's only 1 node in deque
		{
			lastNode = NULL;
		}
		else
		{
			lastNode = lastNode->getPrev();
			lastNode->setNext(NULL); 
		}
		s--; 
        // cout << temp->getData() << endl; // Debugging
		return temp->getData();
	}
};