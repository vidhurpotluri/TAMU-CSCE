#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include "heap.h" // for the _swap function
using namespace std;

int partition(int arr[], int l, int h) {
	int i = l;
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= arr[h]) { // if the number is smaller or equal to the pivot which is arr[h]
			_swap(arr[i], arr[j]); 
			i++;
		}
	}
	_swap(arr[i], arr[h]);
	return i;
}


// l is the lower index 
// h if the higher index
void quicksort(int arr[], int l, int h) {

	if (l < h) { // if there are 2 or more elements in arr[]

		// index that divides the array
		int index = partition(arr, l, h);

		// recursion to sort the subarrays divided by the pivoting point
		quicksort(arr, l, index - 1);
		quicksort(arr, index + 1, h);
	}	

}
#endif
