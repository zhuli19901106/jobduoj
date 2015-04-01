#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Edge {
	int x, y, d;
} Edge;
vector<Edge> v;
vector<int> ei;
vector<bool> b;
vector<int> dj;
int n, m;
int minCost;
int ans;

bool comp(const Edge &e1, const Edge &e2)
{
	return e1.d < e2.d;
}

int findRoot(int x)
{
	int r, k;

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

int MST()
{
	int cc;
	int i;
	int rx, ry;
	int sum;

	for (i = 0; i < n; ++i) {
		dj[i] = i;
	}

	sum = 0;
	cc = 0;
	for (i = 0; i < m; ++i) {
		if (cc == n - 1) {
			return sum;
		}
		rx = findRoot(v[i].x);
		ry = findRoot(v[i].y);
		if (rx != ry) {
			dj[rx] = ry;
			sum += v[i].d;
			ei.push_back(i);
			b[i] = true;
			++cc;
		}
	}

	return -1;
}

int SMST()
{
	int minCost = -1;
	int cost;
	int i, j;
	int rx, ry;

	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n; ++j) {
			dj[j] = j;
		}
		cost = 0;
		for (j = 0; j < n - 1; ++j) {
			if (i == j) {
				continue;
			}
			rx = findRoot(v[ei[j]].x);
			ry = findRoot(v[ei[j]].y);
			if (rx != ry) {
				dj[rx] = ry;
				cost += v[ei[j]].d;
			}
		}

		for (j = 0; j < m; ++j) {
			if (b[j]) {
				continue;
			}
			rx = findRoot(v[j].x);
			ry = findRoot(v[j].y);
			if (rx != ry) {
				dj[rx] = ry;
				cost += v[j].d;
				break;
			}
		}
		if (j == m) {
			continue;
		}
		minCost = minCost == -1 ? cost : min(minCost, cost);
	}

	return minCost;
}

int main()
{
	int t, ti;
	int i;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &m);
		v.resize(m);
		b.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].d);
			--v[i].x;
			--v[i].y;
			b[i] = false;
		}
		sort(v.begin(), v.end(), comp);
		dj.resize(n);
		minCost = MST();
		if (minCost == -1) {
			printf("-1\n");
			goto CLEARUP;
		}
		
		minCost = SMST();
		printf("%d\n", minCost);
CLEARUP:
		v.clear();
		b.clear();
		dj.clear();
		ei.clear();
	}

	return 0;
}