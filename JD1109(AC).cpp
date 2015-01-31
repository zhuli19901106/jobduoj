#include <cstdio>
using namespace std;

int findRoot(int dj[], int x)
{
	int k, r;

	r = x;
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
	int n, m;
	int i;
	int dj[1005];

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			dj[i] = i;
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			--x;
			--y;
			rx = findRoot(dj, x);
			ry = findRoot(dj, y);
			if (rx != ry) {
				dj[rx] = ry;
			}
		}
		rx = findRoot(dj, 0);
		for (i = 1; i < n; ++i) {
			if (findRoot(dj, i) != rx) {
				break;
			}
		}
		if (i == n) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}