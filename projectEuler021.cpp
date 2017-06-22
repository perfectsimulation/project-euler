/*	Problem 21
	Amicable Numbers

	Let d(n) be defined as the sum of proper divisors of n (numbers less than n
	which divide evenly into n).

	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair
	and each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are
	1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
	The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>

using namespace std;

int sumOfDivisors (int n) {
	int s = 0;

	for (int divisor = 1; divisor < n; divisor++) {
		if (n % divisor == 0) {
			s += divisor;
		}
	}
	return s;
}

int main () {
	int nums [10000] = { };

	for (int i = 1; i < 10000; i++) {
		nums [i] = sumOfDivisors (i);
	}

	int sumOfAmicableNums = 0;

	for (int i = 1; i < 10000; i++) {
		int candidate = nums [i];
		int candidateMatch = 0;

		if (candidate < 10000) {
			candidateMatch = nums [candidate];
		}

		if ((candidateMatch == i) && (candidate != candidateMatch)) {
			sumOfAmicableNums += (candidate + candidateMatch);
			cout << candidate << " and " << candidateMatch << endl;
		}
	}

	sumOfAmicableNums /= 2;	// Amicable number pairs are counted twice.
	cout << sumOfAmicableNums << endl;
}