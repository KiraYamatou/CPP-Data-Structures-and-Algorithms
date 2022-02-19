/// Exponential Search Algorithm
/// C++ 
#include <iostream>


using namespace std;

int binarySearch(int arr[], int, int, int);

int exponentialSearch(int arrp[], int n, int x) {
	if (arr[0] == x) {
		return 0;
	}
	int i = 1;
	while (i < n && arr[i] <= x) {
		i = i * 2;
	}
	return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int binarySearch(int arrp[], int l, int r, int x) {
	if (r >= 1) {
		int mid = 1 + (r - 1) / 2;

		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] > x) {
			return binarySearch(arr, l, mid - 1, x);
		}
		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 40;
	int result = exponentialSearch(arr, n, x);
	(result == -1)
		? cout << "Element is not present in the array." << endl
	: cout << "Element is presnet at index " << result << endl;
	return 0;
}

