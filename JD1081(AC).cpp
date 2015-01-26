#include <cstdio>
#include <vector>
using namespace std;

void mult(int a[2][2], int b[2][2], int c[2][2], const int MOD)
{
	int i, j, k;

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			c[i][j] = 0;
			for (k = 0; k < 2; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}
	}
}

void mexp(int a[2][2], int b[2][2], int n, const int MOD)
{
	if (n == 1) {
		b[0][0] = a[0][0];
		b[0][1] = a[0][1];
		b[1][0] = a[1][0];
		b[1][1] = a[1][1];
		return;
	}
	if (n <= 0) {
		a[0][0] = 1 % MOD;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = 1 % MOD;
		return;
	}
	int c[2][2];
	mexp(a, c, n / 2, MOD);

	if (n % 2) {
		int p[2][2];

		mult(c, c, p, MOD);
		mult(p, a, b, MOD);
	} else {
		mult(c, c, b, MOD);
	}
}

int main()
{
	int a0, a1, p, q, k;
	const int MOD = 10000;
	int a[2][2], b[2][2];

	while (scanf("%d%d%d%d%d", &a0, &a1, &p, &q, &k) == 5) {
		if (k == 0) {
			printf("%d\n", a0 % MOD);
			continue;
		}
		if (k == 1) {
			printf("%d\n", a1 % MOD);
			continue;
		}
		if (p == 0 && q	== 0) {
			printf("%d\n", 0);
			continue;
		}

		a[0][0] = 0;
		a[0][1] = 1 % MOD;
		a[1][0] = q % MOD;
		a[1][1] = p % MOD;
		mexp(a, b, k - 1, MOD);

		printf("%d\n", (b[1][0] * a0 + b[1][1] * a1) % MOD);
	}

	return 0;
}