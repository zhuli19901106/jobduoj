#include <cstdio>
using namespace std;

int findRoot(int dj[], int x)
{
	int k, r = x;
	while (r != dj[r]) {
		r = dj[r];
	}
	k = x;
	while (x != r) {
		x = dj[x];
		dj[k] = r;
		k = x;
	}
	return r;
}

int main()
{
	int x, y;
	int rx, ry;
	int i, n, m;
	int dj[1005];
	int res;

	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%d", &m);
		for (i = 0; i <= n; ++i) {
			dj[i] = i;
		}
		res = n - 1;
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			rx = findRoot(dj, x);
			ry = findRoot(dj, y);
			if (rx != ry) {
				dj[rx] = ry;
				--res;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}