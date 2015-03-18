#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

map<int, int> dj;
map<int, int> cnt;
int res;
int n;

int findRoot(int x)
{
	if (dj[x] == 0) {
		dj[x] = x;
		return x;
	}

	int k, r;
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
	map<int, int>::iterator it;

	while (scanf("%d", &n) == 1) {
		if (n == 0) {
			printf("1\n");
			continue;
		}
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			rx = findRoot(x);
			ry = findRoot(y);
			if (rx != ry) {
				dj[rx] = ry;
			}
		}
		for (it = dj.begin(); it != dj.end(); ++it) {
			findRoot(it->first);
		}
		for (it = dj.begin(); it != dj.end(); ++it) {
			++cnt[it->second];
		}
		res = 0;
		for (it = cnt.begin(); it != cnt.end(); ++it) {
			res = max(res, it->second);
		}
		printf("%d\n", res);
		dj.clear();
		cnt.clear();
	}

	return 0;
}