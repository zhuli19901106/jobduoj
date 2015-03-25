#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int n, m;
int dj[N];
int b[N];

int findRoot(int x)
{
	int r, k;

	r = x;
	while (r != dj[r]) {
		r = dj[r];
	}

	k = x;
	while (x != dj[x]) {
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i;
	int x, y;
	int rx, ry;
	int ans;

	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		for (i = 1; i <= n; ++i) {
			dj[i] = i;
		}
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			rx = findRoot(x);
			ry = findRoot(y);
			if (rx != ry) {
				dj[rx] = ry;
			}
		}
		for (i = 1; i <= n; ++i) {
			findRoot(i);
		}

		ans = 0;
		memset(b, 0, sizeof(b));
		for (x = 1; x <= n; ++x) {
			rx = findRoot(x);
			if (!b[rx]) {
				++ans;
				b[rx] = 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}