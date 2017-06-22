/*	Problem 14
	Longest Collatz Sequence

	The following iterative sequence is defined for the set of
	positive integers:

	n → n/2 (n is even)
	n → 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the
	following sequence:

	13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

	It can be seen that this sequence (starting at 13 and finishing at 1)
	contains 10 terms. Although it has not been proved yet (Collatz Problem),
	it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain?

	NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iomanip>
#include <iostream>

using namespace std;

double iterSeq (double x) {
	return ((x / 2) == floor (x / 2)) ? (x / 2) : (x * 3 + 1);
}

int main () {
	double longestChainStartN = 0;
	int longestChainLength = 0;

	for (double i = 999999; i > 0; i--) {
		int numOfTerms = 2;
		double n = iterSeq (i);
		
		while (n != 1) {
			n = iterSeq (n);
			numOfTerms++;			
		}

		if (numOfTerms > longestChainLength) {
			longestChainStartN = i;
			longestChainLength = numOfTerms;
		}

		// if (numOfTerms > 400) {
		// 	cout << i << " has " << numOfTerms << " terms." << endl;
		// }
	}

	cout << setprecision (0) << fixed;
	cout << longestChainStartN << endl;
	cout << longestChainLength << endl;
}