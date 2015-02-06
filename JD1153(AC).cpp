#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<int> sp;
	string s, t;
	int n;
	int i;

	while (cin >> s) {
		n = s.length();
		t.resize(n, ' ');
		for (i = 0; i < n; ++i) {
			if (s[i] == '(') {
				sp.push(i);
			} else if (s[i] == ')') {
				if (sp.empty()) {
					t[i] = '?';
				} else {
					sp.pop();
				}
			}
		}
		while (!sp.empty()) {
			t[sp.top()] = '$';
			sp.pop();
		}
		cout << s << endl;
		cout << t << endl;

		s.clear();
		t.clear();
	}

	return 0;
}