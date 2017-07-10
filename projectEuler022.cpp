/*	Problem 22
	Names Scores

	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
	containing over five-thousand first names, begin by sorting it into
	alphabetical order. Then working out the alphabetical value for each name,
	multiply this value by its alphabetical position in the list to obtain
	a name score.

	For example, when the list is sorted into alphabetical order, COLIN,
	which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
	So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file?
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	string line;
	ifstream names;
	names.open ("names_022.txt");

	//	Retrieve the names from the provided text file.
	if (names.is_open ()) {
		getline (names, line);
		names.close ();
	}

	//	Delete all " " in the names list.
	line.erase (remove (line.begin (), line.end (), '"'), line.end ());
	
	//	Add a delimiter so the final name is not skipped.
	line.append (",");

	//	Make a vector of all the names.
	int pos = 0;
	string delimiter = ",";
	string token;
	vector<string> namesList;

	//	Fill the names vector.
	while ((pos = line.find (delimiter)) != string::npos) {
		token = line.substr (0, pos);
		namesList.push_back (token);
		line.erase (0, pos + delimiter.length ());
	}

	//	Conveniently sort the names list alphabetically.
	sort (namesList.begin (), namesList.end ());

	//	Make a vector to hold the scores of each name.
	vector<int> scores;

	//	Make a counter to multiply the raw name score with the list position.
	int counter = 1;

	//	Fill the scores vector with each name score.
	for (auto i = namesList.begin (); i != namesList.end (); i++) {
		string name = *i;
		int score = 0;

		for (int j = 0; j < name.length (); j++) {
			score += (name [j] - 64);
		}

		score *= counter;
		scores.push_back (score);
		counter++;
	}

	//	Sum all the name scores into totalScore.
	int totalScore = 0;

	for (auto i = scores.begin (); i != scores.end (); i++) {
		totalScore += *i;
	}

	cout << totalScore << endl;
}