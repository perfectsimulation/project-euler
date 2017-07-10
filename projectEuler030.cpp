/*	Problem 30
	Digit Fifth Powers

	Surprisingly there are only three numbers that can be written as the sum
	of fourth powers of their digits:

	1634 = 1^4 + 6^4 + 3^4 + 4^4
	8208 = 8^4 + 2^4 + 0^4 + 8^4
	9474 = 9^4 + 4^4 + 7^4 + 4^4

	As 1 = 1^4 is not a sum it is not included.

	The sum of these numbers is 1634 + 8208 + 9474 = 19316.

	Find the sum of all the numbers that can be written as the sum of fifth
	powers of their digits.
*/

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main () {
	int sum5powers = 0;
	for (int i = 2; i < 200000; i++) {
		string s = to_string (i);

		while (s.length () != 6) {
			s = "0" + s;
		}

		int i0 = pow (int (s [0] - 48), 5);
		int i1 = pow (int (s [1] - 48), 5);
		int i2 = pow (int (s [2] - 48), 5);
		int i3 = pow (int (s [3] - 48), 5);
		int i4 = pow (int (s [4] - 48), 5);
		int i5 = pow (int (s [5] - 48), 5);

		if (i0 + i1 + i2 + i3 + i4 + i5 == i) {
			cout << i << endl;
			sum5powers += i;
		}
	}
	cout << sum5powers << endl;
}