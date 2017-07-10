/*	Problem 45
	Goldbach's Other Conjecture

	It was proposed by Christian Goldbach that every odd composite number
	can be written as the sum of a prime and twice a square.

	9  = 7  + 2 × 1^2
	15 = 7  + 2 × 2^2
	21 = 3  + 2 × 3^2
	25 = 7  + 2 × 3^2
	27 = 19 + 2 × 2^2
	33 = 31 + 2 × 1^2

	It turns out that the conjecture was false.

	What is the smallest odd composite that cannot be written as the sum of
	a prime and twice a square?
*/

#include <cmath>
#include <iostream>
#include <vector>

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

vector <int> getPrimes (int n) {
	vector <int> primes;
	primes.push_back (2);

	for (int i = 3; i <= n; i++) {
		if (isPrime (i)) {
			primes.push_back (i);
		}
	}

	return primes;
}

vector <int> getSquares (int n) {
	vector <int> squares;

	for (int i = 1; i <= n; i++) {
		squares.push_back (2 * i * i);
	}

	return squares;
}

bool isCompositeSum (int x, vector <int> primes, vector <int> squares) {
	int i = 0;
	int j = 0;

	while (primes [i] < x) {
		while (primes [i] + squares [j] <= x) {
			// cout << primes [i] << " " << squares [j] << " " << x << endl;
			if (x == primes [i] + squares [j]) {
				return true;
			}
			j++;
		}

		j = 0;
		i++;
	}

	return false;
}

int main () {

	//	Messed with the value for n until I got desired results.
	int n = 6000;
	vector <int> primes = getPrimes (n);
	vector <int> squares = getSquares (primes.size () * 2);

	for (int i = 9; i < n; i += 2) {
		if (!isPrime (i)) {
			if (!isCompositeSum (i, primes, squares)) {
				cout << i << " cannot be written as a sum." << endl;
				break;
			}
		}
	}
}