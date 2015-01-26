#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const LL INF = 10000000000005;
const int MAXN = 205;
LL a[MAXN];
LL sum[MAXN];
LL d[MAXN];
int n;
LL l1, l2, l3;
LL c1, c2, c3;
int ix, iy;

LL fee(LL dist)
{
	if (dist <= l1) {
		return c1;
	} else if (dist <= l2) {
		return c2;
	} else if (dist <= l3) {
		return c3;
	} else {
		return INF;
	}
}

int main()
{
	int i, j;
	LL f, dist;

	while (scanf("%lld%lld%lld%lld%lld%lld", &l1, &l2, &l3, &c1, &c2, &c3) == 6) {
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &ix, &iy);
		--ix;
		--iy;
		if (ix > iy) {
			swap(ix, iy);
		}
		scanf("%d", &n);
		if (n > MAXN) {
			while(true);
		}
		for (i = 1; i < n; ++i) {
			scanf("%lld", &sum[i]);
		}
		if (ix == iy) {
			printf("0\n");
			continue;
		}

		for (i = 1; i < n; ++i) {
			d[i] = sum[i] - sum[i - 1];
		}

		a[ix] = 0;
		for (i = ix + 1; i <= iy; ++i) {
			a[i] = INF;
		}
		for (i = ix + 1; i <= iy; ++i) {
			dist = 0;
			for (j = i - 1; j >= ix; --j) {
				dist += d[j + 1];
				f = fee(dist);
				a[i] = min(a[i], a[j] + f);
			}
		}
		printf("%lld\n", a[iy]);
	}

	return 0;
}