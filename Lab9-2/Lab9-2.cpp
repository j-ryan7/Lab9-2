/*
Jaden Ryan
4/2/2026

Program Description: Generate an array of integers, and check if they are sorted increasing or decreasing,
and checks if there are duplicates, adjacent or not.
*/
#include<iostream>
using namespace std;


bool isSortedIncreasing(int values[], const int size);		//This prototype sets up a boolean function
bool isSortedDecreasing(int values[], const int size);		//This prototype sets up another boolean function

int main() {
	const int ARRAYSIZE = 6;	//This sets the size of the array
	int numbers[ARRAYSIZE];		//This initializes the array
	bool increasing = true;		//This initializes the boolean we use with the isSortedIncreasing function
	bool decreasing = true;		//This initializes the boolean we use with the isSortedDecreasing function

	for (int x = 0; x < ARRAYSIZE; x++) {		//This loop gets the user to input each index of the array
		cout << "Enter integer #" << x << ": ";
		cin >> numbers[x];
	}

	increasing = isSortedIncreasing(numbers, ARRAYSIZE);		//This runs the function with the array and the array size
	if (increasing == true) {						//If the function returned true, we output that it is increasing
		cout << "The data are increasing." << endl;
	}
	else {											//Otherwise it must be false, so it's not increasing
		cout << "The data are not increasing. " << endl; 
	}
	
	decreasing = isSortedDecreasing(numbers, ARRAYSIZE);	//This runs the function with the array and the array size
	if (decreasing == true) {						//If the function returned true, we output that it is decreasing
		cout << "The data are decreasing." << endl;
	}
	else {											//Otherwise it must be false, so it's not decreasing
		cout << "The data are not decreasing. " << endl;
	}

	return 0;
}

bool isSortedIncreasing(int values[], int size) {		//This part actually defines the function
	for (int y = 1; y < size; y++) {			//This for loop runs through each value in the array. It starts at 1 because otherwise, element 0 would be compared to element -1, which doesn't exist.
		if (values[y] < values[(y - 1)]) {		//If one element of the array is less than the value before it, then it's not increasing.
			return false;						//If it isn't increasing, then it returns false.
		}
	}
	return true;			//This goes after the for loop, because if it makes it through the for loop without returning false, then it must be true.
}

bool isSortedDecreasing(int values[], int size) {		//This part actually defines the function
	for (int y = 1; y < size; y++) {			//This for loop runs through each value in the array. It starts at 1 because otherwise, element 0 would be compared to element -1, which doesn't exist.
		if (values[y] > values[(y - 1)]) {		//If one element of the array is greater than the value before it, then it's not decreasing.
			return false;						//If it isn't decreasing, then it returns false.
		}
	}
	return true;			//This goes after the for loop, because if it makes it through the for loop without returning false, then it must be true.
}
