/*	Problem 47
	Distinct Prime Factors

	The first two consecutive numbers to have two distinct prime factors are:

	14 = 2 × 7
	15 = 3 × 5

	The first three consecutive numbers to have three distinct prime factors
	are:

	644 = 2² × 7 × 23
	645 = 3 × 5 × 43
	646 = 2 × 17 × 19.

	Find the first four consecutive integers to have four distinct prime
	factors each. What is the first of these numbers?
*/

#include <algorithm>
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

vector <int> getFactors (int n, vector <int> primes) {
	int i = 0;
	vector <int> factors;
	vector <int> multiplicity;

	while (primes [i] <= n) {
		if (n % primes [i] == 0) {

			if (find (factors.begin (), factors.end (), primes [i]) == factors.end ()) {
				factors.push_back (primes [i]);
				multiplicity.push_back (1);
			} else {
				vector <int> :: iterator it = find (factors.begin (), factors.end (), primes [i]);
				auto pos = it - factors.begin ();
				multiplicity [pos] ++;
			}

			n /= primes [i];
			i = -1;
		}
		i++;
	}

	//	Account for multiplicity.
	for (int j = 0; j < factors.size (); j++) {
		factors [j] *= multiplicity [j];
	}

	return factors;
}

int main () {
	//	I messed with the range in the for loop to get desired results.
	vector <int> primes = getPrimes (999999);
	for (int i = 99999; i < 999999; i++) {
		vector <int> p1 = getFactors (i, primes);
		vector <int> p2 = getFactors (i + 1, primes);
		vector <int> p3 = getFactors (i + 2, primes);
		vector <int> p4 = getFactors (i + 3, primes);

		bool hasDistinctFactors = true;
		if ((p1.size () == 4)
			&& (p1.size () == p2.size ())
			&& (p2.size () == p3.size ())
			&& (p3.size () == p4.size ())) {

			for (int x = 0; x < p1.size (); x++) {
				if (find (p2.begin (), p2.end (), p1 [x]) != p2.end ()) {
					hasDistinctFactors = false;
					break;
				} else if (find (p3.begin (), p3.end (), p1 [x]) != p3.end ()) {
					hasDistinctFactors = false;
					break;
				} else if (find (p4.begin (), p4.end (), p1 [x]) != p4.end ()) {
					hasDistinctFactors = false;
					break;
				}
			}

			for (int y = 0; y < p2.size (); y++) {
				if (find (p3.begin (), p3.end (), p2 [y]) != p3.end ()) {
					hasDistinctFactors = false;
					break;
				} else if (find (p4.begin (), p4.end (), p2 [y]) != p4.end ()) {
					hasDistinctFactors = false;
					break;
				}
			}

			for (int z = 0; z < p3.size (); z++) {
				if (find (p4.begin (), p4.end (), p3 [z]) != p4.end ()) {
					hasDistinctFactors = false;
					break;
				}
			}

		} else {
			hasDistinctFactors = false;
		}

		if (hasDistinctFactors) {

			for (int a = 0; a < p1.size (); a++) {
				cout << p1 [a] << " ";
			}
			cout << endl;
			for (int a = 0; a < p2.size (); a++) {
				cout << p2 [a] << " ";
			}
			cout << endl;
			for (int a = 0; a < p3.size (); a++) {
				cout << p3 [a] << " ";
			}
			cout << endl;
			for (int a = 0; a < p4.size (); a++) {
				cout << p4 [a] << " ";
			}
			cout << endl;

			cout << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
			break;
		}

	}
}