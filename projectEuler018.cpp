/*	Problem 18
	Maximum Path Sum I
	
	By starting at the top of the triangle below and moving to adjacent
	numbers on the row below, the maximum total from top to bottom is 23.

	3
	7 4
	2 4 6
	8 5 9 3

	That is, 3 + 7 + 4 + 9 = 23.

	Find the maximum total from top to bottom of the triangle below:

	75
	95 64
	17 47 82
	18 35 87 10
	20 04 82 47 65
	19 01 23 75 03 34
	88 02 77 73 07 63 67
	99 65 04 28 06 16 70 92
	41 41 26 56 83 40 80 70 33
	41 48 72 33 47 32 37 16 94 29
	53 71 44 65 25 43 91 52 97 51 14
	70 11 33 28 77 73 17 78 39 68 17 57
	91 71 52 38 17 14 91 43 58 50 27 29 48
	63 66 04 68 89 53 67 30 73 16 69 87 40 31
	04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

	NOTE: As there are only 16384 routes, it is possible to solve this problem
	by trying every route. However, Problem 67, is the same challenge with a
	triangle containing one-hundred rows; it cannot be solved by brute force,
	and requires a clever method! ;o)
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// A binary tree node
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

// A utility function to allocate a new node
struct Node* newNode (int data) {
	struct Node *newNode = new Node;
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return (newNode);
}

// Ended up not needing either of the two functions below.
// Did not use the Node struct to compute the max sum.
void insertLeft (int data, Node *leaf) {
	if (leaf -> left != NULL) {
		insertLeft (data, leaf -> left);
	} else {
		leaf -> left = new Node;
		leaf -> left -> data = data;
		leaf -> left -> left = NULL;
		leaf -> left -> right = NULL;
	}
}

void insertRight (int data, Node *leaf) {
	if (leaf -> right != NULL) {
		insertRight (data, leaf -> right);
	} else {
		leaf -> right = new Node;
		leaf -> right -> data = data;
		leaf -> right -> left = NULL;
		leaf -> right -> right = NULL;
	}
}

int main () {
	int triangle [15][15] = { };
	int triangleCopy [15][15] = { };

	string s =
	"75"
	"95 64"
	"17 47 82"
	"18 35 87 10"
	"20 04 82 47 65"
	"19 01 23 75 03 34"
	"88 02 77 73 07 63 67"
	"99 65 04 28 06 16 70 92"
	"41 41 26 56 83 40 80 70 33"
	"41 48 72 33 47 32 37 16 94 29"
	"53 71 44 65 25 43 91 52 97 51 14"
	"70 11 33 28 77 73 17 78 39 68 17 57"
	"91 71 52 38 17 14 91 43 58 50 27 29 48"
	"63 66 04 68 89 53 67 30 73 16 69 87 40 31"
	"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

	s.erase (remove_if (s.begin (), s.end (), isspace), s.end ());

	for (int row = 0; row < 15; row++) {
		for (int j = 0; j <= row; j++) {
			int ones = s [1] - 48;
			int tens = (s [0] - 48) * 10;
			int num = ones + tens;
			triangle [row] [j] = num;
			triangleCopy [row] [j] = num;
			s.erase (s.begin (), s.begin () + 2);
		}
	}

	struct Node *root = newNode (triangle [0][0]);

	for (int row = 0; row < 14; row++) {
		for (int j = 0; j <= row; j++) {
			insertLeft (triangle [row + 1][j], root);
			insertRight (triangle [row + 1][j + 1], root);
		}
	}
	
	// Compute the max sum of the tree using a bottom-up approach.
	for (int row = 14; row > 0; row--) {
		for (int j = 0; j < row; j++) {
			int pathA = triangle [row - 1][j] + triangle [row][j];
			int pathB = triangle [row - 1][j] + triangle [row][j + 1];
			if (pathA > pathB) {
				triangle [row - 1][j] += triangle [row][j];
			} else {
				triangle [row - 1][j] += triangle [row][j + 1];
			}
		}
	}

	for (int row = 0; row < 14; row++) {
		for (int j = 0; j <= row; j++) {
			cout << triangle [row][j] << " ";
		}
		cout << endl;
	}
}