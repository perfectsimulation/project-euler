/*	Problem 49
	Prime Permutations

	The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
	increases by 3330, is unusual in two ways: (i) each of the three terms
	are prime, and, (ii) each of the 4-digit numbers are permutations of
	one another.

	There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
	primes, exhibiting this property, but there is one other 4-digit
	increasing sequence.

	What 12-digit number do you form by concatenating the three terms
	in this sequence?
*/

#include <algorithm>
#include <iostream>
#include <string>
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

	for (int i = 1000; i < 10000; i++) {
		if (isPrime (i)) {
			primes.push_back (i);
		}
	}

	return primes;
}

int strToInt (string s) {
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int main () {
	vector <int> primes = getPrimes ();
	bool found = false;

	for (auto a = primes.begin (); a < primes.end (); a++) {
		int digits [4] = { };
		string s = to_string (*a);

		for (int a = 0; a < 4; a++) {
			digits [a] = int (s [a] - 48);
		}

		vector <int> permutations;
		permutations.push_back (*a);
		sort (digits, digits + 4);

		do {
			s = "";
			for (int a = 0; a < 4; a++) {
				s += to_string (digits [a]);
			}

			int perm = strToInt (s);
			if (isPrime (perm)) {
				if (find (permutations.begin (), permutations.end (), perm) == permutations.end ()) {
					permutations.push_back (perm);
				}
			}

		} while (next_permutation (digits, digits + 4));




		if (permutations.size () >= 3) {
			for (int i = 1; i < 5000; i++) {
				int candA = permutations [0] + i;
				int candB = permutations [0] + (2 * i);
				
				if (find (permutations.begin (), permutations.end (), candA) != permutations.end ()) {
					if (find (permutations.begin (), permutations.end (), candB) != permutations.end ()) {
						cout << permutations [0] << " ";
						cout << candA << " ";
						cout << candB << " ";
						cout << endl;
						break;
					}
				}


			}
		}

		if (found) {
			break;
		}


	}

}