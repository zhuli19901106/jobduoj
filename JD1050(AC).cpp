#include <iostream>
#include <vector>
using namespace std;

int sumOfDivisiors(int n)
{
	int i = 2;
	int sum = 1;

	while (i * i <= n) {
		if (n % i == 0) {
			if (i == n / i) {
				sum += i;
			} else {
				sum += (i + n / i);
			}
		}
		++i;
	}

	return sum;
}

int main()
{
	int n;
	int i;
	vector<int> v;

	while (cin >> n) {
		for (i = 2; i <= n; ++i) {
			if (i == sumOfDivisiors(i)) {
				v.push_back(i);
			}
		}
		for (i = 0; i < (int)v.size(); ++i) {
			if (i == 0) {
				cout << v[i];
			} else {
				cout << ' ' << v[i];
			}
		}
		cout << endl;
		v.clear();
	}

	return 0;
}