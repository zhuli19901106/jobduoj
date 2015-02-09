#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int i, j;
	const int N = 105;
	int a[N][N];

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[j][i]);
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