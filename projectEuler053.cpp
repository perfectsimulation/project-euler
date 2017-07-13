/*	Problem 53
	Combinatoric Selections

	There are exactly ten ways of selecting three from five, 12345:

	123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

	In combinatorics, we use the notation, 5C3 = 10.

	In general, nCr = n! / r!(n−r)!
	
	where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

	It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

	How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are
	greater than one-million?
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//	Returns integer array with a single digit for each index.
int* shift (int arr []) {
	int multiDigit = 1;

	while (multiDigit != 0) {
		multiDigit = 0;

		for (int i = 0; i < 162; i++) {
			if (arr [i] > 999) {
				multiDigit++;
				string s = to_string (arr [i]);
				arr [i] = int (s [3] - 48);
				arr [i - 1] += int (s [2] - 48);
				arr [i - 2] += int (s [1] - 48);
				arr [i - 3] += int (s [0] - 48);
				break;
			} else if (arr [i] > 99) {
				multiDigit++;
				string s = to_string (arr [i]);
				arr [i] = int (s [2] - 48);
				arr [i - 1] += int (s [1] - 48);
				arr [i - 2] += int (s [0] - 48);
				break;
			} else if (arr [i] > 9) {
				multiDigit++;
				string s = to_string (arr [i]);
				arr [i] = int (s [1] - 48);
				arr [i - 1] += int (s [0] - 48);
				break;
			}
		}

	}

	return arr;
}

bool isNonzero (int arr []) {

	for (int i = 0; i < 162; i++) {
		if (arr [i] != 0) {
			return true;
		}
	}

	return false;
}

//	"Divides" the integer arrays.
int combinations (int numerator [], int denominator [], int c) {

	int nDummy [162] = { };

	for (int i = 0; i < 162; i++) {
		nDummy [i] = numerator [i];
	}

	while (isNonzero (nDummy)) {

		//	Subtract the denominator from the numerator.
		for (int i = 161; i >= 0; i--) {
			if (nDummy [i] - denominator [i] < 0) {
				nDummy [i] += 10;
				nDummy [i - 1] -= 1;
			}
			nDummy [i] -= denominator [i];
		}

		c++;

		//	If the denominator can be subtracted more than 1M times,
		//	return, since we are only concerned if it exceeds 1M and not with
		//	the actual value.
		if (c > 1000000) {
			return c;
		}
	}

	return c;
}

//	This script can be significantly sped up by counting how many combos
//	are below 1M for each (n, r) before the combos exceed 1M, doubling that,
//	and subtracting it from the total number of pairs of (n, r).

int main () {

	int counter = 0;

	//	The value q represents n in the equation for c.
	for (int q = 100; q > 0; q--) {
	// for (int q = 60; q > 59; q--) {

		//	The largest value we will compute is 100!, which has 158 digits.
		//	Make an array with a little padding: 162 elements.
		//	nFact is an array that represents the numerator.
		int nFact [162] = { };

		//	The value r represents r in the equation for c.
		for (int r = q - 1; r > 0; r--) {
		// for (int r = 16; r > 0; r--) {

			int dFact [162] = { };
			int dOnes [162] = { };
			int dTens [162] = { };
			int dHund [162] = { };

			//	We can simplify the expression for c by simplifying the
			//	factorials.
			//	The value numerator is used to cancel out common terms
			//	in the numerator and denominator.
			//	The value denominator represents the factorial in the
			//	denominator of the simplified expression.
			int numerator = (r > (q - r)) ? r : (q - r);
			int denominator = (r > (q - r)) ? (q - r) : r;
			// int numerator = r;
			// int denominator = q - r;

			//	Reset the array representing the numerator.
			for (int i = 0; i < 162; i++) {
				nFact [i] = 0;
			}

			//	Create helper arrays for shift and add methods.
			int nOnes [162] = { };
			int nTens [162] = { };
			int nHund [162] = { };

			//	Start the calculation of the numerator factorial
			//	by inputting the first value into nFact.
			//	e.g. if the numerator is 60!, input the first value 60 into
			//	nFact.
			string qStr = to_string (q);
			for (int a = 0; a < qStr.length (); a++) {
				nFact [161 - a] = int (qStr [qStr.length () - 1 - a] - 48);
			}

			//	Compute the simplified factorial in the numerator.
			for (int n = q - 1; n > numerator; n--) {

				for (int i = 0; i < 162; i++) {
					nOnes [i] = nFact [i];
					nTens [i] = nFact [i];
					nHund [i] = nFact [i];
				}

				string nStr = to_string (n);
				for (int digit = 0; digit < nStr.length (); digit++) {

					for (int i = 0; i < 162; i++) {

						if (nFact [i] != 0) {

							if (digit == 2) {
								nOnes [i] = nFact [i] * int (nStr [digit] - 48);
								for (int a = 0; a < 162; a++) {
									int *tempO = shift (nOnes);
									nOnes [a] = tempO [a];
								}
							} else if (digit == 1) {
								if (n > 99) {
									nTens [i] = nFact [i] * int (nStr [digit] - 48) * 10;
									for (int a = 0; a < 162; a++) {
										int *tempT = shift (nTens);
										nTens [a] = tempT [a];
									}
								} else {
									nOnes [i] = nFact [i] * int (nStr [digit] - 48);
									for (int a = 0; a < 162; a++) {
										int *tempO = shift (nOnes);
										nOnes [a] = tempO [a];
									}
								}
							} else {
								if (n > 99) {
									nHund [i] = nFact [i] * int (nStr [digit] - 48) * 100;
									for (int a = 0; a < 162; a++) {
										int *tempH = shift (nHund);
										nHund [a] = tempH [a];
									}
								} else if (n > 9) {
									nTens [i] = nFact [i] * int (nStr [digit] - 48) * 10;
									for (int a = 0; a < 162; a++) {
										int *tempT = shift (nTens);
										nTens [a] = tempT [a];
									}	
								} else {
									nOnes [i] = nFact [i] * int (nStr [digit] - 48);
									for (int a = 0; a < 162; a++) {
										int *tempO = shift (nOnes);
										nOnes [a] = tempO [a];
									}
								}
							}

						}

					}
				}

				for (int i = 0; i < 162; i++) {

					if (n > 99) {
						nFact [i] = nOnes [i] + nTens [i] + nHund [i];
					} else if (n > 9) {
						nFact [i] = nOnes [i] + nTens [i];
					} else {
						nFact [i] = nOnes [i];
					}

				}

				// for (int i = 0; i < 161; i += 3) {
				// 	cout << nFact [i] << nFact [i + 1] << nFact [i + 2] << " ";
				// }
				// cout << endl;

				int *temp = shift (nFact);
				for (int a = 0; a < 162; a++) {
					nFact [a] = temp [a];
				}
			}

			//	Start the calculation of the denominator factorial
			//	by inputting the first value into dFact.
			//	e.g. if the denominator is 60!, input the first value 60 into
			//	dFact.
			string den = to_string (denominator);
			for (int a = 0; a < den.length (); a++) {
				dFact [161 - a] = int (den [den.length () - 1 - a] - 48);
			}

			//	Compute the simplified factorial in the denominator.
			for (int d = denominator - 1; d > 0; d--) {

				for (int i = 0; i < 162; i++) {
					dOnes [i] = dFact [i];
					dTens [i] = dFact [i];
					dHund [i] = dFact [i];
				}

				string dStr = to_string (d);
				for (int digit = 0; digit < dStr.length (); digit++) {

					for (int i = 0; i < 162; i++) {

						if (dFact [i] != 0) {

							if (digit == 2) {
								dOnes [i] = dFact [i] * int (dStr [digit] - 48);
								for (int a = 0; a < 162; a++) {
									int *tempO = shift (dOnes);
									dOnes [a] = tempO [a];
								}
							} else if (digit == 1) {
								if (d > 99) {
									dTens [i] = dFact [i] * int (dStr [digit] - 48) * 10;
									for (int a = 0; a < 162; a++) {
										int *tempT = shift (dTens);
										dTens [a] = tempT [a];
									}
								} else {
									dOnes [i] = dFact [i] * int (dStr [digit] - 48);
									for (int a = 0; a < 162; a++) {
										int *tempO = shift (dOnes);
										dOnes [a] = tempO [a];
									}
								}
							} else {
								if (d > 99) {
									dHund [i] = dFact [i] * int (dStr [digit] - 48) * 100;
									for (int a = 0; a < 162; a++) {
										int *tempH = shift (dHund);
										dHund [a] = tempH [a];
									}
								} else if (d > 9) {
									dTens [i] = dFact [i] * int (dStr [digit] - 48) * 10;
									for (int a = 0; a < 162; a++) {
										int *tempT = shift (dTens);
										dTens [a] = tempT [a];
									}	
								} else {
									dOnes [i] = dFact [i] * int (dStr [digit] - 48);
									for (int a = 0; a < 162; a++) {
										int *tempO = shift (dOnes);
										dOnes [a] = tempO [a];
									}
								}
							}

						}

					}
				}

				for (int i = 0; i < 162; i++) {

					if (d > 99) {
						dFact [i] = dOnes [i] + dTens [i] + dHund [i];
					} else if (d > 9) {
						dFact [i] = dOnes [i] + dTens [i];
					} else {
						dFact [i] = dOnes [i];
					}

				}

				int *temp = shift (dFact);
				for (int a = 0; a < 162; a++) {
					dFact [a] = temp [a];
				}
			}

			// for (int i = 0; i < 161; i += 3) {
			// 	cout << dFact [i] << dFact [i + 1] << dFact [i + 2] << " ";
			// }
			// cout << endl;

			int combos = 0;
			int c = combinations (nFact, dFact, combos);
			cout << q << " " << r << " " << c << endl;
			if (c > 1000000) {
				counter++;
			}

		}
	}

	cout << counter << endl;
}