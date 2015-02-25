// Reference code from uuuouou.
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

const int N = 100005;
int n, m;
int c[N];
int a[N][5];
int dp[N];
 
int main()
{
    int i, j, k;
	int minVal;

    while (scanf("%d", &n) == 1) {
        minVal = INT_MAX;
        for (i = 0; i < n; ++i) {
            scanf("%d", &c[i]);
            for (j = 0; j < c[i]; ++j) {
				scanf("%d", &a[i][j]);
			}
            sort(a[i], a[i] + c[i]);
            minVal = min(minVal, a[i][0]);
        }
        dp[0] = minVal - 1;
        dp[1] = a[0][0];
        
		m = 1;
        for (i = 1; i < n; ++i) {
            for (j = c[i] - 1; j >= 0; --j) {
                k = lower_bound(dp, dp + m + 1, a[i][j]) - dp;
                if (k > m) {
					dp[++m] = a[i][j];
				} else {
					dp[k] = min(dp[k], a[i][j]);
				}
            }
        }

        printf("%d\n", m);
    }

    return 0;
}