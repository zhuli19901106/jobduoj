#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
const int T = 1005;
int b[N][T];
int w[N][T];
int n, t;
int at[N];
int aw[N];

int main()
{
	int i, j;
	int res;

	while (scanf("%d%d", &t, &n) == 2) {
		memset(b, 0, sizeof(b));
		memset(w, 0, sizeof(w));

		b[0][0] = 1;
		for (i = 1; i <= n; ++i) {
			scanf("%d%d", &at[i], &aw[i]);
		}
		for (i = 1; i <= n; ++i) {
			for (j = 0; j <= t; ++j) {
				b[i][j] = b[i - 1][j];
				w[i][j] = w[i - 1][j];
			}
			for (j = 0; j + at[i] <= t; ++j) {
				if (!b[i - 1][j]) {
					continue;
				}

				if (!b[i][j + at[i]] || w[i][j + at[i]] < w[i - 1][j] + aw[i]) {
					b[i][j + at[i]] = 1;
					w[i][j + at[i]] = w[i - 1][j] + aw[i];
				}
			}
		}
		res = INT_MIN;
		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= t; ++j) {
				if (b[i][j] && w[i][j] > res) {
					res = w[i][j];
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}