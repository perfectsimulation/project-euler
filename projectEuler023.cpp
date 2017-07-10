/*	Problem 23
	Non-abundant Sums

	A perfect number is a number for which the sum of its proper divisors is
	exactly equal to the number. For example, the sum of the proper divisors
	of 28 would be

	1 + 2 + 4 + 7 + 14 = 28,

	which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less
	than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
	number that can be written as the sum of two abundant numbers is 24.

	By mathematical analysis, it can be shown that all integers greater than
	28123 can be written as the sum of two abundant numbers.

	However, this upper limit cannot be reduced any further by analysis even
	though it is known that the greatest number that cannot be expressed as
	the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as
	the sum of two abundant numbers.
*/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

//	Returns true if n is abundant; false if otherwise.
bool isAbundant (int n) {
	int s = 0;

	for (int divisor = 1; divisor < n; divisor++) {
		if (n % divisor == 0) {
			s += divisor;
		}
		if (s > n) {
			return true;
		}
	}

	return false;
	// return (s > n) ? true : false;
}

//	Returns true if n can be expressed as the sum of two abundant numbers.
bool isSumOf2Abundants (int n, vector<int> abundants) {

	for (auto i = abundants.begin (); i < abundants.end (); i++) {
		//	If i is bigger than n, it cannot be used in the sum.
		if (*i >= n) {
			break;
		}

		for (auto j = abundants.begin (); j < abundants.end (); j++) {
			if (*j != 0) {
				if (*i + *j == n) {
					// cout << *i << " " << *j << " " << n << endl;
					return true;
				//	If j is bigger than n, it cannot be used in the sum.
				//	Go on to the next i.
				} else if (*j >= n) {
					break;
				}
			}
		}
	}

	return false;
}

int main () {
	vector<int> abundants;

	for (int i = 12; i <= 28123; i++) {
		if (isAbundant (i)) {
			abundants.push_back (i);+
			// cout << i << endl;
		}
	}

	cout << endl;
	cout << endl;

	double sumNonAbundants = 0;

	//	If i cannot be expressed as the sum of two abundant numbers, it is
	//	added to the running total sumNonAbundants.
	for (int i = 1; i <= 28123; i++) {
		if (!isSumOf2Abundants (i, abundants)) {
			sumNonAbundants += double (i);
			cout << i << endl;
		}
	}

	cout << setprecision (0) << fixed;
	cout << sumNonAbundants << endl;
}