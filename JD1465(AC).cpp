#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	vector<int> v;
	int n;
	int i, j;
	int res;

	while (scanf("%d", &n) == 1 && n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		res = 0;
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (v[i] >= v[j]) {
					continue;
				}
				if (gcd(v[i], v[j]) == 1) {
					++res;
				}
			}
		}
		printf("%d\n", res);
		v.clear();
	}

	return 0;
}