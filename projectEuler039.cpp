/*	Problem 39
	Integer Right Triangles

	If p is the perimeter of a right angle triangle with integral length sides,
	{a,b,c}, there are exactly three solutions for p = 120.

	{20,48,52}, {24,45,51}, {30,40,50}

	For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <cmath>
#include <iostream>

using namespace std;

int main () {
	int maxNumSolutions = 0;
	int maxP = 0;

	for (int p = 2; p <= 1000; p++) {
		int numSolutions = 0;

		for (int i = 1; i < p; i++) {
			for (int j = 1; j < p; j++) {

				double k = sqrt (pow (double (i), 2) + pow (double (j), 2));
				if (floor (k) == k) {
					if (i + j + k == p) {
						numSolutions++;
					}
				}
			}
		}

		if (numSolutions > maxNumSolutions) {
			maxP = p;
			maxNumSolutions = numSolutions;
		}
	}

	cout << maxP << " had " << maxNumSolutions << " solutions." << endl;
}