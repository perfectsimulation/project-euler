/*	Problem 42
	Coded Triangle Numbers

	The nth term of the sequence of triangle numbers is given by
	tn = (1/2)n(n+1)

	so the first ten triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	By converting each letter in a word to a number corresponding to its
	alphabetical position and adding these values we form a word value.

	For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word
	value is a triangle number then we shall call the word a triangle word.

	Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
	containing nearly two-thousand common English words, how many are triangle
	words?
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isTriangleNum (int x) {
	int triNum = 1;
	int n = 2;

	while (triNum <= x) {
		if (triNum == x) {
			return true;
		} else {
			triNum = n * (n + 1);
			triNum /= 2;
			n++;
		}
	}

	return false;
}

int main () {
	string line;
	ifstream words;
	words.open ("words_042.txt");

	//	Retrieve the words from the provided text file.
	if (words.is_open ()) {
		getline (words, line);
		words.close ();
	}

	//	Delete all " " in the words list.
	line.erase (remove (line.begin(), line.end (), '"'), line.end ());

	//	Add a delimiter so the final word is not skipped.
	line.append (",");

	//	Make a vector of all the words.
	int pos = 0;
	string delimiter = ",";
	string token;
	vector<string> wordsList;

	//	Fill the words vector.
	while ((pos = line.find (delimiter)) != string::npos) {
		token = line.substr (0, pos);
		wordsList.push_back (token);
		line.erase (0, pos + delimiter.length ());
	}

	//	Make a vector to hold the scores of each word.
	vector<int> scores;

	//	Fill the scores vector with each word score.
	for (auto i = wordsList.begin (); i != wordsList.end (); i++) {
		string word = *i;
		int score = 0;

		for (int j = 0; j < word.length (); j++) {
			score += (word [j] - 64);
		}

		if (isTriangleNum (score)) {
			scores.push_back (score);
		}
	}

	cout << scores.size () << endl;
}