#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st {
	int x, y, d;
} st;

bool comp(const st &s1, const st &s2)
{
	return s1.d < s2.d;
}

int findRoot(vector<int> &dj, int x)
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
	int n, n2;
	int i;
	vector<int> dj;
	int cc;
	int rx, ry;
	long long int cost;

	while (scanf("%d", &n) == 1 && n) {
		if (n < 0) {
			while (true);
			continue;
		}
		n2 = n * (n - 1) / 2;
		v.resize(n2);
		for (i = 0; i < n2; ++i) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
		}

		dj.resize(n + 1);
		for (i = 0; i <= n; ++i) {
			dj[i] = i;
		}
		sort(v.begin(), v.end(), comp);
		cc = n - 1;
		cost = 0;
		for (i = 0; i < n2; ++i) {
			if (cc <= 0) {
				break;
			}
			rx = findRoot(dj, v[i].x);
			ry = findRoot(dj, v[i].y);
			if (rx != ry) {
				--cc;
				dj[rx] = ry;
				cost += v[i].d;
			}
		}
		printf("%lld\n", cost);
		v.clear();
		dj.clear();
	}

	return 0;
}