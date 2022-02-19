/// Binary Search Algorithm
/// C++ 
#include <iostream>


using namespace std;

int binarySearch(const int [], int, int);

const int SIZE = 5;

int binarySearch(const int array[], int size, int value) {
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (array[middle] == value) {
			found = true;
			position = middle;
		}
		else if (array[middle] > value) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return position;
}

int main()
{
	int ar[SIZE] = { 2, 3, 4, 10, 40};
	int x = 10;
	int results;

	results = binarySearch(ar, SIZE, x);

	if (results == -1) {
		cout << "That number does not exist within the array" << endl;
	}
	else {
		cout << "That number is found at element " << results << " in the array." << endl;
	}
}

