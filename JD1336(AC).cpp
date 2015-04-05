#include <algorithm>
#include <cstdio>
using namespace std;

long long int gcd(long long int x, long long int y)
{
	return x ? gcd(y % x, x) : y;
}

int main()
{
	long long int a, b, x, y, gd;

	while (scanf("%lld%lld%lld%lld", &a, &b, &x, &y) == 4) {
		gd = gcd(x, y);
		x /= gd;
		y /= gd;
		if (x > a || y > b) {
			printf("0 0\n");
			continue;
		}
		gd = min(a / x, b / y);
		printf("%lld %lld\n", gd * x, gd * y);
	}

	return 0;
}