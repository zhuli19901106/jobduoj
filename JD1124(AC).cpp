#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	int sum;
	string s;

	while (cin >> s) {
		if (s == "0") {
			break;
		}
		n = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			n += (s[i] - '0');
		}
		while (n >= 10) {
			sum = 0;
			while (n > 0) {
				sum += n % 10;
				n /= 10;
			}
			n = sum;
		}
		cout << n << endl;
	}

	return 0;
}