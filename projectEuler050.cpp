/*	Problem 50
	Consecutive Prime Sum

	The prime 41, can be written as the sum of six consecutive primes:

	41 = 2 + 3 + 5 + 7 + 11 + 13

	This is the longest sum of consecutive primes that adds to a prime
	below one-hundred.

	The longest sum of consecutive primes below one-thousand that adds
	to a prime, contains 21 terms, and is equal to 953.

	Which prime, below one-million, can be written as the sum of the most
	consecutive primes?
*/

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

	for (int divisor = 2; divisor <= floor (double (x / 2)); divisor++) {
		if (x % divisor == 0) {
			return false;
		}
	}

	return true;
}

//	Returns a vector of all the 4-digit primes.
vector <int> getPrimes () {
	vector <int> primes;

	for (int i = 2; i < 4000; i++) {
		if (isPrime (i)) {
			primes.push_back (i);
		}
	}

	return primes;
}

int main () {
	vector <int> primes = getPrimes ();
	int mostOverall = 0;
	int pOverall = 0;
	for (auto a = primes.begin (); a < primes.end (); a++) {
		int counter = 1;
		int most = 0;
		int s = *a;
		int p = 0;
		for (auto b = a + 1; b < primes.end (); b++) {
			s += *b;
			counter++;

			if (s < 1000000) {
				if (isPrime (s)) {
					most = counter;
					p = s;
				}
			} else {
				break;
			}

		}

		if (most > mostOverall) {
			mostOverall = most;
			pOverall = p;
		}
	}

	cout << mostOverall << endl;
	cout << pOverall << endl;
}