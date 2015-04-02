#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Edge {
	int x, y, d;
} Edge;
vector<Edge> v;
const int N = 1005;
int dj[N];
int n, m;
int cc;
int cost;

bool comp(const Edge &e1, const Edge &e2)
{
	return e1.d < e2.d;
}

int findRoot(int x)
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
	int i;
	int rx, ry;

	while (scanf("%d%d", &n, &m) == 2) {
		v.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
		}
		sort(v.begin(), v.end(), comp);
		for (i = 1; i <= n; ++i) {
			dj[i] = i;
		}

		cost = 0;
		cc = n - 1;
		for (i = 0; i < m; ++i) {
			if (cc == 0) {
				break;
			}
			rx = findRoot(v[i].x);
			ry = findRoot(v[i].y);
			if (rx != ry) {
				dj[rx] = ry;
				cost += v[i].d;
				--cc;
			}
		}
		if (cc == 0) {
			printf("%d\n", cost);
		} else {
			printf("no\n");
		}

		v.clear();
	}

	return 0;
}