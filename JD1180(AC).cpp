#include <cstdio>
using namespace std;

int main()
{
	int a[105][105];
	int i, j, n;
	bool suc;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		suc = true;
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (a[i][j] != a[j][i]) {
					suc = false;
				}
			}
		}
		printf(suc ? "Yes!\n" : "No!\n");
	}

	return 0;
}