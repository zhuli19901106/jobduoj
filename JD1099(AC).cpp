#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	vector<string> ss;
	int i;

	while (cin >> s) {
		for (i = (int)s.length() - 1; i >= 0; --i) {
			ss.push_back(s.substr(i, s.length() - i));
		}
		sort(ss.begin(), ss.end());
		for (i = 0; i < (int)ss.size(); ++i) {
			cout << ss[i] << endl;
		}
		ss.clear();
	}

	return 0;
}