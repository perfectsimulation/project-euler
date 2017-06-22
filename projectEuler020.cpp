/*	Problem 20
	Factorial Digit Sum

	n! means n × (n − 1) × ... × 3 × 2 × 1

	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800.
	The sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

	Find the sum of the digits in the number 100!
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
	int num [162] = { };
	int numTempOnes [162] = { };
	int numTempTens [162] = { };
	num [159] = 1;
	numTempOnes [159] = 1;
	numTempTens [159] = 1;

	for (int n = 99; n > 0; n--) {

		for (int index = 0; index < 162; index++) {
			numTempOnes [index] = num [index];
			numTempTens [index] = num [index];
		}

		string n_string = to_string (n);
		
		for (int digit = 0; digit <= n_string.length () - 1; digit++) {

			for (int index = 0; index < 162; index++) {

				if (num [index] != 0) {

					if (digit == 1) {
						int product = num [index] * int (n_string [digit] - 48);
						numTempOnes [index] = product;
					} else {
						if (n > 9) {
							int product = (num [index] * int (n_string [digit] - 48)) * 10;
							numTempTens [index] = product;
						} else {
							int product = num [index] * int (n_string [digit] - 48);
							numTempOnes [index] = product;
						}
					}

					if (numTempOnes [index] > 9 || numTempTens [index] > 9) {
						int multiDigitNums = 1;

						while (multiDigitNums != 0) {

							multiDigitNums = 0;
							
							for (int i = 0; i < 162; i++) {

								if (numTempOnes [i] > 9) {
									multiDigitNums++;
									string num_string = to_string (numTempOnes [i]);
									numTempOnes [i] = int (num_string [1] - 48);
									numTempOnes [i - 1] += int (num_string [0] - 48);
									break;
								}
							}
						
							for (int i = 0; i < 162; i++) {

								if (numTempTens [i] > 99) {
									multiDigitNums++;
									string num_string = to_string (numTempTens [i]);
									numTempTens [i] = int (num_string [2] - 48);
									numTempTens [i - 1] += int (num_string [1] - 48);
									numTempTens [i - 2] += int (num_string [0] - 48);
									break;

								} else if (numTempTens [i] > 9) {
									multiDigitNums++;
									string num_string = to_string (numTempTens [i]);
									numTempTens [i] = int (num_string [1] - 48);
									numTempTens [i - 1] += int (num_string [0] - 48);
									break;
								}
							}
						}
					}
				}
			}
		}
		
		for (int i = 0; i < 162; i++) {

			if (n > 9) {
				num [i] = numTempOnes [i] + numTempTens [i];
			} else {
				num [i] = numTempOnes [i];
			}

			int multiDigitNums = 1;

			while (multiDigitNums != 0) {

				multiDigitNums = 0;

				for (int i = 0; i < 162; i++) {

					if (num [i] > 99) {
						multiDigitNums++;
						string num_string = to_string (num [i]);
						num [i] = int (num_string [2] - 48);
						num [i - 1] += int (num_string [1] - 48);
						num [i - 2] += int (num_string [0] - 48);
						break;

					} else if (num [i] > 9) {
						multiDigitNums++;
						string num_string = to_string (num [i]);
						num [i] = int (num_string [1] - 48);
						num [i - 1] += int (num_string [0] - 48);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 161; i += 3) {
		cout << num [i] << num [i + 1] << num [i + 2] << " ";
	}

	int sumOf100factorial = 0;
	for (int i = 0; i < 162; i++) {
		sumOf100factorial += num [i];
	}

	cout << endl;
	cout << sumOf100factorial << endl;
}