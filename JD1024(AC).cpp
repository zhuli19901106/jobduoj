#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 105;

typedef struct st {
	int x, y, d;
} st;

bool comp(const st &s1, const st &s2)
{
	return s1.d < s2.d;
}

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
	vector<st> v;
	int n, m;
	int i;
	int cc;
	int cost;
	int rx, ry;
	int dj[N];

	while (scanf("%d%d", &n, &m) == 2 && n) {
		v.resize(n);
		for (i = 0; i <= m; ++i) {
			dj[i] = i;
		}
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
		}
		sort(v.begin(), v.end(), comp);
		cc = m - 1;
		cost = 0;
		for (i = 0; i < n; ++i) {
			if (cc <= 0) {
				break;
			}
			rx = findRoot(dj, v[i].x);
			ry = findRoot(dj, v[i].y);
			if (rx != ry) {
				dj[rx] = ry;
				--cc;
				cost += v[i].d;
			}
		}
		if (cc <= 0) {
			printf("%d\n", cost);
		} else {
			printf("?\n");
		}
		v.clear();
	}

	return 0;
}