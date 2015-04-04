#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 105;
int a[N][N];
int n;
int sx, sy, ex, ey;
int d[8][2] = {
	{-1, -2}, 
	{-1, +2}, 
	{+1, -2}, 
	{+1, +2}, 
	{-2, -1}, 
	{-2, +1}, 
	{+2, -1}, 
	{+2, +1}
};

int main()
{
	int i;
	queue<int> q;
	int x, y;
	int x1, y1;
	int p;

	while (scanf("%d", &n) == 1) {
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		memset(a, 0, sizeof(a));
		q.push(sx * N  + sy);
		a[sx][sy] = 1;
		while (!q.empty() && !a[ex][ey]) {
			p = q.front();
			q.pop();
			x = p / N;
			y = p % N;
			for (i = 0; i < 8; ++i) {
				x1 = x + d[i][0];
				y1 = y + d[i][1];
				if (x1 < 1 || x1 > n || y1 < 1 || y1 > n) {
					continue;
				}
				if (a[x1][y1]) {
					continue;
				}
				q.push(x1 * N + y1);
				a[x1][y1] = a[x][y] + 1;
			}
		}
		printf("%d\n", a[ex][ey] - a[sx][sy]);
		
		while (!q.empty()) {
			q.pop();
		}
	}

	return 0;
}