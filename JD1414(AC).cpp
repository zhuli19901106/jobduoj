#include <cstdio>
using namespace std;

const int N = 50;
const int INF = 1000000000;
int a[N][N];
int d[N];
int cost;
int maxdist;
int m;

void dfs(int idx, int dist)
{
	d[idx] = dist;
	if (dist > maxdist) {
		maxdist = dist;
	}

	int i;

	for (i = 0; i < N; ++i) {
		if (a[idx][i] == INF || d[i] != INF) {
			continue;
		}
		dfs(i, dist + a[idx][i]);
	}
}

int main()
{
	int i, j;
	int x, y, val;

	while (scanf("%d", &m) == 1) {
		for (i = 0; i < N; ++i) {
			d[i] = INF;
			for (j = 0; j < N; ++j) {
				a[i][j] = INF;
			}
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &x, &y, &val);
			a[x][y] = a[y][x] = val;
		}
		cost = 0;
		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				if (a[i][j] != INF) {
					cost += a[i][j];
				}
			}
		}
		maxdist = 0;
		dfs(0, 0);
		cost = cost * 2 - maxdist;
		printf("%d\n", cost);
	}

	return 0;
}