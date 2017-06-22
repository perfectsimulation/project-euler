/*	Problem 7
	10001st Prime

	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
	we can see that the 6th prime is 13.

	What is the 10001st prime number?
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime (float x) {
	bool prime = true;
	float sqroot = sqrt (x);
	int upperLimit = floor (sqroot);

	if (upperLimit % 2 == 0) {
		upperLimit++;
	}

	for (int divisor = 2; divisor <= upperLimit; divisor++) {
		if (x / (float)divisor == floor (x / (float)divisor)) {
			prime = false;
			break;
		}
	}

	return prime;
}

void main () {
	int nthPrime = 10001;
	int primeCount = 2;	// start from 3
	float num = 3;
	float nextPrime = num;

	while (primeCount != nthPrime) {
		num += 2;
		if (isPrime (num)) {
			primeCount++;
			nextPrime = num;
		}
	}

	cout << nextPrime << endl;
}