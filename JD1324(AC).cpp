#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct Item {
	string s;
	int a[4];
	int r[4];
	int mi;
} Item;
vector<Item> v;
vector<int> r;
int idx;
int n, m;
map<string, int> mm;

bool comp(const int &x, const int &y)
{
	return v[x].a[idx] > v[y].a[idx];
}

int main()
{
	int i, j;
	string str;
	char ss[] = "ACME";

	while (cin >> n >> m) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].s;
			cin >> v[i].a[1] >> v[i].a[2] >> v[i].a[3];
			v[i].a[0] = v[i].a[1] + v[i].a[2] + v[i].a[3];
			mm[v[i].s] = i;
		}

		r.resize(n);
		for (idx = 0; idx < 4; ++idx) {
			for (i = 0; i < n; ++i) {
				r[i] = i;
			}
			sort(r.begin(), r.end(), comp);
			i = 0;
			while (i < n) {
				j = i;
				while (j < n && v[r[i]].a[idx] == v[r[j]].a[idx]) {
					v[r[j]].r[idx] = i;
					++j;
				}
				i = j;
			}
		}

		for (i = 0; i < n; ++i) {
			v[i].mi = 0;
			for (j = 1; j < 4; ++j) {
				if (v[i].r[j] < v[i].r[v[i].mi]) {
					v[i].mi = j;
				}
			}
		}

		int rr;
		for (i = 0; i < m; ++i) {
			cin >> str;
			if (mm.find(str) != mm.end()) {
				rr = v[mm[str]].mi;
				cout << v[mm[str]].r[rr] + 1 << ' ' << ss[rr] << endl;
			} else {
				cout << "N/A" << endl;
			}
		}

		v.clear();
		r.clear();
		mm.clear();
	}

	return 0;
}