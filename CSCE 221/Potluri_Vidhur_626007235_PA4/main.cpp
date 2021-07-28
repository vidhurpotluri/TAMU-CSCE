#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "heapsort.h"
#include "heap.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"
using namespace std;

int main() {
    cout << "--------------------- Numbers inputted from file --------------------" << endl;
	// Reading the file to input
	char filename[] = "";
   
    cout << "Enter a file name: " ;
    cin >> filename;
   

    ifstream inFile(filename);

    // Error message if file isn't valid
    if (!inFile) {
    	cerr << "Unable to open file " << filename << endl;
    	exit(1);
    }

    int n; // Number of numbers to be sorted
    int type; // Type of sort to be used

    inFile >> type;
    inFile >> n;

    int arr[n]; // Array of numbers to be sorted

    int i = 0; // iterator
    int x;
    while (inFile >> x) {
    	arr[i] = x;
    	i++;
    }

    // choosing the type of sort
    if (type == 1) {
        bubblesort(arr, n);
        cout << "Sorting technique: bubble sort" << endl;
    }

    if (type == 2) {
        heapsort(arr, n);
        cout << "Sorting technique: heap sort" << endl;
    }

    if (type == 3) {
        mergesort(arr, 0, n - 1);
        cout << "Sorting technique: merge sort" << endl;
    }

    if (type == 4) {
        quicksort(arr, 0, n - 1);
        cout << "Sorting technique: quick sort" << endl;
    }
    i = 0;

    while (i < n) {
    	cout << arr[i] << endl;
    	i++;
    }
    
    inFile.close();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    // Runtime calculations
    // (I) Sorted inputs - 0,1,2,....10000 timed at intervals of 100
    // Bubble sort
    cout << "----------------------------- Sorted inputs ----------------------------" << endl;
    int j = 100;
    ofstream outbub1("BubbleSort-sorted.xls");
    double bub1time = 0;
    while (j <= 10000) {
        int bubbleArr[j];
        for (int i = 0; i < j; i++) {
            bubbleArr[i] = i;
        }
        clock_t startbub1 = clock();
        bubblesort(bubbleArr,j);
        clock_t endbub1 = clock();
        bub1time = (double)(endbub1-startbub1)/CLOCKS_PER_SEC  ;
        outbub1 << bub1time << endl;
        //cout << bub1time << endl;
        j += 100;
    }
    cout << "Time taken by bubble sort to sort an array of 10000 sorted elements: " << bub1time << endl;

    //Heap sort
    j = 1000;
    ofstream outheap1("HeapSort-sorted.xls");
    double heap1time = 0;
    while (j <= 100000) {
        int heapArr[j];
        for (int i = 0; i < j; i++) {
            heapArr[i] = i;
        }
        clock_t startheap1 = clock();
        heapsort(heapArr,j);
        clock_t endheap1 = clock();
        heap1time = (double)(endheap1-startheap1)/CLOCKS_PER_SEC  ;
        outheap1 << heap1time << endl;
        //cout << heap1time << endl;
        j += 1000;
    }
    cout << "Time taken by heap sort to sort an array of 100000 sorted elements: " << heap1time << endl;

    //merge sort
    j = 1000;
    ofstream outmerge1("MergeSort-sorted.xls");
    double merge1time = 0;
    while (j <= 100000) {
        int mergeArr[j];
        for (int i = 0; i < j; i++) {
            mergeArr[i] = i;
        }
        clock_t startmerge1 = clock();
        mergesort(mergeArr,0,j - 1);
        clock_t endmerge1 = clock();
        merge1time = (double)(endmerge1-startmerge1)/CLOCKS_PER_SEC  ;
        outmerge1 << merge1time << endl;
        //cout << merge1time << endl;
        j += 1000;
    }
    cout << "Time taken by merge sort to sort an array of 100000 sorted elements: " << merge1time << endl;

    // Quick sort
    j = 100;
    ofstream outquick1("QuickSort-sorted.xls");
    double quick1time = 0;
    while (j <= 10000) {
        int quickArr[j];
        for (int i = 0; i < j; i++) {
            quickArr[i] = i;
        }
        clock_t startquick1 = clock();
        quicksort(quickArr,0,j-1);
        clock_t endquick1 = clock();
        quick1time = (double)(endquick1-startquick1)/CLOCKS_PER_SEC  ;
        outquick1 << quick1time << endl;
        //cout << quick1time << endl;
        j += 100;
    }
    cout << "Time taken by quick sort to sort an array of 10000 sorted elements: " << quick1time << endl;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // (II) Reverse sorted inputs - 10000,9999,...0 timed at intervals of 100
    // Bubble sort
    cout << "----------------------------- Reverse sorted inputs ----------------------------" << endl;
    j = 9900;
    ofstream outbub2("BubbleSort-rsorted.xls");
    double bub2time = 0;
    while (j >= 0) {
        int bubbleArr[10000-j];
        for (int i = 10000; i > j; i--) {
            bubbleArr[10000 - i] = i;
        }
        clock_t startbub2 = clock();
        bubblesort(bubbleArr,10000 - j);
        clock_t endbub2 = clock();
        bub2time = (double)(endbub2-startbub2)/CLOCKS_PER_SEC  ;
        outbub2 << bub2time << endl;
        //cout << bub2time << endl;
        j -= 100;
    }
    cout << "Time taken by bubble sort to sort an array of 10000 reverse sorted elements: " << bub2time << endl;

    //Heap sort
    j = 99000;
    ofstream outheap2("HeapSort-rsorted.xls");
    double heap2time = 0;
    while (j >= 0) {
        int heapArr[100000-j];
        for (int i = 100000; i > j; i--) {
            heapArr[100000 - i] = i;
        }
        clock_t startheap2 = clock();
        heapsort(heapArr,100000 - j);
        clock_t endheap2 = clock();
        heap2time = (double)(endheap2-startheap2)/CLOCKS_PER_SEC  ;
        outheap2 << heap2time << endl;
        //cout << heap2time << endl;
        j -= 1000;
    }
    cout << "Time taken by heap sort to sort an array of 100000 reverse sorted elements " << heap2time << endl;

    // merge sort
    j = 99000;
    ofstream outmerge2("MergeSort-rsorted.xls");
    double merge2time = 0;
    while (j >= 0) {
        int mergeArr[100000 - j];
        for (int i = 100000; i > j; i--) {
            mergeArr[100000 - i] = i;
        }
        clock_t startmerge2 = clock();
        mergesort(mergeArr,0,99999-j);
        clock_t endmerge2 = clock();
        merge2time = (double)(endmerge2-startmerge2)/CLOCKS_PER_SEC  ;
        outmerge2 << merge2time << endl;
        //cout << merge1time << endl;
        j -= 1000;
    }
    cout << "Time taken by merge sort to sort an array of 100000 reverse sorted elements " << merge2time << endl;

    // Quick sort
    j = 9900;
    ofstream outquick2("QuickSort-rsorted.xls");
    double quick2time = 0;
    while (j >= 0) {
        int quickArr[10000 - j];
        for (int i = 10000; i > j; i--) {
            quickArr[10000 - i] = i;
        }
        clock_t startquick2 = clock();
        quicksort(quickArr,0,9999-j);
        clock_t endquick2 = clock();
        quick2time = (double)(endquick2-startquick2)/CLOCKS_PER_SEC  ;
        outquick2 << quick2time << endl;
        //cout << quick1time << endl;
        j -= 100;
    }
    cout << "Time taken by quick sort to sort an array of 10000 reverse sorted elements " << quick2time << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // (III) Random inputs of size 100000 timed at size intervals of 100
    // Bubble sort
    cout << "----------------------------- Random inputs ----------------------------" << endl;
    j = 100;
    ofstream outbub3("BubbleSort-random.xls");
    double bub3time = 0;
    while (j <= 10000) {
        int bubbleArr[j];
        for (int i = 0; i < j; i++) {
            int x = rand();
            bubbleArr[i] = x;
        }
        clock_t startbub3 = clock();
        bubblesort(bubbleArr,j);
        clock_t endbub3 = clock();
        bub3time = (double)(endbub3-startbub3)/CLOCKS_PER_SEC  ;
        outbub3 << bub3time << endl;
        //cout << bub3time << endl;
        j += 100;
    }
    cout << "Time taken by bubble sort to sort an array of 10000 random elements: " << bub3time << endl;

    //Heap sort
    j = 1000;
    ofstream outheap3("HeapSort-random.xls");
    double heap3time = 0;
    while (j <= 100000) {
        int heapArr[j];
        for (int i = 0; i < j; i++) {
            int x = rand();
            heapArr[i] = x;
        }
        clock_t startheap3 = clock();
        heapsort(heapArr,j);
        clock_t endheap3 = clock();
        heap3time = (double)(endheap3-startheap3)/CLOCKS_PER_SEC  ;
        outheap3 << heap3time << endl;
        //cout << heap3time << endl;
        j += 1000;
    }
    cout << "Time taken by heap sort to sort an array of 100000 random elements: " << heap3time << endl;

    //merge sort
    j = 1000;
    ofstream outmerge3("MergeSort-random.xls");
    double merge3time = 0;
    while (j <= 100000) {
        int mergeArr[j];
        for (int i = 0; i < j; i++) {
            int x = rand();
            mergeArr[i] = x;
        }
        clock_t startmerge3 = clock();
        mergesort(mergeArr,0,j - 1);
        clock_t endmerge3 = clock();
        merge3time = (double)(endmerge3-startmerge3)/CLOCKS_PER_SEC  ;
        outmerge3 << merge3time << endl;
        //cout << merge3time << endl;
        j += 1000;
    }
    cout << "Time taken by merge sort to sort an array of 100000 random elements: " << merge3time << endl;

    // Quick sort
    j = 100;
    ofstream outquick3("QuickSort-random.xls");
    double quick3time = 0;
    while (j <= 10000) {
        int quickArr[j];
        for (int i = 0; i < j; i++) {
            int x = rand();
            quickArr[i] = x;
        }
        clock_t startquick3 = clock();
        quicksort(quickArr,0,j-1);
        clock_t endquick3 = clock();
        quick3time = (double)(endquick3-startquick3)/CLOCKS_PER_SEC  ;
        outquick3 << quick3time << endl;
        //cout << quick3time << endl;
        j += 100;
    }
    cout << "Time taken by quick sort to sort an array of 10000 random elements: " << quick3time << endl;
    */




    return 0;
}