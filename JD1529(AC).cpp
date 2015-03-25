#include <algorithm>
#include <cstdio>
using namespace std;

int a[8][8];
int dp[8][8];

int main()
{
	int i, j;

	while (scanf("%d", &a[0][0]) == 1) {
		for (i = 1; i < 64; ++i) {
			scanf("%d", &a[i / 8][i % 8]);
		}
		dp[0][0] = a[0][0];
		for (i = 1; i < 8; ++i) {
			dp[0][i] = dp[0][i - 1] + a[0][i];
		}
		for (i = 1; i < 8; ++i) {
			dp[i][0] = dp[i - 1][0] + a[i][0];
		}
		for (i = 1; i < 8; ++i) {
			for (j = 1; j < 8; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
		}
		printf("%d\n", dp[7][7]);
	}

	return 0;
}