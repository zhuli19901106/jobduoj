#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 505;
int a[N];
int b[N];
int g[N][N];
int n, m;

int main()
{
	vector<int> r;
	int x, y;
	int i, j;

	while (scanf("%d%d", &n, &m) == 2) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(g, 0, sizeof(g));
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			if (!g[x][y]) {
				g[x][y] = 1;
				++a[y];
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (b[j] || a[j]) {
					continue;
				}
				r.push_back(j);
				x = j;
				break;
			}
			if (j > n) {
				break;
			}
			b[x] = 1;
			for (j = 1; j <= n; ++j) {
				if (g[x][j]) {
					g[x][j] = 0;
					--a[j];
				}
			}
		}

		for (i = 0; i < r.size(); ++i) {
			printf((i ? " %d" : "%d"), r[i]);
		}
		printf("\n");
		r.clear();
	}

	return 0;
}