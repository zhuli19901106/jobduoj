#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st {
	string name;
	int count;
}st;

bool comparator(const st &x, const st &y)
{
	return x.name < y.name;
}

int findRoot(int x, vector<int> &dj)
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

int main()
{
	string nx, ny;
	int ix, iy;
	int rx, ry;
	int n, k;
	int i;
	int tmp;
	map<string, int> id;
	map<int, string> di;
	map<string, int>::iterator it;
	map<int, int> gc;
	map<int, int> gw;
	map<int, int> hg;
	map<int, int>::iterator it1;
	vector<int> v;
	vector<int> dj;
	vector<st> res;
	int m;
	st st1;

	while (cin >> n >> k) {
		k *= 2;
		m = 0;
		for (i = 0; i < n; ++i) {
			cin >> nx >> ny >> tmp;
			it = id.find(nx);
			if (it == id.end()) {
				v.push_back(0);
				id[nx] = m;
				di[m] = nx;
				dj.push_back(m++);
			}
			it = id.find(ny);
			if (it == id.end()) {
				v.push_back(0);
				id[ny] = m;
				di[m] = ny;
				dj.push_back(m++);
			}
			ix = id[nx];
			iy = id[ny];
			v[ix] += tmp;
			v[iy] += tmp;
			rx = findRoot(ix, dj);
			ry = findRoot(iy, dj);
			dj[rx] = ry;
		}

		for (i = 0; i < m; ++i) {
			++gc[findRoot(i, dj)];
			gw[findRoot(i, dj)] += v[i];
		}
		for (it1 = gc.begin(); it1 != gc.end(); ++it1) {
			hg[it1->first] = it1->first;
		}
		for (i = 0; i < m; ++i) {
			rx = findRoot(i, dj);
			if (v[i] > v[hg[rx]]) {
				hg[rx] = i;
			}
		}

		for (it1 = hg.begin(); it1 != hg.end(); ++it1) {
			rx = it1->first;
			ix = it1->second;
			if (gw[rx] <= k || gc[rx] <=  2) {
				continue;
			}
			st1.count = gc[rx];
			st1.name = di[ix];
			res.push_back(st1);
		}
		sort(res.begin(), res.end(), comparator);
		cout << res.size() << endl;
		for (i = 0; i < (int)res.size(); ++i) {
			cout << res[i].name << ' ' << res[i].count << endl;
		}

		id.clear();
		di.clear();
		gc.clear();
		gw.clear();
		hg.clear();
		v.clear();
		dj.clear();
		res.clear();
	}
	
	return 0;
}
