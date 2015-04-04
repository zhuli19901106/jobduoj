#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[55];
int dp[500005];
int n;
int sum;

int main()
{
	int i, j;
	bool suc;

	while (scanf("%d", &n) == 1) {
		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n);
		suc = true;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < i; ++j) {
				if (a[i] % a[j] == 0) {
					suc = false;
				}
			}
		}
		if (!suc) {
			puts("-1");
			continue;
		}

		suc = true;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i = 0; suc && i < n; ++i) {
			for (j = a[i]; suc && j <= sum; ++j) {
				dp[j] += dp[j - a[i]];
				if (dp[sum] > 1) {
					suc = false;
				}
			}
		}
		printf("%d\n", dp[sum] == 1 ? sum : -1);
	}

	return 0;
}