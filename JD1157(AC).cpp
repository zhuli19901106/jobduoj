#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int i, n;
	vector<int> v;

	while (scanf("%d", &n) == 1 && n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		if (n % 2) {
			printf("%d\n", v[n / 2]);
		} else {
			printf("%d\n", (v[n / 2] + v[n / 2 - 1]) / 2);
		}
		v.clear();
	}

	return 0;
}