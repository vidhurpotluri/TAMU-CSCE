#ifndef ABSTRACT
#define ABSTRACT AbstractStack<Type>
#include <iostream>

// Template class
template <class Type>
class AbstractStack
{
protected:
   // data goes here
   int t;
   int sz; // array size
   Type* arr; // array


public:
	// Constructor function
   AbstractStack(int n): sz(n) {
      t = -1;
   	arr = new Type[sz]; // array initialization
   }

   // Destructor
   ~AbstractStack() {}

   // returns 1 if stack is empty
   bool isEmpty() {
   	return t < 0;
   }

   // returns size of stack
   int size() {
   	return t + 1;
   }

   // returns number at the top of the stack
   Type top() {
      try {
   	  if (isEmpty() == 1)
   		throw arr;
   	  else
   		 return arr[t];
      }
      catch (Type* e) {
         std::cout << "Stack is empty!!" << std::endl;
      }
   }

   // returns and deletes 
   Type pop() {
      try {
        if (isEmpty() == 1)
         throw arr;
        else{
         t = t - 1;
         return arr[t+1];
         }
      }
      catch (Type* e) {
         std::cout << "Stack is empty!!" << std::endl;
      }
   }

   void pushAssist (Type e){
   	//Debugging: std::cout << t << std::endl;
   	t = t + 1;
   	arr[t] = e;
   }
   
   // virtual so it can be changed later for the derived classes.
   virtual void push (Type e) = 0;
};

template <class Type>

class ArrayStack : public AbstractStack<Type> {
private:
	// Incrementor
	int i;

public:
	// Constructor
	ArrayStack(int x, int n) : AbstractStack<Type>(x), i(n) {};
	~ArrayStack() {};

	// 
	void push(Type e) {
		if (this->size() == this->sz){
         Type* temp = new Type[this->sz + i]; // temporary array
			int a = 0; // iterator
			while (a < this->sz){
				temp[a] = this->arr[a];
				//std::cout << STACKARRAY::arr[a] << std::endl; // debuggin
				a++;
			}
			delete [] this->arr; // deletes the old array
         this->arr = temp;
         this->sz = this->sz + i;



		}
		this->pushAssist(e);
	}
};	


template <class Type>
class DoublingArrayStack: public AbstractStack<Type> {
private:

public:
   // Constructor
   DoublingArrayStack(int x) : AbstractStack<Type>(x) {};
   ~DoublingArrayStack() { };

   // 
   void push(Type e) {
      if (this->size() == this->sz){
         Type* temp = new Type[this->sz+this->sz]; // temporary array
         int a = 0; // iterator
         while (a < this->sz){
            temp[a] = this->arr[a];
            //std::cout << STACKARRAY::arr[a] << std::endl; // debuggin
            a++;
         }
         delete [] this->arr; // deletes the old array
         this->arr = temp;
         this->sz = this->sz + this->sz;



      }
      this->pushAssist(e);
   }


};



#endif
