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
bool hasAdjacentDuplicates(int values[], const int size);	//This prototype sets a boolean to check for adjacent duplicates
bool hasDuplicates(int values[], const int size);		//This sets up a function to detect for duplicate values

int main() {
	const int ARRAYSIZE = 6;	//This sets the size of the array
	int numbers[ARRAYSIZE];		//This initializes the array
	bool increasing = true;		//This initializes the boolean we use with the isSortedIncreasing function
	bool decreasing = true;		//This initializes the boolean we use with the isSortedDecreasing function
	bool adjacentDuplicates = true;	//This sets the boolean used with hasAdjacentDuplicates
	bool duplicates = true;		//This sets the boolean used to store the duplicates check
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

	adjacentDuplicates = hasAdjacentDuplicates(numbers, ARRAYSIZE);	//This runs the function
	if (adjacentDuplicates == true) {				//If the function is true, then it outputs that there are adjacent duplicates
		cout << "The data has adjacent duplicates." << endl;	
	}
	else {						//Otherwise it is false, so it outputs that there aren't adjacent duplicates
		cout << "The data does not have adjacent duplicates. " << endl;
	}

	duplicates = hasDuplicates(numbers, ARRAYSIZE);		//This runs the function
	if (duplicates == true) {				//If it's true, it outputs that there is duplicates
		cout << "The data has duplicates. " << endl;
	}
	else {							//Otherwise, there are no duplicates, so it says that
		cout << "The data does not have duplicates." << endl;
	}
	cout << "Press any key to continue . . .";			
	

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
	for (int z = 1; z < size; z++) {			//This for loop runs through each value in the array. It starts at 1 because otherwise, element 0 would be compared to element -1, which doesn't exist.
		if (values[z] > values[(z - 1)]) {		//If one element of the array is greater than the value before it, then it's not decreasing.
			return false;						//If it isn't decreasing, then it returns false.
		}
	}
	return true;			//This goes after the for loop, because if it makes it through the for loop without returning false, then it must be true.
}

bool hasAdjacentDuplicates(int values[], int size) {		//This part actually defines the function
	for (int i = 1; i < size; i++) {			//This for loop runs through each value in the array. It starts at 1 because otherwise, element 0 would be compared to element -1, which doesn't exist.
		if (values[i] == values[(i - 1)]) {		//If one element of the array is equal to the value before it, then there's adjacent duplicates
			return true;						//If there are adjacent duplicates, it returns true.
		}
	}
	return false;			//This goes after the for loop, because if it makes it through the for loop without returning true, then it must be false.
}

bool hasDuplicates(int values[], int size) {
	for (int j = 0; j < size; j++) {			//This for loop runs through each value in the array, including 0 this time
		for (int k = (j + 1); k < size; k++) {			//This for loop runs through each value above the one in the previous for loop
			if (values[j] == values[k]) {				//If it finds that the value selected in the for loop is equal to any other value, it returns true
				return true;
			}

		}
	}
	return false;		//If it reaches this point, none are equal, so it's false
}