#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void exe(string &s, string &op)
{
	int i;
	int start;
	int len;

	start = op[1] - '0';
	len = op[2] - '0';
	if (op[0] == '0') {
		for (i = start; i < 2* start + len - 1 - i; ++i) {
			swap(s[i], s[2* start + len - 1 - i]);
		}
	} else if (op[0] == '1') {
		for (i = start; i <= start + len - 1; ++i) {
			s[i] = op[i - start + 3];
		}
	}
}

int main()
{
	string s, op;
	int n, i;

	while (cin >> s) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> op;
			exe(s, op);
			cout << s << endl;
		}
	}

	return 0;
}