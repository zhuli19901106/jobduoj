#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;

	while (cin >> n) {
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}
		while (n > 0) {
			s.push_back(n % 8 + '0');
			n /= 8;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
		s.clear();
	}

	return 0;
}