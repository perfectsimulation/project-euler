/*	Problem 27
	Quadratic Primes

	Euler discovered the remarkable quadratic formula:

	n^2 + n + 41

	It turns out that the formula will produce 40 primes for the consecutive
	integer values 0 ≤ n ≤ 39.

	However, when n = 40,
	40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and when n = 41,
	41^2 + 41 + 41 is clearly divisible by 41.

	The incredible formula n^2 − 79n + 1601 was discovered,
	which produces 80 primes for the consecutive values 0 ≤ n ≤ 79.
	The product of the coefficients, −79 and 1601, is −126479.

	Considering quadratics of the form:

	n^2 + an + b, where |a| < 1000 and |b| ≤ 1000

	where |n| is the modulus/absolute value of n
	e.g. |11| = 11 and |−4| = 4

	Find the product of the coefficients, a and b, for the quadratic expression
	that produces the maximum number of primes for consecutive values of n,
	starting with n = 0.
*/

#include <cmath>
#include <iostream>

using namespace std;

bool isExpressionPrime (int a, int b, int n) {
	int result = pow (n, 2) + (a * n) + b;

	if (result < 0) {	// Negative numbers cannot be prime.
		return false;
	}

	for (int divisor = 2; divisor < result; divisor++) {
		if (result % divisor == 0) {
			return false;
		}
	}

	return true;
}

int main () {
	int a = 1;
	int b = 1;
	int greatestConsecutivePrimes = 0;

	for (int i = -999; i < 1000; i++) {
		for (int j = -1000; j <= 1000; j++) {
			int n = 0;

			while (isExpressionPrime (i, j, n)) {
				n++;
			}

			if (n > greatestConsecutivePrimes) {
				greatestConsecutivePrimes = n;
				a = i;
				b = j;
			}
		}
	}

	cout << a << " x " << b << " = " << a * b << endl;
	cout << greatestConsecutivePrimes << endl;
}