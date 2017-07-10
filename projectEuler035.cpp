/*	Problem 35
	Circular Primes

	The number, 197, is called a circular prime because all rotations of the
	digits: 197, 971, and 719, are themselves prime.

	There are thirteen such primes below 100:
	2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

	How many circular primes are there below one million?
*/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool isPrime (int x) {

	if (x > 2 && x % 2 == 0) {
		return false;	//	Other than 2, even numbers are not prime.
	}

	for (int divisor = 2; divisor <= floor (double (x / 2)); divisor++) {
		if (x % divisor == 0) {
			return false;
		}
	}

	return true;
}

int circleNum (int x) {
	string s = to_string (x);
	string sub = s.substr (0, 1);
	s.erase (s.begin ());
	s = s + sub;
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}
	// cout << result << endl;
	return result;
}

bool anyEvenDigits (int x) {
	string s = to_string (x);

	for (int i = 0; i < s.length (); i++) {
		int y = int (s [i] - 48);
		if (y % 2 == 0) {
			return true;
		}
	}

	return false;
}

int main () {
	int counter = 1;	//	Include 2, the first circular prime.

	for (int i = 3; i < 1000000; i++) {

		if (isPrime (i)) {

			if (!anyEvenDigits (i)) {
				bool isCircularPrime = true;
				string s = to_string (i);

				int n = i;
				for (int j = 1; j < s.length (); j++) {
					if (!isPrime (circleNum (n))) {
						isCircularPrime = false;
						break;
					} else {
						n = circleNum (n);
					}
				}

				if (isCircularPrime) {
					cout << i << endl;
					counter++;
				}
			}

		}

	}

	cout << counter << endl;
}