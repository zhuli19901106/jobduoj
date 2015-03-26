#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Edge {
	int x, y, d;
} Edge;
vector<Edge> v;
int n, m;
int dj[10005];

bool comp(const Edge &e1, const Edge &e2)
{
	return e1.d < e2.d;
}

int findRoot(int x)
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
	int i;
	int x, y;

	while (scanf("%d%d", &n, &m) == 2) {
		for (i = 1; i <= n; ++i) {
			dj[i] = i;
		}
		v.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < m; ++i) {
			x = findRoot(v[i].x);
			y = findRoot(v[i].y);
			if (x != y) {
				dj[x] = y;
			}

			if (findRoot(1) == findRoot(n)) {
				break;
			}
		}
		if (i < m) {
			printf("%d\n", v[i].d);
		} else {
			printf("-1\n");
		}

		v.clear();
	}

	return 0;
}