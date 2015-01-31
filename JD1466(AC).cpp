#include <cstdio>
using namespace std;

int count2(int n)
{
	int i;
	int sum;

	i = 2;
	sum = 0;
	while (i <= n) {
		sum += n / i;
		i *= 2;
	}

	return sum;
}

int main()
{
	int n, m;

	while (scanf("%d%d", &n, &m) == 2 && n && n >= m) {
		printf("%d\n", count2(n) - count2(n - m));
	}

	return 0;
}