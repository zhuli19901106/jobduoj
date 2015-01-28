#include <iostream>
#include <map>
#include <string>
using namespace std;

inline bool leap(const int y)
{
	return y % 100 ? y % 4 == 0 : y % 400 == 0;
}

int main()
{
	int y, m, d;
	int dc;
	map<string, int> mn;
	map<int, string> wd;
	int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	mn["January"] = 1;
	mn["February"] = 2;
	mn["March"] = 3;
	mn["April"] = 4;
	mn["May"] = 5;
	mn["June"] = 6;
	mn["July"] = 7;
	mn["August"] = 8;
	mn["September"] = 9;
	mn["October"] = 10;
	mn["November"] = 11;
	mn["December"] = 12;
	
	wd[0] = "Sunday";
	wd[1] = "Monday";
	wd[2] = "Tuesday";
	wd[3] = "Wednesday";
	wd[4] = "Thursday";
	wd[5] = "Friday";
	wd[6] = "Saturday";

	string str;
	int i;

	while (cin >> d >> str >> y) {
		m = mn[str];
		dc = 0;
		y %= 400;
		for (i = 0; i < y; ++i) {
			dc += leap(i) ? 366 : 365;
		}
		for (i = 1; i < m; ++i) {
			dc += md[i];
			if (i == 2 && leap(y)) {
				++dc;
			}
		}
		dc += d - 1;
		dc = (dc + 6) % 7;
		cout << wd[dc] << endl;
	}

	return 0;
}