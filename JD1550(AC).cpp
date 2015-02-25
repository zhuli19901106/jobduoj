#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<long long int> v;
	vector<long long int> dp;
	int n;
	int i;
	long long int sum;

	while (scanf("%d", &n) == 1) {
		if (n == 0) {
			printf("0\n");
			continue;
		}

		v.resize(n);
		dp.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &v[i]);
			dp[i] = 1;
		}
		for (i = 1; i <= n - 1; ++i) {
			if (v[i] > v[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
		}
		for (i = n - 2; i >= 0; --i) {
			if (v[i] > v[i + 1]) {
				dp[i] = max(dp[i], dp[i + 1] + 1);
			}
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum += dp[i];
		}

		printf("%lld\n", sum);
		v.clear();
		dp.clear();
	}

	return 0;
}