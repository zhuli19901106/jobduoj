#include <cstdio>
using namespace std;

const int N = 15;
bool equal(int a[N][N], int b[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void rotate(int a[N][N], int n)
{
	int i, j;
	int val;

	for (i = 0; i < n / 2; ++i) {
		for (j = 0; j < (n + 1) / 2; ++j) {
			val = a[i][j];
			a[i][j] = a[j][n - 1 - i];
			a[j][n - 1 - i] = a[n - 1 - i][n - 1 - j];
			a[n - 1 - i][n - 1 - j] = a[n - 1 - j][i];
			a[n - 1 - j][i] = val;
		}
	}
}

void print(int a[N][N], int n)
{
	int i, j;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("#\n");
	}
}

int main()
{
	int a[N][N], b[N][N];
	int i, j;
	int n;
	int angle;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &b[i][j]);
			}
		}
		angle = 0;
		for (i = 0; i < 4; ++i) {
			if (equal(a, b, n)) {
				break;
			}
			rotate(b, n);
			angle += 90;
		}
		if (i == 4) {
			printf("-1\n");
		} else {
			printf("%d\n", angle);
		}
	}

	return 0;
}