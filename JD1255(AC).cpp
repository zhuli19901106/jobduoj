#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000;
double a[2][6 * N + 1];
double sum;

int main()
{
	int n;
	int i, j, k;
	int f, nf;

	while (scanf("%d", &n) == 1) {
		memset(a, 0, sizeof(a));

		for (j = 1; j <= 6; ++j) {
			a[0][j] = 1.0;
		}

		f = 1;
		nf = !f;
		for (i = 2; i <= n; ++i) {
			for (j = i * 6; j >= i; --j) {
				a[f][j] = 0;
				for (k = 1; k <= 6; ++k) {
					if (j > k) {
						a[f][j] += a[nf][j - k];
					}
				}
			}
			f = !f;
			nf = !f;
		}
		sum = pow(6, n);

		f = !f;
		for (i = n; i <= 6 * n; ++i) {
			printf("%d: %.3lf\n", i, a[f][i] / sum);
		}
		printf("\n");
	}

	return 0;
}