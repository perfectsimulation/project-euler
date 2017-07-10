/*	Problem 29
	Distinct Powers

	Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

	2^2=4, 2^3=8, 2^4=16, 2^5=32
	3^2=9, 3^3=27, 3^4=81, 3^5=243
	4^2=16, 4^3=64, 4^4=256, 4^5=1024
	5^2=25, 5^3=125, 5^4=625, 5^5=3125

	If they are then placed in numerical order, with any repeats removed,
	we get the following sequence of 15 distinct terms:

	4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

	How many distinct terms are in the sequence generated by a^b for
	2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	vector<string> vec;

	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= 100; j++) {

			//	Create an array to represent the number a.
			int term [205] = { };
			int ones [205] = { };
			int tens [205] = { };
			int hund [205] = { };
			string s = to_string (i);

			if (i < 10) {
				term [204] = s [0] - 48;
				ones [204] = s [0] - 48;
				tens [204] = s [0] - 48;
				hund [204] = s [0] - 48;
			} else if (i < 100) {
				term [204] = s [1] - 48;
				term [203] = s [0] - 48;
				ones [204] = s [1] - 48;
				ones [203] = s [0] - 48;
				tens [204] = s [1] - 48;
				tens [203] = s [0] - 48;
				hund [204] = s [1] - 48;
				hund [203] = s [0] - 48;
			} else {
				term [204] = s [2] - 48;
				term [203] = s [1] - 48;
				term [202] = s [0] - 48;
				ones [204] = s [2] - 48;
				ones [203] = s [1] - 48;
				ones [202] = s [0] - 48;
				tens [204] = s [2] - 48;
				tens [203] = s [1] - 48;
				tens [202] = s [0] - 48;
				hund [204] = s [2] - 48;
				hund [203] = s [1] - 48;
				hund [202] = s [0] - 48;
			}

			//	Multiply each member in the array by i (j times).
			for (int power = 1; power < j; power++) {

				for (int n = 0; n < 205; n++) {
					ones [n] = term [n];
					tens [n] = term [n];
					hund [n] = term [n];
				}

				for (int digit = 0; digit <= s.length () - 1; digit++) {
					for (int index = 0; index < 205; index++) {
						if (term [index] != 0) {
							if (digit == 2) {
								int product = term [index] * int (s [digit] - 48);
								ones [index] = product;
							} else if (digit == 1) {
								if (i < 100) {
									int product = term [index] * int (s [digit] - 48);
									ones [index] = product;
								} else {
									int product = (term [index] * int (s [digit] - 48)) * 10;
									tens [index] = product;
								}
							} else {
								if (i == 100) {
									int product = (term [index] * int (s [digit] - 48)) * 100;
									hund [index] = product;
								} else if (i > 9) {
									int product = (term [index] * int (s [digit] - 48)) * 10;
									tens [index] = product;
								} else {
									int product = term [index] * int (s [digit] - 48);
									ones [index] = product;
								}
							}


							if (hund [index] > 9) {
								int multiDigits = 1;

								while (multiDigits != 0) {
									multiDigits = 0;

									for (int x = 0; x < 205; x++) {
										if (hund [x] > 999) {
											multiDigits++;
											string xs = to_string (hund [x]);
											hund [x] = int (xs [3] - 48);
											hund [x - 1] += int (xs [2] - 48);
											hund [x - 2] += int (xs [1] - 48);
											hund [x - 3] += int (xs [0] - 48);
											break;
										} else if (hund [x] > 99) {
											multiDigits++;
											string xs = to_string (hund [x]);
											hund [x] = int (xs [2] - 48);
											hund [x - 1] += int (xs [1] - 48);
											hund [x - 2] += int (xs [0] - 48);
											break;
										} else if (hund [x] > 9) {
											multiDigits++;
											string xs = to_string (hund [x]);
											hund [x] = int (xs [1] - 48);
											hund [x - 1] += int (xs [0] - 48);
											break;
										}
									}

								}
							}

							if (tens [index] > 9) {
								int multiDigits = 1;

								while (multiDigits != 0) {
									multiDigits = 0;

									for (int x = 0; x < 205; x++) {
										if (tens [x] > 99) {
											multiDigits++;
											string xs = to_string (tens [x]);
											tens [x] = int (xs [2] - 48);
											tens [x - 1] += int (xs [1] - 48);
											tens [x - 2] += int (xs [0] - 48);
											break;
										} else if (tens [x] > 9) {
											multiDigits++;
											string xs = to_string (tens [x]);
											tens [x] = int (xs [1] - 48);
											tens [x - 1] += int (xs [0] - 48);
											break;
										}
									}

								}
							}

							if (ones [index] > 9) {
								int multiDigits = 1;

								while (multiDigits != 0) {
									multiDigits = 0;

									for (int x = 0; x < 205; x++) {
										if (ones [x] > 99) {
											multiDigits++;
											string xs = to_string (ones [x]);
											ones [x] = int (xs [2] - 48);
											ones [x - 1] += int (xs [1] - 48);
											ones [x - 2] += int (xs [0] - 48);
											break;
										} else if (ones [x] > 9) {
											multiDigits++;
											string xs = to_string (ones [x]);
											ones [x] = int (xs [1] - 48);
											ones [x - 1] += int (xs [0] - 48);
											break;
										}
									}

								}
							}
						}

					}
				}

				for (int k = 0; k < 205; k++) {

					if (i > 99) {
						term [k] = ones [k] + tens [k] + hund [k];
					} else if (i > 9) {
						term [k] = ones [k] + tens [k];
					} else {
						term [k] = ones [k];
					}

					int multiDigits = 1;

					while (multiDigits != 0) {
						multiDigits = 0;

						for (int x = 0; x < 205; x++) {
							if (term [x] > 999) {
								multiDigits++;
								string xs = to_string (term [x]);
								term [x] = int (xs [3] - 48);
								term [x - 1] += int (xs [2] - 48);
								term [x - 2] += int (xs [1] - 48);
								term [x - 3] += int (xs [0] - 48);
								break;
							} else if (term [x] > 99) {
								multiDigits++;
								string xs = to_string (term [x]);
								term [x] = int (xs [2] - 48);
								term [x - 1] += int (xs [1] - 48);
								term [x - 2] += int (xs [0] - 48);
								break;
							} else if (term [x] > 9) {
								multiDigits++;
								string xs = to_string (term [x]);
								term [x] = int (xs [1] - 48);
								term [x - 1] += int (xs [0] - 48);
								break;
							}
						}

					}
				}
			}

			string termString = "";
			for (int k = 0; k < 205; k++) {
				termString += to_string (term [k]);
			}

			while (int (termString [0] - 48) == 0) {
				termString.erase (termString.begin ());
			}

			if (find (vec.begin (), vec.end (), termString) == vec.end ()) {
				vec.push_back (termString);
			} else {
				cout << termString << " " << i << " " << j << endl;
			}
		}
	}

	cout << vec.size () << endl;

}