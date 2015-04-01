#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;
const int INF = 1000000005;
int a[N][N];
/*
int b[N];
int d[N];
*/
int n, m;
int ss, tt;

int main()
{
	int x, y, val;
	int i, j;
	int k;
	// int k1;

	while (scanf("%d%d", &n, &m) == 2) {
		scanf("%d%d", &ss, &tt);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				a[i][j] = INF;
			}
			/*
			d[i] = INF;
			b[i] = 0;
			*/
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &val);
			a[x][y] = a[y][x] = min(a[x][y], val);
		}

		/*
		b[ss] = 1;
		d[ss] = 0;
		k = ss;
		for (i = 1; i <= n - 1; ++i) {
			k1 = -1;
			for (j = 1; j <= n; ++j) {
				if (a[k][j] == INF || b[j]) {
					continue;
				}
				d[j] = min(d[j], d[k] + a[k][j]);
				if (k1 == -1 || d[j] < d[k1]) {
					k1 = j;
				}
			}
			if (k1 == -1) {
				break;
			}
			k = k1;
			b[k] = 1;
		}
		*/

		for (k = 1; k <= n; ++k) {
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= n; ++j) {
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}

		printf("%d\n", a[ss][tt]);
	}

	return 0;
}