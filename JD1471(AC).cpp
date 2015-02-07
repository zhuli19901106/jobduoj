#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b, c;
	int i;
	int la;

	while (cin >> a >> b) {
		reverse(b.begin(), b.end());
		la = a.length();
		for (i = 0; i < la; ++i) {
			c.push_back(a[i]);
			c.push_back(b[i]);
		}
		cout << c << endl;

		a.clear();
		b.clear();
		c.clear();
	}

	return 0;
}