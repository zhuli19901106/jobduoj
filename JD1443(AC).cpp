#include <cstdio>
using namespace std;

const int N = 12;
const int MOD = 9973;

int a[N][N];
int b[N][N];
int n, k;
int tr;

void copy(int a[N][N], int b[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			b[i][j] = a[i][j];
		}
	}
}

void mult(int a[N][N], int b[N][N], int c[N][N], int n)
{
	int i, j, k;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (k = 0; k < n; ++k) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
}

void mypow(int a[N][N], int b[N][N], int k, int n)
{
	int i, j;

	if (k == 1) {
		copy(a, b, n);
		return;
	}

	int c[N][N];
	
	mypow(a, c, k / 2, n);
	if (k % 2) {
		int d[N][N];
		mult(c, c, d, n);
		mult(d, a, b, n);
	} else {
		mult(c, c, b, n);
	}
}

int main()
{
	int i, j;
	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
				a[i][j] %= MOD;
			}
		}
		mypow(a, b, k, n);
		tr = 0;
		for (i = 0; i < n; ++i) {
			tr = (tr + b[i][i]) % MOD;
		}
		printf("%d\n", tr);
	}

	return 0;
}