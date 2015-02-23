#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void print(long long int a, int m)
{
	if (a == 0) {
		cout << "0" << endl;
		return;
	}

	string s = "";

	while (a > 0) {
		s.push_back(a % m + '0');
		a /= m;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	long long int a, b;
	int m;

	while (cin >> m && m > 0) {
		cin >> a >> b;
		a += b;
		print(a, m);
	}

	return 0;
}