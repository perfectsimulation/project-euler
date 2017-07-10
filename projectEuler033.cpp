/*	Problem 33
	Digit Cancelling Fractions

	The fraction 49/98 is a curious fraction, as an inexperienced mathematician
	in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
	which is correct, is obtained by cancelling the 9s.

	We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

	There are exactly four non-trivial examples of this type of fraction, less
	than one in value, and containing two digits in the numerator and
	denominator.

	If the product of these four fractions is given in its lowest common terms,
	find the value of the denominator.
*/

#include <iostream>
#include <string>

using namespace std;

int main () {

	int totalNum = 1;
	int totalDem = 1;

	int counter = 0;

	for (int dem = 10; dem < 100; dem++) {
		for (int num = 10; num < dem; num++) {
			string numStr = to_string (num);
			string demStr = to_string (dem);
			bool isMatchDigit = false;
			int matchNum;
			int matchDem;
			for (int i = 0; i < numStr.length (); i++) {
				for (int j = 0; j < demStr.length (); j++) {
					// cout << numStr [i] << " " << demStr [j] << endl;
					if (numStr [i] == demStr [j] && numStr [i] != '0') {
						matchNum = i;
						matchDem = j;
						isMatchDigit = true;
						break;
					}
				}
				if (isMatchDigit) {
					break;
				}
			}
			double before;
			double after;
			if (isMatchDigit) {
				before = double (num) / double (dem);
				// cout << numStr [matchNum] << " " << demStr [matchDem] << endl;
				numStr.erase (numStr.begin () + matchNum);
				demStr.erase (demStr.begin () + matchDem);
				int newNum = int (numStr [0] - 48);
				int newDem = int (demStr [0] - 48);
				after = double (newNum) / double (newDem);
				// cout << numStr << " " << demStr << endl;
				if (before == after) {
					totalNum *= num;
					totalDem *= dem;
					counter++;
				}
			}

		}
	}

	cout << totalNum << " / " << totalDem << endl;

}