#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 2005;
LL a[N];
LL dp[N][N / 2];
int n, k;

int main()
{
	int i, j;

	while (scanf("%d%d", &n, &k) == 2) {
		a[0] = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		sort(a + 1, a + n + 1);

		memset(dp, 0, sizeof(dp));
		dp[2][1] = (a[2] - a[1]) * (a[2] - a[1]);
		for (i = 3; i <= n; ++i) {
			dp[i][1] = min(dp[i - 1][1], (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
		}
		for (j = 2; j <= k; ++j) {
			dp[j * 2][j] = dp[j * 2 - 2][j - 1] + (a[j * 2] - a[j * 2 - 1]) * (a[j * 2] - a[j * 2 - 1]);
			for (i = j * 2 + 1; i <= n; ++i) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
			}
		}
		printf("%lld\n", dp[n][k]);
	}

	return 0;
}