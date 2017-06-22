/*	Problem 3
	Largest Prime Factor

	The prime factors of 13195 are 5, 7, 13 and 29.
	What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime (int x) {
	bool prime = true;
	double x_d = static_cast<double> (x);
	int upperLimit = static_cast<int> (sqrt (x));

	if (upperLimit % 2 == 0) {
		upperLimit++;
	}

	for (int divisor = 3; divisor <= upperLimit; divisor++) {
		if (x % divisor == 0) {
			prime = false;
			break;
		}
	}

	return prime;
}

void main () {
	// double num = 13195;
	double num = 600851475143;
	bool primeFactorFound = false;
	// double num_d = static_cast<double> (num);
	int largestCandidate = static_cast<int> (sqrt (num));

	cout << num << endl;
	cout << largestCandidate << endl;

	if (largestCandidate % 2 == 0) {
		largestCandidate++;
	}

	while (!primeFactorFound && largestCandidate > 0) {
		bool primeFound = isPrime (largestCandidate);

		if (!primeFound) {
			largestCandidate -= 2;
		} else {
			double otherFactor = num / (double)largestCandidate;
			if (floor (otherFactor) == otherFactor) {
				primeFactorFound = true;
				break;
			}
			largestCandidate -= 2;
		}
	}

	cout << largestCandidate << endl;
}