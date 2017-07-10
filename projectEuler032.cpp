/*	Problem 32
	Pandigital Products

	We shall say that an n-digit number is pandigital if it makes use of all
	the digits 1 to n exactly once; for example, the 5-digit number, 15234,
	is 1 through 5 pandigital.

	The product 7254 is unusual, as the identity, 39 × 186 = 7254,
	containing multiplicand, multiplier, and product is 1 through 9 pandigital.

	Find the sum of all products whose multiplicand/multiplier/product
	identity can be written as a 1 through 9 pandigital.

	HINT: Some products can be obtained in more than one way so be sure to
	only include it once in your sum.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool checkPan (string s) {
	for (int i = 1; i < 10; i++) {
		string n = to_string (i);
		if (s.find (n) == string::npos) {
			return false;
		}
	}
	return true;
}

int main () {

	map<int, int> products;
	int sumProducts = 0;

	for (int i = 1; i <= 999; i++) {
		for (int j = 1; j <= 9999; j++) {
			int k = i * j;
			string a = to_string (i);
			string b = to_string (j);
			string c = to_string (k);
			string s = a + b + c;
			if (s.length () == 9) {
				if (checkPan (s)) {
					if (products.find (k) == products.end ()) {
						cout << i << " " << j << " " << k << endl;
						products [k] = k;
						sumProducts += k;
					}
				}
			}
		}
	}

	cout << sumProducts << endl;
}