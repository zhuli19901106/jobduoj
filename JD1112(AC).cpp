#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	const int N = 100;
	int a[N];
	int dp[N];
	int n, i, j;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		dp[0] = 1;
		for (i = 1; i < n; ++i) {
			dp[i] = 1;
			for (j = 0; j < i; ++j) {
				if (a[j] >= a[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		j = dp[0];
		for (i = 1; i < n; ++i) {
			j = max(j, dp[i]);
		}
		printf("%d\n", j);
	}

	return 0;
}