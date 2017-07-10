/*	Problem 51
	Prime Digit Replacements

	By replacing the 1st digit of the 2-digit number *3, it turns out that
	six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all
	prime.

	By replacing the 3rd and 4th digits of 56**3 with the same digit,
	this 5-digit number is the first example having seven primes among the
	ten generated numbers, yielding the family:
	56003, 56113, 56333, 56443, 56663, 56773, and 56993.

	Consequently 56003, being the first member of this family, is the
	smallest prime with this property.

	Find the smallest prime which, by replacing part of the number
	(not necessarily adjacent digits) with the same digit, is part of an
	eight prime value family.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strToInt (string s) {
	int result = 0;

	for (int i = 0; i < s.length (); i++) {
		result += int (s [i] - 48) * pow (10, s.length () - 1 - i);
	}

	return result;
}

int main () {

	vector <int> primes;
	string line;
	ifstream myfile ("primes.txt");						//	primes.txt is a list of all primes < 1 million.
	if (myfile.is_open ()) {
		while (getline (myfile, line)) {
			int p = strToInt (line);
			if (p > 99999) {
				primes.push_back (p);				//	Only consider primes containing six digits.
			}
		}
		myfile.close ();
	}

	for (auto a = primes.begin (); a < primes.end (); a++) {		//	For each prime...
		string s = to_string (*a);
		int num [6] = { };						//	Contains the digits of a given prime.
		int family = 1;							//	Number of successfully replaced primes for a given prime.
		vector <int> members;						//	Contains all primes in a given prime's "family."
		members.push_back (*a);						//	The given prime is the first element of members.
		
		for (int b = 0; b < 6; b++) {
			num [b] = int (s [b] - 48);
		}

		int digits [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int occurences [10] = { };					//	Keeps track of # times each digit appears for a given prime.

		for (int c = 0; c < 6; c++) {
			for (int d = 0; d < 10; d++) {
				if (num [c] == digits [d]) {
					occurences [d]++;			//	# times the digit x occurs is stored in occurences [x].
				}
			}
		}

		bool repeats = false;						//	Used to signal if there are any digits occuring more than once.
		
		while (!repeats) {
			repeats = true;
			int repeatDigit = 0;

			members.erase (members.begin () + 1,members.end ());	//	There is one members vector per repeating digit.
			family = 1;

			for (int e = 0; e < 10; e++) {
				if (occurences [e] > 1) {
					repeatDigit = e;
					occurences [e] = 0;
					repeats = false;
					break;
				}
			}

			if (repeats) {
				break;
			}

			vector <int> places;									//	Contains the indices where the repeating digit occurs.
			for (int f = 0; f < 6; f++) {
				if (num [f] == repeatDigit) {
					places.push_back (f);
				}
			}

			for (int g = 0; g < 10; g++) {								//	Replace repeating digits with 0 thru 9.
				int numRep [6] = { };

				for (int h = 0; h < 6; h++) {
					numRep [h] = num [h];
				}

				bool isFirstDigit0 = false;
				for (auto i = places.begin (); i < places.end (); i++) {
					if ((*i == 0) && (g == 0)) {						//	Avoid replacing the first digit with 0.
						isFirstDigit0 = true;
					}
					if (!isFirstDigit0 || (g != 0)) {
						numRep [*i] = g;
					}
				}

				string numRepStr = "";
				for (int j = 0; j < 6; j++) {
					numRepStr += to_string (numRep [j]);
				}

				int rep = strToInt (numRepStr);							//	The new number with replaced digits.
				if (find (primes.begin (), primes.end (), rep) != primes.end ()) {		//	If the new number is prime...
					if (find (members.begin (), members.end (), rep) == members.end ()) {	//	... and it's not already in members...
						members.push_back (rep);					//	Add the new digit-replaced prime to members
						family++;							//	and increment family.
					}
				}

			}

			if (family == 8) {									//	Once the first prime with a family of 8 is found,
				for (auto k = members.begin (); k < members.end (); k++) {			//	end the program.
					cout << *k << " ";
				}
				cout << endl;
				break;
			}
		}

		if (family == 8) {
			break;
		}
		
	}

}
