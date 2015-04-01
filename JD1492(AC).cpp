#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 105;
int a[M][M];
int s[M][M];
int m, n;
int ans;

int main()
{
	int i, j;

	while (scanf("%d%d", &m, &n) == 2) {
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		for (i = 1; i <= m; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 1; i <= m; ++i) {
			for (j = 1; j <= m; ++j) {
				s[i][j] = s[i][j - 1] + s[i - 1][j] + a[i][j] - s[i - 1][j - 1];
			}
		}
		ans = INT_MAX;
		for (i = n; i <= m; ++i) {
			for (j = n; j <= m; ++j) {
				ans = min(ans, s[i][j] + s[i - n][j - n] - s[i][j - n] - s[i - n][j]);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}