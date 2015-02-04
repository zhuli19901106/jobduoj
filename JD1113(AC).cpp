#include <algorithm>
#include <cstdio>
using namespace std;

int calc(int n, int m)
{
	int x = n;

	while ((x & x - 1) != 0) {
		x = (x & x - 1);
	}
	x = (x << 1) - 1;
	int ll, rr;
	
	ll = m;
	while (ll * 2 <= x) {
		ll = ll * 2;
	}
	rr = m;
	while (rr * 2 + 1 <= x) {
		rr = rr * 2 + 1;
	}

	int sum = 0;
	int b2;

	b2 = 1;
	x = m;
	while (x < ll) {
		sum += b2;
		b2 *= 2;
		x *= 2;
	}
	if (n >= ll) {
		sum += (min(rr, n) - ll + 1);
	}

	return sum;
}

int main()
{
	int n, m;

	while (scanf("%d%d", &m, &n) == 2 && (n || m)) {
		printf("%d\n", calc(n, m));
	}

	return 0;
}