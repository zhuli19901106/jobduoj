#include <iostream>
#include <string>
#include <vector>
using namespace std;

void lower(string &s)
{
	int i, len;

	len = s.length();
	for (i = 0; i < len; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
}

bool match(string &s, string &p)
{
	int ls = s.length();
	int lp = p.length();

	int i, j;
	int ll, rr, k;

	i = j = 0;
	while (j < lp) {
		if (i >= ls) {
			return false;
		}
		if (p[j] == '[') {
			ll = rr = j + 1;
			while (p[rr] != ']') {
				++rr;
			}
			for (k = ll; k < rr; ++k) {
				if (s[i] == p[k]) {
					break;
				}
			}
			if (k == rr) {
				return false;
			}
			j = rr + 1;
			++i;
		} else if (s[i] == p[j]) {
			++i;
			++j;
		} else {
			return false;
		}
	}

	return i == ls;
}

int main()
{
	vector<string> v1, v2;
	string p;
	int n, i;

	while (cin >> n) {
		v1.resize(n);
		v2.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v1[i];
			v2[i] = v1[i];
			lower(v2[i]);
		}
		cin >> p;
		lower(p);
		for (i = 0; i < n; ++i) {
			if (match(v2[i], p)) {
				cout << i + 1 << " " << v1[i] << endl;
			}
		}

		v1.clear();
		v2.clear();
	}

	return 0;
}