#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	string ss;
	int len, i, j;
	map<string, int> mm;
	map<string, int>::iterator it;

	while (cin >> s) {
		len = s.length();
		for (i = 0; i < len; ++i) {
			ss.clear();
			for (j = i; j < len; ++j) {
				ss.push_back(s[j]);
				++mm[ss];
			}
		}

		for (it = mm.begin(); it != mm.end(); ++it) {
			if (it->second <= 1) {
				continue;
			}
			cout << it->first << " " << it->second << endl;
		}

		mm.clear();
	}

	return 0;
}