#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int N = 1005;
set<int> root;
int dj[N];
int n, m;

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
	int x, y;
	int rx, ry;
	int i;
	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &m);
		for (i = 0; i <= n; ++i) {
			dj[i] = i;
		}
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			rx = findRoot(x);
			ry = findRoot(y);
			if (rx != ry) {
				dj[rx] = ry;
			}
		}
		for (i = 1; i <= n; ++i) {
			root.insert(findRoot(i));
		}
		printf("%d\n", (int)root.size());
		root.clear();
	}

	return 0;
}