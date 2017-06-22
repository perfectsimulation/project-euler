/*	Problem 4
	Largest Palindrome Product

	A palindromic number reads the same both ways.
	The largest palindrome made from the product of two 2-digit numbers is
	9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome (int num) {
	bool isProductPalindrome = true;
	string productString = to_string(num);

	for (int i = 0; i < productString.length (); i++) {
		if (productString [i] != productString [productString.length () - 1 - i]) {
			isProductPalindrome = false;
			break;
		}
	}

	return isProductPalindrome;
}

void main () {
	bool palindrome = false;
	int product = 999 * 999;
	int largestCandidate = 0;
	for (int n1 = 999; n1 > 99; n1--) {
		for (int n2 = 999; n2 > 99; n2--) {
			product = n1 * n2;
			palindrome = isPalindrome (product);
			if (palindrome) {
				if (product > largestCandidate) {
					cout << n1 << " and " << n2 << endl;
					largestCandidate = product;
					break;
				} else {
					break;
				}
			}
		}
	}

	cout << largestCandidate << endl;
}