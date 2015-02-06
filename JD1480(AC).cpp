#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> a, dp;
	int n, i, j;
	int res;

	while (scanf("%d", &n) == 1) {
		a.resize(n);
		dp.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			dp[i] = a[i];
			for (j = 0; j < i; ++j) {
				if (a[j] < a[i]) {
					dp[i] = max(dp[i], a[i] + dp[j]);
				}
			}
		}
		res = dp[0];
		for (i = 1; i < n; ++i) {
			res = max(res, dp[i]);
		}
		printf("%d\n", res);

		a.clear();
		dp.clear();
	}

	return 0;
}