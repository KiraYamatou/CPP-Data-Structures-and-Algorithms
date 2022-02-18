/// Linear or Sequential Search Algorithm
/// 
/// User has 5 test scores stored in the array.
/// Using linear search will find which test was scored with 100 points.

#include <iostream>


using namespace std;
// Function Prototype
int searchList(const int [], int, int);
const int SIZE = 5;

int searchList(const int list[], int numElems, int value) {
	int index = 0; ///Subscript to search array
	int position = -1; /// records position of search value
	bool found = false; /// Flag to indicate if the value was found

	/// if statement used for if the value is found.
	while (index < numElems && !found) {
		if (list[index] == value) {
			found = true; /// Sets the flag to true.
			position = index; /// Records the value's subscript
		}
		index++; ///Moves on to the next element of array.
	}
	return position; /// Return the position, or -1.
}

int main()
{
	int tests[SIZE] = { 87, 75, 98, 100, 82 };
	int results;

	results = searchList(tests, SIZE, 100);

	if (results == -1) {
		cout << "You did not earn 100 points on any of your tests" << endl << endl;
	}
	else {
		cout << "You earned 100 points on test " << (results + 1) << endl;
	}
	return 0;
}

