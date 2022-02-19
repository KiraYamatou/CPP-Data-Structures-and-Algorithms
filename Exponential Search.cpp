/// Exponential Search Algorithm
/// C++ 
#include <iostream>
#include <stdio.h>

using namespace std;

int binarySearch(int arr[], int, int, int);

//Integer function for finding minimum of two numbers
int min(int x, int y) {
	return (x < y) ? x : y;
}

int binarySearch(int arr[], int low, int high, int x) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;

	if (x == arr[mid]) {
		return mid;
	}
	else if (x < arr[mid]) {
		return binarySearch(arr, low, mid - 1, x);
	}
	else {
		return binarySearch(arr, mid + 1, high, x);
	}
}

int exponentialSearch(int arr[], int n, int x) {
	if (n == 0) {
		return -1;
	}
	int i = 1;
	while (i < n && arr[i] < x) {
		i *= 2;
	}
	return binarySearch(arr, i/2, min(i, n - 1), x);
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 40; // Target or value of interest.
	int result = exponentialSearch(arr, n, x);
	
	if (result != -1) {
		cout << "Element is present at index number " << result << endl;
	}
	else {
		cout << "Element is not present in the array" << endl;
	}
	return 0;
}

