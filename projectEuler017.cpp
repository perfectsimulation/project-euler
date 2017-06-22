/*	Problem 17
	Number Letter Counts

	If the numbers 1 to 5 are written out in words: one, two, three, four,
	five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written
	out in words, how many letters would be used?


	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
	forty-two) contains 23 letters and 115 (one hundred and fifteen) contains
	20 letters. The use of "and" when writing out numbers is in compliance
	with British usage.
*/

#include <iostream>
#include <string>

using namespace std;

int onesLetterCount (int one) {
	switch (one) {
		case 0:	return 0;
		case 1:	return 3;
		case 2:	return 3;
		case 3:	return 5;
		case 4:	return 4;
		case 5:	return 4;
		case 6:	return 3;
		case 7:	return 5;
		case 8:	return 5;
		case 9:	return 4;	
		default: return 0;
	}
}

int teensLetterCount (int teen) {
	switch (teen) {
		case 0:	return 3;
		case 1:	return 6 - 3;
		case 2:	return 6 - 3;
		case 3:	return 8 - 5;
		case 4:	return 8 - 4;
		case 5:	return 7 - 4;
		case 6:	return 7 - 3;
		case 7:	return 9 - 5;
		case 8:	return 8 - 5;
		case 9:	return 8 - 4;
		default: return 0;
	}
}

int tensLetterCount (int ten, int one) {
	switch (ten) {
		case 0:	return 0;
		case 1:	return teensLetterCount (one);
		case 2:	return 6;
		case 3:	return 6;
		case 4:	return 5;
		case 5:	return 5;
		case 6:	return 5;
		case 7:	return 7;
		case 8:	return 6;
		case 9:	return 6;
		default: return 0;
	}
}

int hundLetterCount (int hun) {
	switch (hun) {
		case 0:	return 0;
		case 1:	return 10;
		case 2:	return 10;
		case 3:	return 12;
		case 4:	return 11;
		case 5:	return 11;
		case 6:	return 10;
		case 7:	return 12;
		case 8:	return 12;
		case 9:	return 11;
		default: return 0;
	}
}

int main () {
	int letterCount = 0;

	for (int i = 1; i <= 1000; i++) {
		string s = to_string (i);
		if (i < 10) {
			letterCount += onesLetterCount (i);
		} else if (i < 100) {
			int ones = s [1] - 48;
			int tens = s [0] - 48;
			letterCount += onesLetterCount (ones);
			letterCount += tensLetterCount (tens, ones);
		} else if (i < 1000) {
			int ones = s [2] - 48;
			int tens = s [1] - 48;
			int hund = s [0] - 48;
			letterCount += onesLetterCount (ones);
			letterCount += tensLetterCount (tens, ones);
			letterCount += hundLetterCount (hund);
			if (tens != 0 || ones != 0) {
				letterCount += 3;	// and
			}
		} else {
			letterCount += 11;	// one thousand
		}
	}

	cout << letterCount << endl;

}