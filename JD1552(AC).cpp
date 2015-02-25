#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000;
const int MOD = 1000000007;
long long int dp[N + 1][4];

int main()
{
	int i;

	memset(dp, 0, sizeof(dp));
	dp[2][0] = 1;
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 1;
	for (i = 3; i <= N; ++i) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][1] = dp[i - 1][3];
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
	}
	dp[1][0] = 1;

	while (scanf("%d", &i) == 1) {
		if (i == 1) {
			printf("1\n");
		} else {
			printf("%lld\n", (dp[i][0] + dp[i][1] + dp[i][3]) % MOD);
		}
	}
	
	return 0;
}