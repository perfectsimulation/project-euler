/*	Problem 10
	Summation of Primes

	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
*/

#include <iomanip>
#include <iostream>

using namespace std;

bool isPrime (double x) {
	bool prime = true;
	double upperLimit = sqrt (x);

	if (upperLimit / 2 == floor (upperLimit / 2)) {
		upperLimit++;
	}

	for (int divisor = 2; divisor <= int(upperLimit); divisor++) {
		if (x / (double)divisor == floor (x / (double)divisor)) {
			prime = false;
			break;
		}
	}

	return prime;
}

void main () {
	double primeCap = 2000000;
	double primeSum = 2;	// Start with the first prime already in the sum.
	double num = 3;

	while (num < primeCap) {
		if (isPrime (num)) {
			primeSum += num;
		}
		num += 2;
	}

	cout << setprecision (0) << fixed;
	cout << primeSum << endl;
}