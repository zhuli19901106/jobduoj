#include <iostream>
using namespace std;

int main()
{
	int a;
	int tmp, sum;

	while (cin >> a) {
		sum = 0;
		for (int i = 0; i < 5; ++i) {
			cin >> tmp;
			sum += (tmp < a ? tmp : 0);
		}
		cout << sum << endl;
	}

	return 0;
}