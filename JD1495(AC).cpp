#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int N = 10005;
int n, m;
int ss, tt;
vector<set<int> > a;
int d[N];
int b[N];
int v[N];
set<int> can;
vector<int> path;

void bfs()
{
	queue<int> q;
	set<int>::iterator it;
	int p, p1;

	memset(d, -1, sizeof(d));
	q.push(ss);
	d[ss] = 0;
	while (!q.empty() && d[tt] == -1) {
		p = q.front();
		q.pop();
		for (it = a[p].begin(); it != a[p].end(); ++it) {
			p1 = *it;
			if (d[p1] != -1) {
				continue;
			}
			q.push(p1);
			d[p1] = d[p] + 1;
		}
	}

	while (!q.empty()) {
		q.pop();
	}
}

void intersect()
{
	set<int> res;
	set<int>::iterator it;

	int i;
	for (i = 1; i < path.size() - 1; ++i) {
		if (can.find(path[i]) != can.end()) {
			res.insert(path[i]);
		}
	}
	can = res;
	res.clear();
}

void dfs()
{
	if (path.size() == d[tt] + 1) {
		if (path.back() == tt) {
			intersect();
		}
		return;
	}

	set<int>::iterator it;
	int p1, p2;

	p1 = path.back();
	for (it = a[p1].begin(); it != a[p1].end(); ++it) {
		p2 = *it;

		if (v[p2] || !b[p2]) {
			continue;
		}

		path.push_back(p2);
		v[p2] = 1;
		dfs();
		path.pop_back();
		v[p2] = 0;
	}
}

int main()
{
	int i;
	int x, y;

	while (scanf("%d%d%d%d", &n, &m, &ss, &tt) == 4) {
		a.resize(n + 1);
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			a[x].insert(y);
			a[y].insert(x);
		}
		bfs();
		if (d[tt] == -1) {
			printf("0\n");
			a.clear();
			continue;
		}

		memset(b, 0, sizeof(b));
		for (i = 1; i <= n; ++i) {
			if (d[i] != -1) {
				b[i] = 1;
				can.insert(i);
			}
		}

		memset(v, 0, sizeof(v));
		
		path.push_back(ss);
		v[ss] = 1;
		dfs();
		path.pop_back();
		v[ss] = 0;

		printf("%d\n", (int)can.size());
		
		a.clear();
		can.clear();
		path.clear();
	}

	return 0;
}