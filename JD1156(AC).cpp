#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i;
	int n, m;
	vector<int> a, b;
	int tmp;

	while (cin >> n >> m) {
		a.resize(n);
		b.resize(m, 0);
		for (i = 0; i < n; ++i) {
			cin >> tmp;
			a[i] = tmp - 1;
			++b[a[i]];
		}

		for (i = 0; i < n; ++i) {
			if (b[a[i]] > 1) {
				cout << b[a[i]] - 1 << endl;
			} else {
				cout << "BeiJu" << endl;
			}
		}
		a.clear();
		b.clear();
	}

	return 0;
}