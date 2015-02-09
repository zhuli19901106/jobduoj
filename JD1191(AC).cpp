#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int i, j;
	int n, m;
	const int N = 105;
	int a[N][N];
	int s;
	int mi;

	while (scanf("%d%d", &n, &m) == 2) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (i = 0; i < n; ++i) {
			s = a[i][0];
			mi = 0;
			for (j = 1; j < m; ++j) {
				s += a[i][j];
				if (a[i][j] > a[i][mi]) {
					mi = j;
				}
			}
			a[i][mi] = s;
			for (j = 0; j < m; ++j) {
				printf((j ? " %d" : "%d"), a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}