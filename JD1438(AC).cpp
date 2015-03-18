#include <cstdio>
using namespace std;

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

int lcm(int x, int y)
{
	return x / gcd(x, y) * y;
}

int main()
{
	int x, y;

	while (scanf("%d%d", &x, &y) == 2) {
		printf("%d\n", lcm(x, y));
	}

	return 0;
}