/*	Problem 38
	Pandigital Multiples

	Take the number 192 and multiply it by each of 1, 2, and 3:

	192 × 1 = 192
	192 × 2 = 384
	192 × 3 = 576

	By concatenating each product we get the 1 to 9 pandigital, 192384576.
	We will call 192384576 the concatenated product of 192 and (1,2,3)

	The same can be achieved by starting with 9 and multiplying by
	1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the
	concatenated product of 9 and (1,2,3,4,5).

	What is the largest 1 to 9 pandigital 9-digit number that can be formed
	as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <iostream>
#include <string>

using namespace std;

bool isPandigital (string s) {

	for (int i = 1; i < 10; i++) {
		string str = to_string (i);
		if (s.find (str) == string::npos) {
			return false;
		}
	}

	return true;
}

int strToNum (string s) {
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int main () {
	int largestPan = 0;
	int digits [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 1; i < 9999; i++) {
		string s = "";
		int c = 0;

		while (s.length () < 9) {
			s = s + to_string (i * digits [c]);
			c++;
		}

		if (s.length () == 9) {
			if (isPandigital (s)) {
				int num = strToNum (s);
				if (num > largestPan) {
					cout << num << " " << i << endl;
					largestPan = num;
				}
			}
		}
	}

	cout << largestPan << endl;
}