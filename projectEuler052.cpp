/*	Problem 52
	Permuted Multiples

	It can be seen that the number, 125874, and its double, 251748, contain
	exactly the same digits, but in a different order.

	Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
	contain the same digits.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {

	for (int i = 125874; i < 400000; i++) {
		string s = to_string (i);
		vector <int> n;										//	Contains the digits of i.
		for (int j = 0; j < s.length (); j++) {
			n.push_back (int (s [j] - 48));
		}

		bool found = true;
		for (int k = 2; k < 7; k++) {						//	2x, 3x, 4x, 5x, 6x

			string s2 = to_string (i * k);
			vector <int> n2;								//	Contains the digits of the multiple i * k.
			if (s2.length () == s.length ()) {				//	If the # digits of i and (i * k) are equal...
				for (int x = 0; x < s2.length (); x++) {
					n2.push_back (int (s2 [x] - 48));
				}
			} else {
				found = false;
				break;
			}

			if (!is_permutation (n.begin (), n.end (), n2.begin (), n2.end ())) {
				found = false;
				break;
			}
		}

		if (found) {
			cout << i << " ";
			cout << (i * 2) << " ";
			cout << (i * 3) << " ";
			cout << (i * 4) << " ";
			cout << (i * 5) << " ";
			cout << (i * 6) << " ";
			break;
		}

	}

}