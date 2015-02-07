#include <cstdio>
using namespace std;

const int N = 11;
int a[N][N], b[N][N], c[N][N];
int n, k;

void copy(int a[N][N], int b[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			a[i][j] = b[i][j];
		}
	}
}

void multiply(int c[N][N], int a[N][N], int b[N][N], int n)
{
	int i, j, k;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void print(int a[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf((j ? " %d" : "%d"), a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t, ti;
	int i, j;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d%d", &n, &k);
			for (i = 0; i < n; ++i) {
				for (j = 0; j < n; ++j) {
					scanf("%d", &a[i][j]);
				}
			}
			copy(b, a, n);
			for (i = 1; i < k; ++i) {
				multiply(c, a, b, n);
				copy(b, c, n);
			}
			print(b, n);
		}
	}

	return 0;
}