/*	Problem 25
	1000-digit Fibonacci Number

	The Fibonacci sequence is defined by the recurrence relation:

	Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
	Hence the first 12 terms will be:

	F1 = 1
	F2 = 1
	F3 = 2
	F4 = 3
	F5 = 5
	F6 = 8
	F7 = 13
	F8 = 21
	F9 = 34
	F10 = 55
	F11 = 89
	F12 = 144

	The 12th term, F12, is the first term to contain three digits.

	What is the index of the first term in the Fibonacci sequence
	to contain 1000 digits?
*/

#include <iostream>
#include <string>

using namespace std;

int nextFibonacciTerm (int f1, int f2) {
	return f1 + f2;
}

int main () {

	int f1 [1000] = { };
	int f2 [1000] = { };
	int fn [1000] = { };
	int n = 0;

	f1 [999] = 1;
	f2 [999] = 1;

	bool is1000digits = false;

	while (!is1000digits) {
		n++;

		for (int i = 999; i >= 0; i--) {
			f1 [i] = f2 [i];
			f2 [i] = fn [i];
			fn [i] = nextFibonacciTerm (f1 [i], f2 [i]);
		}

		//	Shift the columns to account for 2-digit entries.
		for (int i = 999; i > 0; i--) {
			if (fn [i] > 9) {
				string str = to_string (fn [i]);
				fn [i] = int (str [1]) - 48;
				fn [i - 1] += int (str [0]) - 48;
			}
		}

		if (fn [0] != 0) {
			is1000digits = true;
		}
	}

	cout << n << endl;
}