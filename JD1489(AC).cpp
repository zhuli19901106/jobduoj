#include <cstdio>
using namespace std;

int main()
{
	int a[2][3];
	int b[3][2];
	int c[2][2];
	int i, j, k;

	while (scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]) == 3) {
		scanf("%d%d%d", &a[1][0], &a[1][1], &a[1][2]);
		scanf("%d%d", &b[0][0], &b[0][1]);
		scanf("%d%d", &b[1][0], &b[1][1]);
		scanf("%d%d", &b[2][0], &b[2][1]);
		for (i = 0; i < 2; ++i) {
			for (j = 0; j < 2; ++j) {
				c[i][j] = 0;
				for (k = 0; k < 3; ++k) {
					c[i][j] += a[i][k] * b[k][j];
				}
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}