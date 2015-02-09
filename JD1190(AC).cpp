#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool comparator(const string &s1, const string &s2)
{
	if (s1.length() != s2.length()) {
		return s1.length() < s2.length();
	} else {
		return s1 < s2;
	}
}

int main()
{
	int n, i;
	vector<string> v;

	while (cin >> n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < n; ++i) {
			cout << v[i] << endl;
		}
		v.clear();
	}

	return 0;
}