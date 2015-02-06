#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int add(string &a, string &b)
{
	if (a.length() > b.length()) {
		return add(b, a);
	}

	int len = b.length();
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int i;
	for (i = a.length(); i < len; ++i) {
		a.push_back('0');
	}

	int c = 0;
	int res = 0;
	for (i = 0; i < len; ++i) {
		if (c + (a[i] - '0') + (b[i] - '0') > 9) {
			++res;
			c = 1;
		} else {
			c = 0;
		}
	}

	return res;
}

int main()
{
	string sa, sb;
	int carry;

	while (cin >> sa >> sb) {
		if (sa == "0" && sb == "0") {
			break;
		}
		carry = add(sa, sb);
		if (carry) {
			cout << carry;
		} else {
			cout << "NO";
		}
		if (carry > 1) {
			cout << " carry operations." << endl;
		} else {
			cout << " carry operation." << endl;
		}
	}

	return 0;
}