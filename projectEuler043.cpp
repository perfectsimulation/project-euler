/*	Problem 43
	Sub-string Divisibility

	The number, 1406357289, is a 0 to 9 pandigital number because it is made
	up of each of the digits 0 to 9 in some order, but it also has a rather
	interesting sub-string divisibility property.

	Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way,
	we note the following:

	d2d3d4 = 406 is divisible by 2
	d3d4d5 = 063 is divisible by 3
	d4d5d6 = 635 is divisible by 5
	d5d6d7 = 357 is divisible by 7
	d6d7d8 = 572 is divisible by 11
	d7d8d9 = 728 is divisible by 13
	d8d9d10 = 289 is divisible by 17

	Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int strToInt (string s) {
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

double strToDouble (string s) {
	double result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += double (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

bool isDivisible (string s) {
	int nums [7] = {2, 3, 5, 7, 11, 13, 17};

	for (int i = 0; i < 7; i++) {
		s.erase (s.begin ());
		string s2 = s.substr (0, 3);

		if (strToInt (s2) % nums [i] != 0) {
			return false;
		}
	}

	return true;
}

int main () {
	double panSum = 0;
	int digits [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	do {
		string s = "";
		if (digits [0] != 0) {

			for (int i = 0; i < 10; i++) {
				s += to_string (digits [i]);
			}

			if (isDivisible (s)) {
				panSum += strToDouble (s);
			}
		}
	} while (next_permutation (digits, digits + 10));


	cout << setprecision (0) << fixed;
	cout << panSum << endl;
}