#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
const int C = 1005;
int dp[N][C];
int c, n;
int a[N], b[N];

int main()
{
	int i, j;

	while (scanf("%d%d", &c, &n) == 2) {
		for (i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 0; j <= c; ++j) {
				dp[i][j] = dp[i - 1][j];
			}
			for (j = 0; j + a[i] <= c; ++j) {
				if (dp[i - 1][j] == -1) {
					continue;
				}
				if (dp[i][j + a[i]] == -1 || dp[i][j + a[i]] < dp[i - 1][j] + b[i]) {
					dp[i][j + a[i]] = dp[i - 1][j] + b[i];
				}
			}
		}

		j = 0;
		for (i = 0; i <= c; ++i) {
			j = max(j, dp[n][i]);
		}
		printf("%d\n", j);
	}

	return 0;
}