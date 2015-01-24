#include <iostream>
using namespace std;

int main()
{
	int a, b;

	while (cin >> a) {
		for (int i = 0; i < 9; ++i) {
			cin >> b;
			a = (a > b ? a : b);
		}

		cout << "max=" << a << endl;
	}

	return 0;
}