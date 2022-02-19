/// Bubble Sort
/// C++ 
#include <iostream>
#include <stdio.h>

using namespace std;

void sortArray(int[], int);
void showArray(const int[], int);

void sortArray(int array[], int size) {
	bool swap;
	int temp;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (array[count] > array[count + 1]) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void showArray(const int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}
int main()
{
	int values[6] = { 7, 2, 3, 8, 9, 1 };
	
	cout << "The Unsorted values in the array are: ";
	showArray(values, 6);
	cout << endl;
	sortArray(values, 6);
	cout << "The Sorted Values in the array are: ";
	showArray(values, 6);
	cout << endl;

	return 0;
}

