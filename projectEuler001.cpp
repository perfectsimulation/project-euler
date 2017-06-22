/*	Problem 1
	Multiples of 3 and 5

	If we list all the natural numbers below 10 that are multiples of 3 or 5,
	we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

using namespace std;

void main () {
	int sum3 = 0;
	int sum5 = 0;
	int sum3and5 = 0;	// delete duplicate multiples

	for (int multiple3 = 999; multiple3 > 0; multiple3 -= 3) {
		sum3 += multiple3;
	}

	for (int multiple5 = 995; multiple5 > 0; multiple5 -= 5) {
		sum5 += multiple5;
	}

	for (int multiple15 = 990; multiple15 > 0; multiple15 -= 15) {
		sum3and5 += multiple15;
	}

	cout << sum3 << endl;
	cout << sum5 << endl;
	cout << sum3and5 << endl;

	cout << sum3 + sum5 - sum3and5 << endl;
}