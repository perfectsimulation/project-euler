/*	Problem 48
	Self Powers

	The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

	Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
*/

#include <iostream>
#include <string>

using namespace std;

int* shift (int arr []) {
	int multiDigit = 1;

	while (multiDigit != 0) {
		multiDigit = 0;

		for (int i = 12; i > 2; i--) {
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

int main () {
	int series [13] = { };
	int ones [13] = { };
	int tens [13] = { };
	int hund [13] = { };

	for (int i = 1; i < 1000; i++) {

		for (int index = 0; index < 13; index++) {
			ones [index] = 0;
			tens [index] = 0;
			hund [index] = 0;
		}

		string s = to_string (i);
		if (i > 99) {
			ones [10] = int (s [0] - 48);
			ones [11] = int (s [1] - 48);
			ones [12] = int (s [2] - 48);
		} else if (i > 9) {
			ones [11] = int (s [0] - 48);
			ones [12] = int (s [1] - 48);
		} else {
			ones [12] = int (s [0] - 48);
		}

		for (int j = 1; j < i; j++) {
			for (int k = 12; k >= 0; k--) {
				ones [k] *= i;
			}

			int *t = shift (ones);
			for (int a = 0; a < 13; a++) {
				ones [a] = t [a];
			}

		}

		for (int a = 0; a < 13; a++) {
			series [a] += ones [a];
		}

		int *shifted = shift (series);
		for (int a = 0; a < 13; a++) {
			series [a] = shifted [a];
		}

	}

	for (int i = 3; i < 13; i++) {
		cout << series [i] << " ";
	}
	cout << endl;
}