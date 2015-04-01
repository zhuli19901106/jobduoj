#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

char a[7][800][800];

int main()
{
	int i, j, k, p, q;

	memset(a, 0, sizeof(a));

	a[0][0][0] = 'X';
	int base = 1;
	for (i = 1; i < 7; ++i) {
		for (p = 0; p < 3; ++p) {
			for (q = 0; q < 3; ++q) {
				if ((p + q) % 2) {
					for (j = 0; j < base; ++j) {
						for (k = 0; k < base; ++k) {
							a[i][p * base + j][q * base + k] = ' ';
						}
					}
				} else {
					for (j = 0; j < base; ++j) {
						for (k = 0; k < base; ++k) {
							a[i][p * base + j][q * base + k] = a[i - 1][j][k];
						}
					}
				}
			}
		}
		base *= 3;
	}

	int n;
	while (scanf("%d", &n) == 1 && n > 0) {
		base = 1;
		--n;
		for (i = 0; i < n; ++i) {
			base *= 3;
		}
		for (i = 0; i < base; ++i) {
			puts(a[n][i]);
		}
		puts("#");
	}

	return 0;
}