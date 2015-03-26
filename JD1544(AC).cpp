#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
const int M = 18;
int f[N][M];
int a[N];
int n, m;

int main()
{
	int x, y;
	int i, j;

	while (scanf("%d", &n) == 1) {
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			f[i][0] = a[i];
		}
		for (i = 1; (1 << i) <= n; ++i) {
			for (j = 1; j + (1 << i) - 1 <= n; ++j) {
				f[j][i] = min(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
			}
		}
		scanf("%d", &m);
		for (i = 1; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			j = 0;
			while ((1 << j) <= y - x + 1) {
				++j;
			}
			--j;
			printf("%d\n", min(f[x][j], f[y - (1 << j) + 1][j]));
		}
	}
	
	return 0;
}