/*	Problem 54
	Poker Hands

	In the card game poker, a hand consists of five cards and are ranked,
	from lowest to highest, in the following way:

	High Card:			Highest value card.
	One Pair:			Two cards of the same value.
	Two Pairs:			Two different pairs.
	Three of a Kind:	Three cards of the same value.
	Straight:			All cards are consecutive values.
	Flush:				All cards of the same suit.
	Full House:			Three of a kind and a pair.
	Four of a Kind:		Four cards of the same value.
	Straight Flush:		All cards are consecutive values of same suit.
	Royal Flush:		Ten, Jack, Queen, King, Ace, in same suit.

	The cards are valued in the order:
	2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

	If two players have the same ranked hands then the rank made up of the
	highest value wins; for example, a pair of eights beats a pair of fives
	(see example 1 below). But if two ranks tie, for example, both players
	have a pair of queens, then highest cards in each hand are compared (see
	example 4 below); if the highest cards tie then the next highest cards
	are compared, and so on.

	Consider the following five hands dealt to two players:

	Hand	 	Player 1	 	   Player 2	 	     Winner
	1	 	5H 5C 6S 7S KD      2C 3S 8S 8D TD      Player 2
			Pair of fives 	    Pair of Eights
	 	
	2	 	5D 8C 9S JS AC      2C 5C 7D 8S QH      Player 1
		   Highest card Ace    Highest card Queen
	 	
	3	 	2D 9C AS AH AC      3D 6D 7D TD QD	    Player 2
	          Three Aces      Flush with Diamonds

	4	 	4D 6S 9H QH QC      3D 6D 7H QD QS      Player 1
	        Pair of Queens      Pair of Queens
	      Highest card Nine   Highest card Seven

	5	 	2H 2D 4C 4D 4S      3C 3D 3S 9S 9D      Player 1
	          Full House          Full House
	      With Three Fours     With Three Threes
	
	The file, poker.txt, contains one-thousand random hands dealt to two
	players. Each line of the file contains ten cards (separated by a single
	space): the first five are Player 1's cards and the last five are
	Player 2's cards. You can assume that all hands are valid (no invalid
	characters or repeated cards), each player's hand is in no specific order,
	and in each hand there is a clear winner.

	How many hands does Player 1 win?
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//	Returns true if all cards are of the same suit.
bool isSameSuit (string hand) {
	char c1 = hand [1];
	char c2 = hand [3];
	char c3 = hand [5];
	char c4 = hand [7];
	char c5 = hand [9];

	return ((c1 == c2) && (c2 == c3) && (c3 == c4) && (c4 == c5));
}

//	Returns scores for T, J, Q, K, A.
int changeToScore (int card) {

	switch (card) {
		case (84 - 48):	//	T
			return 10;
		case (74 - 48):	//	J
			return 11;
		case (81 - 48):	//	Q
			return 12;
		case (75 - 48):	//	K
			return 13;
		case (65 - 48):	//	A
			return 14;
	}

	return 0;	//	Should never run.
}

//	Returns the scores of each card in the hand.
int* getScores (string hand, int c []) {

	c [0] = int (hand [0] - 48);
	c [1] = int (hand [2] - 48);
	c [2] = int (hand [4] - 48);
	c [3] = int (hand [6] - 48);
	c [4] = int (hand [8] - 48);

	//	Change T, J, Q, K, and A to corresponding score.
	for (int i = 0; i < 5; i++) {
		if (c [i] > 9) {
			c [i] = changeToScore (c [i]);
		}
	}

	return c;
}

//	Returns true if all cards in the hand are consecutive.
bool isConsecutive (string hand) {
	
	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	//	Get the lowest card value.
	int *minCard = min_element (c, c + 5);

	//	Check the rest of the cards for consecutive values.
	for (int i = 1; i < 5; i++) {
		int * p;
		p = find (c, c + 5, (*minCard + i));
		if (p == c + 5) {
			return false;
		}
	}

	return true;
}

//	Returns true if the hand is a royal flush.
bool isRoyalFlush (string hand) {
	//	Check if all cards are same suit.
	if (!isSameSuit (hand)) {
		return false;
	}
	//	Check if hand has a T, J, Q, K, and A.
	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	//	Get the lowest card value and return false if it's not 10.
	int *minCard = min_element (c, c + 5);
	if (*minCard != 10) {
		return false;
	}

		//	Check the rest of the cards for consecutive values.
		for (int i = 1; i < 5; i++) {
			int * p;
			p = find (c, c + 5, (*minCard + i));
			if (p == c + 5) {
				return false;
			}
		}

	return true;
}

//	Returns true if the hand is a straight flush.
bool isStraightFlush (string hand) {
	//	Check if all cards are same suit.
	if (!isSameSuit (hand)) {
		return false;
	}
	//	Check if all cards are consecutive.
	if (!isConsecutive (hand)) {
		return false;
	}

	return true;
}

//	Returns true if the hand is a four of a kind.
bool is4ofaKind (string hand) {

	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (c [j] == i) {
				count++;
			}
		}

		if (count == 4) {
			return true;
		}
	}

	return false;
}

//	Returns true if the hand is a full house.
bool isFullHouse (string hand) {

	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	//	Check for three of a kind.
	int triple = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (c [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			triple = i;
			break;
		}
	}

	if (triple == 0) {
		return false;
	}

	//	There is a three of a kind. Now check for a pair.
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((c [j] == i) && (i != triple)) {
				count++;
			}
		}

		if (count == 2) {
			return true;
		}
	}

	return false;
}

//	Returns true if the hand is a flush.
bool isFlush (string hand) {
	//	Check if all cards are same suit.
	return (isSameSuit (hand));
}

//	Returns true if the hand is a straight.
bool isStraight (string hand) {
	//	Check if all cards are consecutive.
	return (isConsecutive (hand));
}

//	Returns true if the hand is a three of a kind.
bool is3ofaKind (string hand) {

	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (c [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			return true;
		}
	}

	return false;
}

//	Returns true if the hand is a two pairs.
bool is2pairs (string hand) {

	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	//	Check for first pair.
	int pair1 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (c [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			pair1 = i;
			break;
		}
	}

	if (pair1 == 0) {
		return false;
	}

	//	There is one pair. Now check for another.
	for (int i = pair1 + 1; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((c [j] == i)) {
				count++;
			}
		}

		if (count == 2) {
			return true;
		}
	}

	return false;
}

//	Returns true if the hand is a one pair.
bool is1pair (string hand) {

	int cTemp [5] = { };
	int *c = getScores (hand, cTemp);

	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (c [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			return true;
		}
	}

	return false;
}

//	Returns 1 if player 1 wins, 2 otherwise.
int highCard (string p1, string p2) {

	int p1Temp [5] = { };
	int *h1 = getScores (p1, p1Temp);
	int *high1 = max_element (h1, h1 + 5);

	int p2Temp [5] = { };
	int *h2 = getScores (p2, p2Temp);
	int *high2 = max_element (h2, h2 + 5);

	//	If there is a tie, move to the next highest.
	while (*high1 == *high2) {
		*high1 = 0;
		*high2 = 0;
		high1 = max_element (h1, h1 + 5);
		high2 = max_element (h2, h2 + 5);
	}

	return (*high1 > *high2) ? 1 : 2;
}

//	Returns 1 if player 1 wins, 2 otherwise.
int straightFlushTie (string p1, string p2) {
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int fourOfaKindTie (string p1, string p2) {
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int fullHouseTie (string p1, string p2) {

	int p1Temp [5] = { };
	int *h1 = getScores (p1, p1Temp);

	int p2Temp [5] = { };
	int *h2 = getScores (p2, p2Temp);

	//	Get score of player 1's three of a kind.
	int triple1 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h1 [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			triple1 = i;
			break;
		}
	}

	//	Get score of player 2's three of a kind.
	int triple2 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h2 [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			triple2 = i;
			break;
		}
	}

	if (triple1 != triple2) {
		return (triple1 > triple2) ? 1 : 2;
	}

	//	Both players have the same score for their respective three of a kinds.
	//	Tie break with their pairs.

	//	Get score of player 1's pair.
	int pair1 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((h1 [j] == i) && (i != triple1)) {
				count++;
			}
		}

		if (count == 2) {
			pair1 = i;
			break;
		}
	}

	//	Get score of player 2's pair.
	int pair2 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((h2 [j] == i) && (i != triple2)) {
				count++;
			}
		}

		if (count == 2) {
			pair2 = i;
			break;
		}
	}

	return (pair1 > pair2) ? 1 : 2;
}

//	Returns 1 if player 1 wins, 2 otherwise.
int flushTie (string p1, string p2) {
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int straightTie (string p1, string p2) {
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int threeOfaKindTie (string p1, string p2) {

	int p1Temp [5] = { };
	int *h1 = getScores (p1, p1Temp);

	int p2Temp [5] = { };
	int *h2 = getScores (p2, p2Temp);

	//	Get score of player 1's three of a kind.
	int triple1 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h1 [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			triple1 = i;
			break;
		}
	}

	//	Get score of player 2's three of a kind.
	int triple2 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h2 [j] == i) {
				count++;
			}
		}

		if (count == 3) {
			triple2 = i;
			break;
		}
	}

	if (triple1 != triple2) {
		return (triple1 > triple2) ? 1 : 2;
	}

	//	Both players have the same score for their respective three of a kinds.
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int twoPairsTie (string p1, string p2) {
	
	int p1Temp [5] = { };
	int *h1 = getScores (p1, p1Temp);

	int p2Temp [5] = { };
	int *h2 = getScores (p2, p2Temp);

	//	Get player 1's first pair.
	int p11 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h1 [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			p11 = i;
			break;
		}
	}

	//	Get player 1's other pair.
	int p12 = 0;
	for (int i = p11 + 1; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((h1 [j] == i)) {
				count++;
			}
		}

		if (count == 2) {
			p12 = i;
		}
	}


	//	Get player 2's first pair.
	int p21 = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h2 [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			p21 = i;
			break;
		}
	}

	//	Get player 2's other pair.
	int p22 = 0;
	for (int i = p21 + 1; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if ((h2 [j] == i)) {
				count++;
			}
		}

		if (count == 2) {
			p22 = i;
		}
	}

	if ((p11 > p21) && (p11 > p22)) {
		return 1;
	}

	if ((p12 > p21) && (p12 > p22)) {
		return 1;
	}

	if ((p21 > p11) && (p21 > p12)) {
		return 2;
	}

	if ((p22 > p11) && (p22 > p12)) {
		return 2;
	}

	//	At least one pair is common between the players.
	if ((p11 == p21) && (p11 != p22)) {
		return (p11 > p22) ? 1 : 2;
	}

	if ((p11 == p22) && (p11 != p21)) {
		return (p11 > p21) ? 1 : 2;
	}

	if ((p21 == p11) && (p21 != p12)) {
		return (p21 > p12) ? 2 : 1;
	}

	if ((p21 == p12) && (p21 != p11)) {
		return (p21 > p11) ? 2 : 1;
	}

	//	Both players have the same values for their 2 pairs.
	//	Check the last card.
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int onePairTie (string p1, string p2) {

	int p1Temp [5] = { };
	int *h1 = getScores (p1, p1Temp);

	int p2Temp [5] = { };
	int *h2 = getScores (p2, p2Temp);

	//	Get player 1's pair.
	int p1pair = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h1 [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			p1pair = i;
			break;
		}
	}

	//	Get player 2's pair.
	int p2pair = 0;
	for (int i = 2; i < 15; i++) {
		int count = 0;

		for (int j = 0; j < 5; j++) {
			if (h2 [j] == i) {
				count++;
			}
		}

		if (count == 2) {
			p2pair = i;
			break;
		}
	}

	if (p1pair != p2pair) {
		return (p1pair > p2pair) ? 1 : 2;
	}

	//	Both players have the same values for their pairs.
	return highCard (p1, p2);
}

//	Returns 1 if player 1 wins, 2 otherwise.
int evalHands (string p1, string p2) {

	//	Does one player have a royal flush?
	if (isRoyalFlush (p1)) {
		return 1;
	} else if (isRoyalFlush (p2)) {
		return 2;
	}

	//	Does one player have a straight flush?
	//	If both have, tie break.
	if (isStraightFlush (p1) && !isStraightFlush (p2)) {
		return 1;
	} else if (isStraightFlush (p2) && !isStraightFlush (p1)) {
		return 2;
	} else if (isStraightFlush (p1) && isStraightFlush (p2)) {
		return straightFlushTie (p1, p2);
	}

	//	Does one player have a four of a kind?
	//	If both have, tie break.
	if (is4ofaKind (p1) && !is4ofaKind (p2)) {
		return 1;
	} else if (is4ofaKind (p2) && !is4ofaKind (p1)) {
		return 2;
	} else if (is4ofaKind (p1) && is4ofaKind (p2)) {
		return fourOfaKindTie (p1, p2);
	}

	//	Does one player have a full house?
	//	If both have, tie break.
	if (isFullHouse (p1) && !isFullHouse (p2)) {
		return 1;
	} else if (isFullHouse (p2) && !isFullHouse (p1)) {
		return 2;
	} else if (isFullHouse (p1) && isFullHouse (p2)) {
		return fullHouseTie (p1, p2);
	}

	//	Does one player have a flush?
	//	If both have, tie break.
	if (isFlush (p1) && !isFlush (p2)) {
		return 1;
	} else if (isFlush (p2) && !isFlush (p1)) {
		return 2;
	} else if (isFlush (p1) && isFlush (p2)) {
		return flushTie (p1, p2);
	}

	//	Does one player have a straight?
	//	If both have, tie break.
	if (isStraight (p1) && !isStraight (p2)) {
		return 1;
	} else if (isStraight (p2) && !isStraight (p1)) {
		return 2;
	} else if (isStraight (p1) && isStraight (p2)) {
		return straightTie (p1, p2);
	}

	//	Does one player have a three of a kind?
	//	If both have, tie break.
	if (is3ofaKind (p1) && !is3ofaKind (p2)) {
		return 1;
	} else if (is3ofaKind (p2) && !is3ofaKind (p1)) {
		return 2;
	} else if (is3ofaKind (p1) && is3ofaKind (p2)) {
		return threeOfaKindTie (p1, p2);
	}

	//	Does one player have a two pairs?
	//	If both have, tie break.
	if (is2pairs (p1) && !is2pairs (p2)) {
		return 1;
	} else if (is2pairs (p2) && !is2pairs (p1)) {
		return 2;
	} else if (is2pairs (p1) && is2pairs (p2)) {
		return twoPairsTie (p1, p2);
	}

	//	Does one player have a one pair?
	//	If both have, tie break.
	if (is1pair (p1) && !is1pair (p2)) {
		return 1;
	} else if (is1pair (p2) && !is1pair (p1)) {
		return 2;
	} else if (is1pair (p1) && is1pair (p2)) {
		return onePairTie (p1, p2);
	}

	//	Neither player had any of the above.
	return highCard (p1, p2);
}

int main () {

	int player1wins = 0;

	string line;
	ifstream myfile ("poker_054.txt");

	if (myfile.is_open ()) {
		int ind = 0;
		while (getline (myfile, line)) {
			line.erase (remove_if (line.begin (), line.end (), isspace), line.end ());
			string player1 = line.substr (0, 10);
			string player2 = line.substr (10, 10);
			if (evalHands (player1, player2) == 1) {
				player1wins++;
			}
			// cout << player1 [ind] << " " << player2 [ind] << endl;
			ind++;
		}
		myfile.close ();
	}

	cout << player1wins << endl;
}

//	Test cases.
// int main () {
// 	string line1 = "5H5C6S7SKD";
// 	string line2 = "2C3S8S8DTD";	// Player 2 Win

// 	string line1 = "5D8C9SJSAC";
// 	string line2 = "2C5C7D8SQH";	// Player 1 Win

// 	string line1 = "2D9CASAHAC";
// 	string line2 = "3D6D7DTDQD";	// Player 2 Win

// 	string line1 = "4D6S9HQHQC";
// 	string line2 = "3D6D7HQDQS";	// Player 1 Win

// 	string line1 = "2H2D4C4D4S";
// 	string line2 = "3C3D3S9S9D";	// Player 1 Win

// 	cout << evalHands (line1, line2) << endl;
// }