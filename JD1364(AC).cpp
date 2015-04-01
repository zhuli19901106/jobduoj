#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int M = 1005;
const int N = 105;

int a[M];
int c[N];
int p[N];
int n;
int s;
int ans;

int main()
{
	int i, j;

	while (scanf("%d%d", &s, &n) == 2) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &c[i], &p[i]);
		}
		memset(a, -1, sizeof(a));
		a[0] = 0;
		for (i = 0; i < n; ++i) {
			for (j = s; j >= c[i]; --j) {
				if (a[j - c[i]] >= 0) {
					a[j] = max(a[j], a[j - c[i]] + p[i]);
				}
			}
		}

		ans = 0;
		for (i = s; i > 0; --i) {
			if (a[i] > 0) {
				ans = max(ans, a[i]);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}