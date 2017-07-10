/*	Problem 40
	Champernowne's Constant

	An irrational decimal fraction is created by concatenating the positive
	integers:

	0.123456789101112131415161718192021...

	It can be seen that the 12th digit of the fractional part is 1.

	If dn represents the nth digit of the fractional part, find the value of
	the following expression.

	d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
	string s = ".";
	for (int i = 1; i < 186000; i++) {
		s += to_string (i);
	}

	cout << int (s [1] - 48) * int (s [10] - 48)
	* int (s [100] - 48) * int (s [1000] - 48)
	* int (s [10000] - 48) * int (s [100000] - 48)
	* int (s [1000000] - 48) << endl;
}