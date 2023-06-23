/*
  Quiz 7: Extract Max

  Write C++ code for a function, extractMax() that takes as input 
  a max heap, arr represented as an integer array and the size of 
  the array, size. The function deletes the maximum element in the 
  max heap and returns the new max heap array after deletion.

  Sample Input:
    3
    9 8 7
  
  Sample Output:
    8 7
		
	Explanation:

	Input:  Line 1 denotes the number of elements, size in the 
            heap. Line 2 denotes the contents of the max heap 
            that is passed into extractMax() function.
	
	Output: Output is the max heap after deletion.
*/

#include <iostream>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int* extractMax(int arr[], int size) {
  int lastElement = arr[size - 1];
  arr[0] = lastElement;
  size = size - 1;
  heapify(arr, size, 0);
	return arr; 
}
