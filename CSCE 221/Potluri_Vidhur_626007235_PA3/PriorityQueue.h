#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <list>
#include <assert.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */

// Unsorted PQ Class
template <class Type>
class UnsortedPQ
{
private:
	// data here
   list<Type> upq;

public:
   // Constructor
   UnsortedPQ(){};

   // Destructor
   ~UnsortedPQ(){
      upq.clear();
      cout << "UnsortedPQ Destructor was called" << endl << endl;
   };

   // returns 1 if empty
   bool isEmpty(void){
      return upq.empty();
   }

   // returns size
   int size(void){
      return upq.size();
   }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
      upq.push_back(data);

   }

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin () {
      assert (upq.size() != 0);
      Type min = upq.front();
      typename list<Type>::iterator temp;
      for (typename list<Type>::iterator it = upq.begin(); it != upq.end(); it++){
         if (*it <= min){
            min = *it;
            temp = it;
         }
      }
      upq.erase(temp);
      return min;
   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ){
      assert (upq.size() != 0);
      Type min = upq.front();
      typename list<Type>::iterator it;
      it = upq.begin();
      while (it != upq.end()){
         if (*it < min){
            min = *it;
         }
         it++;
      }
      return min;
   }
};



// Sorted PQ Class
template <class Type>
class SortedPQ
{
private:
   // data here
   list<Type> spq;

public:
   // Constructor
   SortedPQ(){};

   // Destructor
   ~SortedPQ(){
      spq.clear();
      cout << "SortedPQ destructor was called" << endl;
   };

   // Returns 1 if empty
   bool isEmpty(void){
      return spq.empty();
   }

   // Returns size
   int size(void){
      return spq.size();
   }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
      if (spq.size() == 0)
      {
         spq.push_front(data);
      }
      else
      {
         typename list<Type>::iterator it;
         it = spq.begin();
         while (data >= *it && it != spq.end())
         {
            it++;
         }
         spq.insert(it, data);
      }

      // Debugging
      /*typename list<Type>::iterator lit;
      lit = spq.begin();
      while (lit != spq.end())
      {
         cout << *lit;
         lit++;
      }
      cout << endl;*/

   }

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin () {
      assert(spq.size()!= 0);
      Type temp = spq.front();
      spq.pop_front();
      return temp;

   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ){
      assert (spq.size() != 0);
      return spq.front();
   }
};


// HeapPQ class
template <class Type>
class HeapPQ
{
private:
   // data here
   vector<Type> pq;

public:
   HeapPQ(){};

   ~HeapPQ(){
      pq.clear();
      cout << "HeapPQ destructor was called" << endl;
   };

   bool isEmpty(){
      return pq.empty();
   }

   int size(){
      return pq.size(); 
   };

   Type parent(Type data){

   }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
      pq.push_back(data);
      int position = pq.size() - 1;
      int parentpos = floor((position - 1)/2);

      // Upheap
      while (pq[position] < pq[parentpos])
      {
         // swapping
         Type temp = pq[parentpos];
         pq[parentpos] = pq[position];
         pq[position] = temp;
         position = parentpos;
         parentpos = floor((position-1)/2);
      }

      //Debugging
      /*for (int i = 0; i < pq.size(); i++)
      {
         cout << pq[i];
      }
      cout << endl;*/
   };

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin (){
      assert(pq.size() != 0);
      int position = pq.size() - 1;

      // Desbugging
      /*cout << "Being removed: " << pq[0] << endl;
      cout << "Swapped: " << pq[position] << endl;*/

      // Swap minimum and last node

      // Debugging
      /*for (int i = 0; i < pq.size(); i++)
      {
         cout << pq[i];
      }
      cout << endl; */
      Type temp1 = pq[0];
      pq[0] = pq[position];
      pq[position] = temp1;

      Type value = pq[position];
      // Resizing
      // cout << pq.back() << endl;
      pq.pop_back();

      int parent = 0;
      int leftkid = 1;
      int rightkid = 2;

      // Downheap
      while (rightkid < pq.size()){
         // if left child node is smaller than right child node
         if (pq[leftkid] <= pq[rightkid] && pq[parent] > pq[leftkid]){  
            // swapping
            //iter_swap(pq.begin() + leftkid, pq.begin() + parent);
            Type temp = pq[parent];
            pq[parent] = pq[leftkid];
            pq[leftkid] = temp;
            parent = leftkid;
            leftkid = 2*parent + 1;
            rightkid = 2*parent + 2;
         }


            // if right child node is smaller than left child node
         else if (pq[leftkid] > pq[rightkid] && pq[parent] > pq[rightkid]){
         // swapping
         //iter_swap(pq.begin() + rightkid, pq.begin() + parent);
            Type temp = pq[parent];
            pq[parent] = pq[rightkid];
            pq[rightkid] = temp;
            parent = rightkid;
            leftkid = 2*parent + 1;
            rightkid = 2*parent + 2;
         } 

         else {
            leftkid = pq.size();
            rightkid = pq.size();
         }

         /*for (int i = 0; i < pq.size(); i++)
         {
            cout << pq[i];
         }
         cout << endl; */

         // Debugging
         /*
         cout << "parent = " << pq[parent] << endl;
         cout << "left kid = " << pq[leftkid] << endl;
         cout << "right kid = " << pq[rightkid] << endl;*/
      }
   
      //Debugging

      return value;

}

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue (){
      assert(pq.size() != 0);
      return (pq[0]);
   };
};

#endif