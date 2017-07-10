/*	Problem 41
	Pandigital Prime

	We shall say that an n-digit number is pandigital if it makes use of all
	the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital
	and is also prime.

	What is the largest n-digit pandigital prime that exists?
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

//	This method is slow.
bool isPrime (int x) {

	if (x == 1) {
		return false;
	}

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

int strToInt (string s) {
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int main () {
	int largestPanPrime = 0;
	int digits [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int counter = 0;

	while (largestPanPrime == 0) {

		//	Create a pandigital number.
		do {
			string s = "";

			for (int i = 0; i < 9; i++) {
				if (digits [i] != 0) {
					s += to_string (digits [i]);
				}
			}

			if (isPrime (strToInt (s))) {
				if (strToInt (s) > largestPanPrime) {
					largestPanPrime = strToInt (s);
				}
			}

		} while (next_permutation (digits + counter, digits + 9));

		//	If no pandigital numbers were prime, reduce the # digits.
		digits [8] = 0;
		sort (digits, digits + 9);
		counter++;
	}

	cout << largestPanPrime << endl;
}