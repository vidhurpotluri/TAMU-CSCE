#include <iostream>
#include <thread>
#include <stdlib.h>
#include "Semaphore.h"
#include <vector>
#include <unistd.h>
#include <cstdlib>
using namespace std;


#define B 2


Semaphore Asem (1);
Semaphore Bsem (0);
Semaphore Csem (0);
Semaphore mtx(1);
int Bdone = 0;
void threadA (int ano){
	while (true){
		Asem.P();

		mtx.P();
		cout << "Thread A" << endl << endl;
		mtx.V();
		
		for (int i = 0; i < B; i++) {
			Bsem.V();
		}
	}
}

void threadB (int bno){
	while (true){
		//do necessary wait
		Bsem.P();

		// each consumer reads the buffer		
		// you should not need to change this block
		mtx.P();
		cout << "Thread B" << " " << endl;
		mtx.V();
		usleep (500000);

		// now do whatever necessary that would indicate that the consumers are all done
		mtx.P();
		Bdone ++;
		if (Bdone == B){ // it is the last one 
			cout << endl;
			Csem.V(); // so wake up the producer
			Bdone = 0; // reset the counter
		}
		mtx.V();
	}
}

void threadC (int ano){
	while (true){
		Csem.P();

		mtx.P();
		cout << "Thread C" << endl << endl;
		mtx.V();
		
		Asem.V();
	}
}

int main (){
	vector<thread> As;
	vector<thread> Bs;
	vector<thread> Cs;

	for (int i=0; i< 100; i++)
		As.push_back (thread (threadA, i+1));

	for (int i=0; i< 200; i++)
		Bs.push_back(thread (threadB, i+ 1));

	for (int i=0; i< 100; i++)
		Cs.push_back(thread (threadC, i+ 1));

	
	for (int i=0; i<As.size (); i++)
		As [i].join();
	
	for (int i=0; i<Bs.size (); i++)
		Bs [i].join();

	for (int i=0; i<Cs.size (); i++)
		Cs [i].join();
	
}
