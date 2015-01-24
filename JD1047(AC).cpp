#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;

	while (cin >> n) {
		if (n < 2) {
			cout << "no" << endl;
			continue;
		}

		i = 2;
		while (i <= n / i) {
			if (n % i == 0) {
				cout << "no" << endl;
				n = 0;
				break;
			} else {
				++i;
			}
		}
		if (n) {
			cout << "yes" << endl;
		}
	}

	return 0;
}