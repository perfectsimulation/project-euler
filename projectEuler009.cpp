/*	Problem 9
	Special Pythagorean Triplet

	A Pythagorean triplet is a set of three natural numbers a < b < c for which

	a^2 + b^2 = c^2
	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
*/

#include <iostream>

using namespace std;

void main () {
	float abcSum = 1000;
	float cMin = abcSum / 3;

	bool foundTriple = false;

	int c_initial = floor (cMin) + 1;
	int a_initial = c_initial - 2;
	int b_initial = c_initial - 1;

	// Make sure initial a + b + c = abcSum
	if (c_initial + a_initial + b_initial != abcSum) {
		c_initial++;
	}
	
	int c = c_initial;
	int a = a_initial;
	int b = b_initial;

	int bCounter = 0;

	while (!foundTriple && bCounter < floor (float(a_initial) / 2)) {
		c = c_initial + bCounter;
		a = a_initial - (bCounter * 2);
		b = b_initial + bCounter;

		while (a > 0) {
			int a2 = a * a;
			int b2 = b * b;
			int c2 = c * c;

			if (a2 + b2 == c2) {
				foundTriple = true;
				break;
			}

			a--;
			c++;
		}

		bCounter++;
	}

	cout << "found? " << foundTriple << endl;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << "The product abc = " << a * b * c << endl;
}