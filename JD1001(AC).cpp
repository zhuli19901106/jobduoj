#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 15;
	int a[MAXN][MAXN];
	int n, m;
	int i, j;
	int r[MAXN], c[MAXN];
	int tmp;

	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		memset(a, 0, sizeof(a));
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &tmp);
				a[i][j] += tmp;
			}
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &tmp);
				a[i][j] += tmp;
				if (a[i][j] != 0) {
					r[i] = c[j] = 1;
				}
			}
		}
		tmp = 0;
		for (i = 0; i < n; ++i) {
			if (!r[i]) {
				++tmp;
			}
		}
		for (j = 0; j < m; ++j) {
			if (!c[j]) {
				++tmp;
			}
		}
		printf("%d\n", tmp);
	}

	return 0;
}