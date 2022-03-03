/// Merge Sort
/// Using an array to store user set elements and values.
/// C++ 
#include <iostream>

void merge(int* arr, int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			c[k] = arr[i];
			k++;
			i++;
		}
		else {
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high) {
		c[k] = arr[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		arr[i] = c[i];
	}
}

void mergeSort(int* array, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}


int main()
{
	int arry[30], num;
	std::cout << "Enter number of elements inside the array. \n";
	std::cin >> num;

	std::cout << "Enter the " << num << " elements to be sorted: ";
	for (int i = 0; i < num; i++) {
		// Insert values of each element.
		std::cin >> arry[i];
	}
	std::cout << "Values before Merge Sort: ";
	for (int i = 0; i < num; i++) {
		std::cout << arry[i] << "\t";
	}
	std::cout << "\n";
	mergeSort(arry, 0, num - 1);
	std::cout << "Elements sorted in Array: ";
	for (int i = 0; i < num; i++) {
		std::cout << arry[i] << "\t";
	}
	std::cout << "\n";

	return 0;
}

