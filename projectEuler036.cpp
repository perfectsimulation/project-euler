/*	Problem 36
	Double-base Palindromes

	The decimal number 585 = 1001001001 (binary) is palindromic in both bases.

	Find the sum of all numbers, less than one million, which are palindromic
	in base 10 and base 2.

	(Please note that the palindromic number, in either base, may not include
	leading zeros.)
*/

#include <bitset>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome (int x) {
	string s = to_string (x);

	while (s.length () > 1) {
		if (s [0] != s [s.length () - 1]) {
			return false;
		} else {
			s.erase (s.begin ());
			s.erase (s.end () - 1);
		}
	}

	return true;
}

bool isBinaryPalindrome (string s) {

	while (s.length () > 1) {
		if (s [0] != s [s.length () - 1]) {
			return false;
		} else {
			s.erase (s.begin ());
			s.erase (s.end () - 1);
		}
	}

	return true;
}

int main () {
	int sumPals = 0;

	for (int i = 1; i < 1000000; i++) {
		if (isPalindrome (i)) {
			string binary = bitset<32> (i).to_string ();
			while (binary [0] == '0') {
				binary.erase (binary.begin ());
			}
			if (isBinaryPalindrome (binary)) {
				cout << i << " " << binary << endl;
				sumPals += i;
			}
		}
	}

	cout << sumPals << endl;
}