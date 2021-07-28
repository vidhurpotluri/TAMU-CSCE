#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{


	//UnsortedPQ
	
	UnsortedPQ<int> uupq;
	cout << "Inserting and removing 100,000 items from the UnsortedPQ:" << endl;
	//ofstream outD("UnsortedPQ - insertremove100000.xls");
	int d = 0; // records the interval

	double elapsedTimeD = 0; // records the time

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << d << " is " << elapsedTimeD << endl;
			outD << elapsedTimeD << endl;
			d++;
		}*/
		

		clock_t startD = clock(); // starts the timer
		uupq.insertItem(rand());
		clock_t endD = clock(); // ends the timer
		
		elapsedTimeD += (double)(endD-startD)/CLOCKS_PER_SEC ;	
	}

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << d << " is " << elapsedTimeD << endl;
			outD << elapsedTimeD << endl;
			d++;
		}
		*/
	
		clock_t startD = clock(); // starts the timer
		uupq.removeMin();
		clock_t endD = clock(); // ends the timer
		
		elapsedTimeD += (double)(endD-startD)/CLOCKS_PER_SEC ;	
	}

	//outD.close();
	cout << elapsedTimeD << " seconds" << endl;		


	SortedPQ<int> sspq;
	cout << "Inserting and removing 100,000 items from the SortedPQ:" << endl;
	//ofstream outE("SortedPQ - insertremove100000.xls");
	int e = 0; // records the interval

	double elapsedTimeE = 0; // records the time

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << e << " is " << elapsedTimeE << endl;
			outE << elapsedTimeE << endl;
			e++;
		}*/
		

		clock_t startE = clock(); // starts the timer
		sspq.insertItem(rand());
		clock_t endE = clock(); // ends the timer
		
		elapsedTimeE += (double)(endE-startE)/CLOCKS_PER_SEC ;	
	}

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << e << " is " << elapsedTimeE << endl;
			outE << elapsedTimeE << endl;
			e++;
		}
		*/

		clock_t startE = clock(); // starts the timer
		sspq.removeMin();
		clock_t endE = clock(); // ends the timer
		
		elapsedTimeE += (double)(endE-startE)/CLOCKS_PER_SEC ;	
	}

	//outE.close();
	cout << elapsedTimeE << " seconds" << endl;	

	HeapPQ<int> hpq;
	cout << "Inserting and removing 100,000 items from the HeapPQ:" << endl;
	//ofstream outF("HeapPQ - insertremove100000.xls");
	int f = 0; // records the interval

	double elapsedTimeF = 0; // records the time

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << f << " is " << elapsedTimeF << endl;
			outF << elapsedTimeF << endl;
			f++;
		}*/
		

		clock_t startF = clock(); // starts the timer
		hpq.insertItem(rand());
		clock_t endF = clock(); // ends the timer
		
		elapsedTimeF += (double)(endF-startF)/CLOCKS_PER_SEC ;	
	}

	for (int i = 1; i <= 100000; i++) {
		
		// records the time if its the 1000th interval
		/*
		if (i%1000 == 0) { 
			cout << "Time at interval " << f << " is " << elapsedTimeF << endl;
			outF << elapsedTimeF << endl;
			f++;
		}*/


		clock_t startF = clock(); // starts the timer
		hpq.removeMin();
		clock_t endF = clock(); // ends the timer
		
		elapsedTimeF += (double)(endF-startF)/CLOCKS_PER_SEC ;	
	}

	//outE.close();
	cout << elapsedTimeF << " seconds" << endl;	
	
	/*	
	UnsortedPQ<int> upq;
	cout << "UnsortedPQ" << endl;
	cout << upq.isEmpty() << endl;
	upq.insertItem(4);
	upq.insertItem(1);
	upq.insertItem(6);
	upq.insertItem(9);
	upq.insertItem(0);
	cout << upq.size() << endl;
	cout << upq.removeMin() << endl;
	cout << upq.removeMin() << endl;
	cout << upq.removeMin() << endl;
	cout << upq.removeMin() << endl;
	cout << upq.removeMin() << endl;
	upq.insertItem(-2);
	cout << upq.minValue() << endl;
	cout << upq.minValue() << endl << endl;

	SortedPQ<int> spq;
	cout << "SortedPQ" << endl;
	cout << spq.isEmpty() << endl;
	spq.insertItem(4);
	spq.insertItem(1);
	spq.insertItem(6);
	spq.insertItem(9);
	spq.insertItem(0);
	cout << spq.size() << endl;
	cout << spq.removeMin() << endl;
	cout << spq.removeMin() << endl;
	cout << spq.removeMin() << endl;
	cout << spq.removeMin() << endl;
	cout << spq.removeMin() << endl;
	spq.insertItem(-2);
	cout << spq.minValue() << endl;
	cout << spq.minValue() << endl << endl;

	HeapPQ<int> hpq;
	cout << "Heap PQ" << endl;
	cout << hpq.isEmpty() << endl;
	hpq.insertItem(4);
	hpq.insertItem(1);
	hpq.insertItem(6);
	hpq.insertItem(9);
	hpq.insertItem(0);

	cout << hpq.size() << endl;
	cout << hpq.removeMin() << endl;
	cout << hpq.removeMin() << endl;
	cout << hpq.removeMin() << endl;
	cout << hpq.removeMin() << endl;
	cout << hpq.removeMin() << endl;
	hpq.insertItem(-2);
	cout << hpq.minValue() << endl << endl;*/



}