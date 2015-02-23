#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct st {
	int d, p;

	st(int _d = 0, int _p = 0): d(_d), p(_p) {};

	bool operator < (const st &other)
	{
		if (d != other.d) {
			return d < other.d;
		} else {
			return p < other.p;
		}
	}

	st operator + (const st &other)
	{
		return st(d + other.d, p + other.p);
	}
} st;

const int INF = 1000000000;
const int N = 1005;
st a[N][N];
int n, m;
int ss, tt;
bool b[N];
st d[N];

int main()
{
	int i, j;
	int x, y;
	st s1;

	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				a[i][j] = st(INF, INF);
			}
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d%d%d", &x, &y, &s1.d, &s1.p);
			if (s1 < a[x][y]) {
				a[x][y] = a[y][x] = s1;
			}
		}
		scanf("%d%d", &ss, &tt);
		for (i = 1; i <= n; ++i) {
			b[i] = false;
			d[i] = st(INF, INF);
		}

		b[ss] = true;
		d[ss] = st(0, 0);
		x = ss;
		for (i = 1; i < n; ++i) {
			y = -1;
			for (j = 1; j <= n; ++j) {
				if (b[j] || a[x][j].d == INF) {
					continue;
				}
				if (d[x] + a[x][j] < d[j]) {
					d[j] = d[x] + a[x][j];
				}
				if (y == -1 || d[j] < d[y]) {
					y = j;
				}
			}
			if (y == -1) {
				break;
			}
			b[y] = true;
			x = y;
		}
		printf("%d %d\n", d[tt].d, d[tt].p);
	}
	
	return 0;
}