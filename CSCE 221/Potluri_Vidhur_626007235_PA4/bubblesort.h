#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include "heap.h"
using namespace std;

void bubblesort(int arr[], int n){
	bool swapped = true; // l = 1 if its sorted
	while (swapped != false){
		swapped = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i+1] < arr[i]){
				_swap(arr[i+1], arr[i]);
				swapped = true;
			}

		}
	}
}

#endif
