#include <cstdio>
#include <vector>
#include <set>
using namespace std;

vector<set<int> > v;
int n, m, k;
vector<int> dj;

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
	int i, j;
	set<int>::iterator it;
	int x, y;
	int rx, ry;
	int p;
	int cc;

	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		v.resize(n + 1);
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			if (x > y) {
				swap(x, y);
			}
			v[x].insert(y);
		}

		dj.resize(n + 1);
		for (i = 1; i <= k; ++i) {
			scanf("%d", &p);
			cc = n - 2;
			for (j = 1; j <= n; ++j) {
				dj[j] = j;
			}
			for (j = 1; j <= n; ++j) {
				if (cc == 0) {
					break;
				}
				if (j == p) {
					continue;
				}
				x = j;
				for (it = v[j].begin(); it != v[j].end(); ++it) {
					if (cc == 0) {
						break;
					}
					y = *it;
					if (y == p) {
						continue;
					}
					rx = findRoot(x);
					ry = findRoot(y);
					if (rx != ry) {
						dj[rx] = ry;
						--cc;
					}
				}
			}
			printf("%d\n", cc);
		}

		v.clear();
		dj.clear();
	}

	return 0;
}