/*	Problem 16
	Power Digit Sum

	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
	int powerDigit [400] = { };
	powerDigit [399] = 2;

	for (int i = 0; i < 999; i++) {

		for (int index = 0; index < 400; index++) {
			powerDigit [index] *= 2;
			if (powerDigit [index] > 9) {
				string s = to_string (powerDigit [index]);
				powerDigit [index] = s[1] - 48;
				powerDigit [index - 1] += s[0] - 48;
			} 
		}

	}

	int sumOfDigits = 0;
	for (int x = 0; x < 400; x++) {
		sumOfDigits += powerDigit [x];
		// cout << sumOfDigits << endl;
	}

	cout << sumOfDigits << endl;
}