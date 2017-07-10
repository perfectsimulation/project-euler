/*	Problem 26
	Reciprocal Cycles

	A unit fraction contains 1 in the numerator. The decimal representation
	of the unit fractions with denominators 2 to 10 are given:

	1/2	  = 	0.5
	1/3	  = 	0.(3)
	1/4	  = 	0.25
	1/5	  = 	0.2
	1/6	  = 	0.1(6)
	1/7	  = 	0.(142857)
	1/8	  = 	0.125
	1/9	  = 	0.(1)
	1/10  = 	0.1

	Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
	It can be seen that 1/7 has a 6-digit recurring cycle.

	Find the value of d < 1000 for which 1/d contains the longest recurring
	cycle in its decimal fraction part.
*/

#include <iostream>

using namespace std;

int GCD (int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD (b, a % b);
}

//	See wolfram's page on multiplicative order
int multiplicativeOrder (int ten, int mod) {
	if (GCD (ten, mod) != 1) {
		return -1;
	}

	int result = 1;
	int k = 1;

	while (k < mod) {
		result = (result * ten) % mod;

		if (result == 1) {
			return k;
		}

		k++;
	}

	return -1;
}

int main () {
	int d = 1;
	int longestCycle = 0;

	for (int i = 1; i < 1000; i++) {
		int m = multiplicativeOrder (10, i);
		if (m > longestCycle) {
			d = i;
			longestCycle = m;
		}
	}

	cout << d << endl;
	cout << longestCycle << endl;
	
}