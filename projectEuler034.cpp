/*	Problem 34
	Digit Factorials

	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

	Find the sum of all numbers which are equal to the sum of the factorial
	of their digits.

	Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>
#include <string>

using namespace std;

int factorial (int i) {
	int result = 1;
	for (int x = i; x > 0; x--) {
		result *= x;
	}
	return result;
}

int factorialSum (int i) {
	string iStr = to_string (i);
	int iSum = 0;
	for (int x = 0; x < iStr.length (); x++) {
		int digitFact = factorial (int (iStr [x] - 48));
		iSum += digitFact;
	}
	return iSum;
}

int main () {
	int sumFacts = 0;
	for (int i = 3; i < 99999; i++) {
		if (i == factorialSum (i)) {
			sumFacts += i;
		}
	}

	cout << sumFacts << endl;
}