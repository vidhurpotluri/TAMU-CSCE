#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
using namespace std;


// Merges two sorted subarrays into the main sorted array.
void merge(int arr[], int l, int r, int m) {
	int size1 = m-l;
	int size2 = r-m+1;

	int left[size1];
	int right[size2];

	// Copying the values in the array to the left and right subarrays
	for (int i = 0; i < size1; i++) {
		left[i] = arr[l+i];
	}

	for (int j = 0; j < size2; j++) {
		right[j] = arr[m+j];
	}

	int i = 0;
	int j = 0;

	// merging the two subarrays back into the array while sorting
	while (i < size1 && j < size2) {
		if (left[i] <= right[j]) {
			arr[l+i+j] = left[i];
			i++;
		}

		else {
			arr[l+i+j] = right[j];
			j++;
		}
	}

	// Copying any remaining elements into the main array 
	while (i < size1) {
		arr[l+i+j] = left[i];
		i++;
	}

	while (j < size2) {
		arr[l+
			i+j] = right[j];
		j++;
	}
	/* Debugging
	for (int a = 0; a < sizeof(arr); a++) {
		cout << arr[a];
	}
	cout << endl;*/
	
}

// Recursive function that uses the merge function to sort an array
// left: left index of the array
// right: right index of the array
void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m; // starting index of the right subarray
		if (sizeof(arr)%2 == 0) {
			m = (l+r+1)/2;
		}
		else {
			m = (l+r)/2;
		}
		// Debugging
		//cout << "l: " << l << endl;
		//cout << "r: " << r << endl;
		mergesort(arr,l,m-1);
		mergesort(arr,m,r);

		merge(arr,l,r,m);
	}

}

#endif