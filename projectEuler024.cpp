/*	Problem 24
	Lexicographoc Permutations

	A permutation is an ordered arrangement of objects. For example,
	3124 is one possible permutation of the digits 1, 2, 3 and 4.

	If all of the permutations are listed numerically or alphabetically,
	we call it lexicographic order.

	The lexicographic permutations of 0, 1 and 2 are:

	012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits
	0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main () {

	int digits [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int counter = 1;

	while (counter != 1000000) {
		next_permutation (digits, digits + 10);
		counter++;
	}

	cout << digits [0] << digits [1] << digits [2]
	<< digits [3] << digits [4] << digits [5] << digits [6]
	<< digits [7] << digits [8] << digits [9] << endl;
}