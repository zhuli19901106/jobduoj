#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int idx;

typedef struct st {
	int g;
	int m;
	int p;
	double a[4];
} st;

int n, m;
vector<st> v0, v;
vector<int> id;
vector<vector<int> > r;

bool comp(const int &x, const int &y)
{
	return v[x].a[idx] > v[y].a[idx];
}

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	int i, j;
	int val;

	while (scanf("%d%d", &n, &m) == 2) {
		v0.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &v0[i].g, &v0[i].m, &v0[i].p);
			v0[i].a[0] = v0[i].g;
			v0[i].a[1] = v0[i].m;
			val = gcd(v0[i].g, v0[i].p);
			v0[i].a[2] = 1.0 * (v0[i].g / val) / (v0[i].p / val);
			val = gcd(v0[i].m, v0[i].p);
			v0[i].a[3] = 1.0 * (v0[i].m / val) / (v0[i].p / val);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d", &val);
			v.push_back(v0[val]);
			// printf("#%d %d %d %f %f %f %f#\n", v[i].g, v[i].m, v[i].p, v[i].a[0], v[i].a[1], v[i].a[2], v[i].a[3]);
		}
		id.resize(m);
		r.resize(m, vector<int>(4));
		for (idx = 0; idx < 4; ++idx) {
			for (i = 0; i < m; ++i) {
				id[i] = i;
			}
			sort(id.begin(), id.end(), comp);
			i = 0;
			while (i < m) {
				j = i;
				while (j < m && v[id[j]].a[idx] == v[id[i]].a[idx]) {
					r[id[j++]][idx] = i;
				}
				i = j;
			}
		}

		for (i = 0; i < m; ++i) {
			val = 0;
			for (j = 1; j < 4; ++j) {
				if (r[i][j] < r[i][val]) {
					val = j;
				}
			}
			printf("%d:%d\n", r[i][val] + 1, val + 1);	
		}
		printf("\n");

		v.clear();
		v0.clear();
		id.clear();
		r.clear();
	}

	return 0;
}