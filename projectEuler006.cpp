/*	Problem 6
	Sum Square Difference

	The sum of the squares of the first ten natural numbers is

	1^2 + 2^2 + ... + 10^2 = 385
	
	The square of the sum of the first ten natural numbers is

	(1 + 2 + ... + 10)^2 = 55^2 = 3025

	Hence the difference between the sum of the squares of the first ten
	natural numbers and the square of the sum is

	3025 − 385 = 2640.

	Find the difference between the sum of the squares of the first
	one hundred natural numbers and the square of the sum.
*/

#include <iomanip>
#include <iostream>

using namespace std;

void main () {
	float largestMember = 100;
	float sum = 0;
	float sumOfSquares = 0;
	float squareOfSum = 0;

	for (int i = 1; i <= largestMember; i++) {
		sum += i;
		sumOfSquares += (i * i);
	}

	squareOfSum = sum * sum;

	cout << setprecision (0) << fixed;
	cout << squareOfSum << endl;
	cout << sumOfSquares << endl;
	cout << squareOfSum - sumOfSquares << endl;
}