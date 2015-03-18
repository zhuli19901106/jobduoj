#include <cstdio>
using namespace std;

typedef long long int LL;

LL gcd(LL x, LL y)
{
	return x ? gcd(y % x, x) : y;
}

LL lcm(LL x, LL y)
{
	return x / gcd(x, y) * y;
}

int main()
{
	long long int sum, val;
	int t, ti;
	int i, n;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			sum = 1;
			scanf("%d", &n);
			for (i = 0; i < n; ++i) {
				scanf("%lld", &val);
				sum = lcm(sum, val);
			}
			printf("%lld\n", sum);
		}
	}

	return 0;
}