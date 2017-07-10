/*	Problem 37
	Truncatable Primes

	The number 3797 has an interesting property. Being prime itself, it is
	possible to continuously remove digits from left to right, and remain
	prime at each stage:

	3797, 797, 97, and 7.

	Similarly we can work from right to left:

	3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from
	left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool isPrime (int x) {

	if (x == 1) {
		return false;
	}

	if (x > 2 && x % 2 == 0) {
		return false;	//	Other than 2, even numbers are not prime.
	}

	for (int divisor = 2; divisor <= floor (sqrt (double (x))); divisor++) {
		if (x % divisor == 0) {
			return false;
		}
	}

	return true;
}

int removeRight (int x) {
	string s = to_string (x);
	s.erase (s.end () - 1);
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int removeLeft (int x) {
	string s = to_string (x);
	s.erase (s.begin ());
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int main () {
	int sumTPrimes = 0;
	int counter = 0;

	for (int i = 10; i < 1000000; i++) {

		bool leftPrimes = true;
		bool rightPrimes = true;

		if (isPrime (i)) {
			int n = i;
			string nStr = to_string (n);

			//	Left to right
			while (n != 0) {
				if (!isPrime (removeLeft (n))) {
					leftPrimes = false;
					break;
				} else {
					n = removeLeft (n);
					nStr = to_string (n);
				}
			}

			if (leftPrimes) {
				n = i;
				nStr = to_string (n);

				// Right to left
				while (n != 0) {
					if (!isPrime (removeRight (n))) {
						rightPrimes = false;
						break;
					} else {
						n = removeRight (n);
						nStr = to_string (n);
					}
				}
			}

		} else {
			leftPrimes = false;
			rightPrimes = false;
		}

		if (leftPrimes && rightPrimes) {
			sumTPrimes += i;
			cout << i << endl;
			counter++;
		}

		if (counter == 11) {
			break;
		}
	}

	cout << sumTPrimes << endl;
}