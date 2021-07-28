// Work on throw exceptions later

#include "stack.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;






int main()
{

	/*ArrayStack<int> as(2,2);
	as.top();
	as.push(6);
	cout << as.top();
	as.pop();
	as.pop();*/

	// Growable stack array
	ArrayStack<float> ArrayStack(1000,1000); 
	cout << "Pushing 1000000 items on to the Growable stack array: " << endl;
	//ofstream outX("ArrayStack - 1000.xls"); // writes to excel file

	int x = 0; // Counts the number of intervals 
	double elapsedTime1 = 0; // records the time
	for (int i = 1; i <= 1000000; i++) {

		// records the time if its the 1000th interval and writes to the excel file
		/*if (i%1000 == 0) { 
			//cout << "Time at interval " << x << " is " << elapsedTime1 << endl;
			outX << elapsedTime1 << endl;
			x++;
		}*/
		clock_t start1 = clock(); // starts the timer. 
		// I started the timer inside of the for loop since I don't want the elapsed time to contain the time
		// it took to go through the if statement and increment the iterator.
		ArrayStack.push(rand()); 
		clock_t end1 = clock(); // ends the timer
		elapsedTime1 += (double)(end1-start1)/CLOCKS_PER_SEC ;
	}
	//outX.close();
	cout << elapsedTime1 << " seconds" << endl;

	// Doubling stack array
	DoublingArrayStack<float> DoublingArrayStack(1000);
	cout << "Pushing 1000000 items on to the Growable stack array: " << endl;
	//ofstream outY("DoublingArrayStack.xls"); 
	int y = 0;
	double elapsedTime2 = 0; // records the time
	for (int i = 1; i <= 1000000; i++) {
		// records the time if its the 1000th interval 
		/*if (i%1000 == 0) { 
			//cout << "Time at interval " << y << " is " << elapsedTime2 << endl;
			outY << elapsedTime2 << endl;
			y++;
		}*/
		clock_t start2 = clock(); // starts the timer
		DoublingArrayStack.push(rand());
		clock_t end2 = clock(); // ends the timer
		
		elapsedTime2 += (double)(end2-start2)/CLOCKS_PER_SEC ;		
	}
	//outY.close();
	cout << elapsedTime2 << " seconds" << endl;


	// Linked list
	LinkedList<float> Linkedlist;
	cout << "Pushing 1000000 items on to the linked list based stack: " << endl;
	//ofstream outZ("LinkedList.xls");
	int z = 0; // records the interval

	double elapsedTime3 = 0; // records the time

	for (int i = 1; i <= 1000000; i++) {
		// records the time if its the 1000th interval
		/*if (i%1000 == 0) { 
			//cout << "Time at interval " << z << " is " << elapsedTime3 << endl;
			outZ << elapsedTime3 << endl;
			z++;
		}*/

		clock_t start3 = clock(); // starts the timer
		Linkedlist.push(rand());
		clock_t end3 = clock(); // ends the timer
		
		elapsedTime3 += (double)(end3-start3)/CLOCKS_PER_SEC ;	
	}
	//outZ.close();
	cout << elapsedTime3 << " seconds" << endl;


	return 0;


}