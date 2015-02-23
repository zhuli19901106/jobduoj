#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st{
	int x, y;
	int d;
}st;

bool comparator(const st &s1, const st &s2)
{
	return s1.d < s2.d;
}

int findRoot(int dj[], int x)
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
	vector<st> v;
	int n;
	int n2;
	int i;
	int rx, ry;
	st tmp;
	int b;
	int dj[105];
	int cc;
	int sum;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i <= n; ++i) {
			dj[i] = i;
		}

		sum = 0;
		cc = n - 1;
		n2 = n * (n - 1) / 2;
		for (i = 0; i < n2; ++i) {
			scanf("%d%d%d%d", &tmp.x, &tmp.y, &tmp.d, &b);
			if (b) {
				rx = findRoot(dj, tmp.x);
				ry = findRoot(dj, tmp.y);
				if (rx != ry) {
					dj[rx] = ry;
					--cc;
				}
			} else {
				v.push_back(tmp);
			}
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < v.size(); ++i) {
			if (cc <= 0) {
				break;
			}
			rx = findRoot(dj, v[i].x);
			ry = findRoot(dj, v[i].y);
			if (rx != ry) {
				dj[rx] = ry;
				--cc;
				sum += v[i].d;
			}
		}
		printf("%d\n", sum);
		v.clear();
	}

	return 0;
}