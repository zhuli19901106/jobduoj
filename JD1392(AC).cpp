#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int n;

bool comp(const string &s1, const string &s2)
{
	string s12, s21;

	s12 = s1 + s2;
	s21 = s2 + s1;

	return s12 < s21;
}

int main()
{
	int i;
	int val;
	char s[100];

	while (cin >> n) {
		if (n == 1) {
			cin >> val;
			cout << val << endl;
			continue;
		}
		for (i = 0; i < n; ++i) {
			cin >> val;
			sprintf(s, "%d", val);
			v.push_back(string(s));
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < n; ++i) {
			cout << v[i];
		}
		cout << endl;
		v.clear();
	}

	return 0;
}