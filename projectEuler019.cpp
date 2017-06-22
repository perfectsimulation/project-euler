/*	Problem 19
	Counting Sundays

	You are given the following information, but you may prefer to do some
	research for yourself.

	1 Jan 1900 was a Monday.
	Thirty days has September,
	April, June and November.
	All the rest have thirty-one,
	Saving February alone,
	Which has twenty-eight, rain or shine.
	And on leap years, twenty-nine.
	A leap year occurs on any year evenly divisible by 4, but not on a
	century unless it is divisible by 400.

	How many Sundays fell on the first of the month during the twentieth
	century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>

using namespace std;

int main () {
	int days = 0;
	int sundays = 0;

	for (int year = 1900; year <= 2000; year++) {
		for (int month = 1; month <= 12; month++) {
			if (month == 1 || month == 3 || month == 5 ||
				month == 7 || month == 8 || month == 10 || month == 12) {
				days += 31;
			} else if (month == 2) {	// Feb
				if (year == 1900) {
					days += 28;
				} else if (year % 4 == 0) {
					days += 29;
				} else {
					days += 28;
				}
			} else {	// Sep, Apr, Jun, Nov
				days += 30;
			}

			if (days % 7 == 6 && year != 1900) {
				sundays++;
			}
		}
		days = days % 7;
	}
	cout << sundays << endl;
}