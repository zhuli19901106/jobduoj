#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 105;
const int INF = 1000000000;
int a[N][N];
int n, m;

void floyd()
{
	int i, j, k;

	for (k = 1; k <= n; ++k) {
		for (i = 1; i <= n; ++i) {
			if (i == k || a[i][k] == INF) {
				continue;
			}
			for (j = 1; j <= n; ++j) {
				if (k == j || a[k][j] == INF) {
					continue;
				}
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

int main()
{
	int i, j;
	int x, y, len;

	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				a[i][j] = INF;
			}
			a[i][i] = 0;
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &len);
			a[x][y] = a[y][x] = len;
		}
		floyd();
		printf("%d\n", a[1][n]);
	}

	return 0;
}