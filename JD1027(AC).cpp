#include <cstdio>
#include <cstring>
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
	int dj[1005];
	int n, m;
	int dg[1005];
	int i;
	int x, y, rx, ry;
	bool suc;

	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		for (i = 1; i <= n; ++i) {
			dj[i] = i;
			dg[i] = 0;
		}
		suc = true;
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			++dg[x];
			++dg[y];
			rx = findRoot(dj, x);
			ry = findRoot(dj, y);
			if (rx != ry) {
				dj[rx] = ry;
			}
		}
		for (i = 1; i <= n; ++i) {
			if (dg[i] % 2) {
				suc = false;
				break;
			}
		}
		for (i = 2; suc && i <= n; ++i) {
			if (findRoot(dj, 1) != findRoot(dj, i)) {
				suc = false;
				break;
			}
		}
		printf(suc ? "1\n" : "0\n");
	}

	return 0;
}