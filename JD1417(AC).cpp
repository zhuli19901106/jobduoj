#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int N = 105;
map<string, int> mm;
typedef struct Edge {
	int x, y;
	int w;
} Edge;
vector<Edge> v;
int n, m;
int c;
int dj[N];

int getID(const string &s)
{
	map<string, int>::iterator it = mm.find(s);

	if (it != mm.end()) {
		return it->second;
	} else {
		return (mm[s] = c++);
	}
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

bool comp(const Edge &e1, const Edge e2)
{
	return e1.w < e2.w;
}

int main()
{
	string sx, sy;
	int rx, ry;
	int i;
	int len;
	Edge e;

	while (cin >> n >> m) {
		c = 0;
		for (i = 0; i < m; ++i) {
			cin >> sx >> sy;
			e.x = getID(sx);
			e.y = getID(sy);
			cin >> e.w;
			v.push_back(e);
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < n; ++i) {
			dj[i] = i;
		}
		c = 0;
		len = 0;
		for (i = 0; c < n - 1 && i < m; ++i) {
			rx = findRoot(v[i].x);
			ry = findRoot(v[i].y);
			if (rx != ry) {
				dj[rx] = ry;
				len = v[i].w;
				++c;
			}
		}
		if (c == n - 1) {
			cout << len << endl;
		} else {
			cout << "My God" << endl;
		}
		v.clear();
		mm.clear();
	}

	return 0;
}