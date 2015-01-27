#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

bool check(const string &s)
{
	int len = s.length() - 3;
	int i;

	for (i = 0; i < len; ++i) {
		if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '1' && s[i + 3] == '2') {
			return true;
		}
	}
	return false;
}

int main()
{
	int i;
	map<string, int> mm;
	map<string, int>::iterator it;
	queue<pair<string, int> > q;
	pair<string, int> psi;
	string str;
	int res;
	int len;
	int c[3];

	while (cin >> len >> str) {
		c[0] = c[1] = c[2] = 0;
		for (i = 0; i < len; ++i) {
			++c[str[i] - '0'];
		}
		if (c[0] < 1 || c[1] < 1 || c[2] < 2) {
			cout << -1 << endl;
			continue;
		}
		
		psi = make_pair(str, 0);
		q.push(psi);
		mm[str] = 0;
		len = str.length();
		res = -1;
		while (!q.empty()) {
			psi = q.front();
			q.pop();
			if (check(psi.first)) {
				res = mm[psi.first];
				break;
			}
			for (i = 0; i < len - 1; ++i) {
				swap(psi.first[i], psi.first[i + 1]);
				it = mm.find(psi.first);
				if (it == mm.end()) {
					q.push(make_pair(psi.first, psi.second + 1));
					mm[psi.first] = psi.second + 1;
				}
				swap(psi.first[i], psi.first[i + 1]);
			}
		}
		cout << res << endl;

		while (!q.empty()) {
			q.pop();
		}
		mm.clear();
	}

	return 0;
}