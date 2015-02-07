#include <cstdio>
using namespace std;

bool isprime(int n)
{
	if (n < 2) {
		return false;
	}
	int i;

	for (i = 2; i <= n / i; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int i, n;
	int cc;
	const int N = 10000;
	bool b[N + 1];

	for (i = 0; i <= N; ++i) {
		b[i] = isprime(i);
	}

	while (scanf("%d", &n) == 1) {
		cc = 0;
		for (i = 2; i < n; ++i) {
			if (i % 10 == 1 && b[i]) {
				printf((cc++ ? " %d" : "%d"), i);
			}
		}
		if (cc == 0) {
			printf("-1");
		}
		printf("\n");
	}

	return 0;
}