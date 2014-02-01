// 688882	zhuli19901106	1373	Accepted	点击此处查看所有case的执行结果	1020KB	1161B	0MS
// 201402020057
#include <cstdio>
using namespace std;

long long int sum[11];

long long int solve(long long int x)
{
	long long int b10;
	int idx;

	if (x == 0) {
		return 0;
	} else if (x < 10) {
		return 1;
	}

	b10 = 1;
	idx = 0;
	while (b10 * 10 <= x) {
		b10 *= 10;
		++idx;
	}
	/*
	printf("b10 = %lld\n", b10);
	printf("idx = %d\n", idx);
	*/
	if (x / b10 > 1) {
		return (x / b10) * sum[idx] + b10 + solve(x % b10);
	} else {
		return sum[idx] + (x % b10 + 1) + solve(x % b10);
	}
}

int main()
{
	int i;
	int x, y;
	long long int b10;

	sum[0] = 0;
	sum[1] = 1;
	b10 = 1;
	for (i = 2; i <= 10; ++i) {
		b10 *= 10;
		sum[i] = 10 * sum[i - 1] + b10;
	}

	/*
	for (i = 0; i <= 10; ++i) {
		printf("sum[%d] = %lld\n", i, sum[i]);
	}
	*/

	while (scanf("%d%d", &x, &y) == 2) {
		// the problem should've told me what to do if x > y, it's unfair.
		if (x > y) {
			i = x;
			x = y;
			y = i;
		}

		if (x == 0) {
			printf("%lld\n", solve(y));
		} else {
			printf("%lld\n", solve(y) - solve(x - 1));
		}
	}

	return 0;
}