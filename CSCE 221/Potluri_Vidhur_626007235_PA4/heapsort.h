#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "heap.h"
using namespace std;

void heapsort(int arr[], int size){
	Heap<int> heap(size); // heap declaration

	// Inserting the numbers into the heap
	int i = 0;
	while (i < size){
	heap.insertElement(arr[i]);
	i++;
	}

	// Inserting the sorted numbers from the heap back into the array
	i = 0;
	while (i < size){
	arr[i] = heap.removeMin();
	i++;
	}
}

#endif
