#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 105;
int a[N][N];
int b[N][N];
int n;
int sx, sy;
int ex, ey;
int d[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

void BFS()
{
	queue<int> q;
	int x, y;
	int x1, y1;
	int p;
	int i;

	q.push(0);
	b[0][0] = 1;
	while (!q.empty() && !b[ex][ey]) {
		p = q.front();
		x = p / n;
		y = p % n;
		q.pop();
		for (i = 0; i < 4; ++i) {
			x1 = x + d[i][0];
			y1 = y + d[i][1];
			if (x1 < 0 || x1 > n - 1 || y1 < 0 || y1 > n - 1) {
				continue;
			}
			if (a[x1][y1] || b[x1][y1]) {
				continue;
			}
			q.push(x1 * n + y1);
			b[x1][y1] = b[x][y] + 1;
		}
	}

	while (!q.empty()) {
		q.pop();
	}
}

int main()
{
	int i, j;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		sx = sy = 0;
		ex = ey = n - 1;
		memset(b, 0, sizeof(b));
		if (a[sx][sy] || a[ex][ey]) {
			printf("-1\n");
			continue;
		}
		BFS();
		if (b[ex][ey]) {
			printf("%d\n", b[ex][ey] - b[sx][sy]);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}