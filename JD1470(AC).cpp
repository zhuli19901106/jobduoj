#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int i, j, k;
	int a[20][20];
	int n;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			k = i;
			for (j = i + 1; j < n; ++j) {
				if (a[j][i] > a[k][i]) {
					k = j;
				}
			}
			for (j = 0; j < n; ++j) {
				swap(a[k][j], a[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				printf((j ? " %d" : "%d"), a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}