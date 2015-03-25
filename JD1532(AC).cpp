#include <cstdio>
#include <cstring>
using namespace std;

int lim;
int a[8][8];
int b[1005];

void dfs(int x, int y, int sum)
{
	if (x == 7 && y == 7) {
		b[sum] = 1;
		return;
	}

	if (x < 7 && sum + a[x + 1][y] <= lim) {
		dfs(x + 1, y, sum + a[x + 1][y]);
	}
	if (y < 7 && sum + a[x][y + 1] <= lim) {
		dfs(x, y + 1, sum + a[x][y + 1]);
	}
}

int main()
{
	int i, j;

	while (scanf("%d", &lim) == 1) {
		for (i = 0; i < 8; ++i) {
			for (j = 0; j < 8; ++j) {
				scanf("%d", &a[i][j]);
			}
		}

		if (a[0][0] > lim) {
			printf("-1\n");
			continue;
		}

		memset(b, 0, sizeof(b));
		dfs(0, 0, a[0][0]);
		for (i = lim; i >= 0; --i) {
			if (b[i]) {
				break;
			}
		}
		printf("%d\n", (i >= 0 ? i : -1));
	}

	return 0;
}