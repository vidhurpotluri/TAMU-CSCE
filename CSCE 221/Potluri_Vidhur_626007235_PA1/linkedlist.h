#include <iostream>
using namespace std;

//Template class for individual nodes of the linked list
template <class T>
class Node {
public:
	T elem;
	Node<T> *next;	
	Node(T i): elem(i) {};
	Node() {};
};

// Template class for linked list
template <class T>
class LinkedList {
private:

	int n; // number of items in the list
	Node<T>* front; // First item in the list
public:

	// Constructor function
	LinkedList() {
		n = 0;
		front = NULL;
	}

	// Destructor function
	~LinkedList() {
		delete front;
	}

	int size(){
		return n;
	}

	// Checks if stack is empty
	bool empty() {
		return n == 0;
	}

	// Pushes elements to the front of the list
	void push(Node<T> e) {
		Node<T> *temp = new Node<T>; // Temporary pointer to the item being pushed on to the stack
		temp->elem = e.elem;
		temp->next = NULL;
		n++;
		if (front == NULL) // if list is empty
			front = temp;
		else {
			temp->next = front;
			front = temp;
		}

	}

	// Returns the element at the top of the stack
	Node<T>* top() {
		//cout << front->elem; // Debugging
		return front;

	}

	// Deletes the element at the top of the stack
	void pop() {
		if (empty() == 1) // if the stack is empty
			std::cout << "Empty";
		else {
			n--;
			Node<T>* temp = new Node<T>; // Temporary pointer to delete the front element
			temp = front;
			front = front->next;
			delete temp;
		}

	}


};