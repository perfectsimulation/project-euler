/*	Problem 5
	Smallest Multiple

	2520 is the smallest number that can be divided by each of the numbers
	from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all
	of the numbers from 1 to 20?
*/

#include <iostream>

using namespace std;

void main () {
	int largestFactor = 20;
	int smallestCandidate = largestFactor;
	bool foundSmallestMultiple = false;

	while (!foundSmallestMultiple) {
		for (int i = largestFactor; i > 0; i--) {
			if (smallestCandidate % i != 0) {
				smallestCandidate += largestFactor;
				break;
			}
			if (i == 1) {
				cout << smallestCandidate << endl;
				foundSmallestMultiple = true;
			}
		}
	}
}