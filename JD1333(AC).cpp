#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
int n, m;
int a[N][N];

int main()
{
	int i, j, k;
	int res;
	int xx1, xx2, yy1, yy2;

	while (scanf("%d%d", &n, &m) == 2) {
		memset(a, 0, sizeof(a));
		res = n * n;
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
			xx1 = max(xx1, 0);
			yy1 = max(yy1, 0);
			xx2 = min(xx2, n);
			yy2 = min(yy2, n);
			if (xx1 >= xx2 || yy1 >= yy2) {
				continue;
			}
			for (j = xx1; j < xx2; ++j) {
				for (k = yy1; k < yy2; ++k) {
					if (!a[j][k]) {
						a[j][k] = 1;
						--res;
					}
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}