#include <cstdio>
#include <cstring>
using namespace std;

int a[12][12];
int n;

int main()
{
	int i, j;
	int sum1, sum2;

	while (scanf("%d", &n) == 1 && n) {
		memset(a, 0, sizeof(a));
		sum1 = sum2 = 0;
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				if ((i + j) & 1) {
					sum1 += a[i][j];
				} else {
					sum2 += a[i][j];
				}
			}
		}
		if (sum1 != sum2) {
			printf("No\n");
			continue;
		}

		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (a[i][j] > a[i + 1][j] + a[i - 1][j] + a[i][j + 1] + a[i][j - 1]) {
					break;
				}
			}
			if (j <= n) {
				break;
			}
		}

		printf(i > n ? "Yes\n" : "No\n");
	}

	return 0;
}