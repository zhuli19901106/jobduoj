#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	const int N = 105;
	int i, j;
	int dp1[N], dp2[N];
	int a[N];
	int n;
	int sum;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			dp1[i] = 1;
			for (j = 0; j < i; ++j) {
				if (a[j] < a[i]) {
					dp1[i] = max(dp1[i], dp1[j] + 1);
				}
			}
		}
		for (i = n - 1; i >= 0; --i) {
			dp2[i] = 1;
			for (j = n - 1; j > i; --j) {
				if (a[j] < a[i]) {
					dp2[i] = max(dp2[i], dp2[j] + 1);
				}
			}
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum = max(sum, dp1[i] + dp2[i] - 1);
		}
		printf("%d\n", n - sum);
	}

	return 0;
}