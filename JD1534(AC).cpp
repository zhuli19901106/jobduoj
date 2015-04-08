#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const int N = 100005;
LL a[N], b[N];
int m, n;
LL k;

LL count(int mm)
{
	LL cc = 0;
	int i, j;

	j = n - 1;
	for (i = 0; i < m; ++i) {
		while (j >= 0 && a[i] + b[j] > mm) {
			--j;
		}
		cc += (j + 1);
	}

	return cc;
}

int solve()
{
	LL ll = a[0] + b[0];
	LL rr = a[m - 1] +b[n - 1];
	LL mm;

	while (ll <= rr) {
		mm = (ll + rr) / 2;
		if (k <= count(mm)) {
			rr = mm - 1;
		} else {
			ll = mm + 1;
		}
	}

	return ll;
}

int main()
{
	int i;

	while (scanf("%d%d%lld", &m, &n, &k) == 3) {
		for (i = 0; i < m; ++i) {
			scanf("%lld", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			scanf("%lld", &b[i]);
		}
		sort(a, a + m);
		sort(b, b + n);

		printf("%lld\n", solve());
	}

	return 0;
}