#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 105;
const int INF = 1000000000;
int n, m;
int dj[N];
int a[N][N];

void floyd()
{
	int i, j, k;

	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			if (k == i || a[i][k] == INF) {
				continue;
			}
			for (j = 0; j < n; ++j) {
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
	int x, y;

	while (scanf("%d%d", &n, &m) == 2 && n) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				a[i][j] = INF;
			}
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		floyd();
		for (i = 0; i < n; ++i) {
			if (a[i][i] != INF) {
				break;
			}
		}
		printf(i == n ? "YES\n" : "NO\n");
	}

	return 0;
}