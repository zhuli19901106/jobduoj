#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st {
	int p;
	int d;
}st;

bool comparator(const st &s1, const st &s2)
{
	return s1.p < s2.p;
}

int main()
{
	vector<st> v;
	vector<int> lp, rp;
	int n;
	int lc, rc;
	int i;
	int zp;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].p, &v[i].d);
		}
		sort(v.begin(), v.end(), comparator);
		for (zp = 0; zp < n; ++zp) {
			if (v[zp].d == 0) {
				break;
			}
		}
		lc = rc = 0;
		for (i = zp - 1; i >= 0; --i) {
			if (v[i].d == 1) {
				++lc;
				lp.push_back(i);
			}
		}
		for (i = zp + 1; i <= n - 1; ++i) {
			if (v[i].d == -1) {
				++rc;
				rp.push_back(i);
			}
		}
		if (lc < rc) {
			printf("%d\n", v[rp[lc]].p - 0);
		} else if (lc > rc) {
			printf("%d\n", 100 - v[lp[rc]].p);
		} else {
			printf("Cannot fall!\n");
		}
		v.clear();
		lp.clear();
		rp.clear();
	}

	return 0;
}