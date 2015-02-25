#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
int b[N][N];
char s[N];

int main()
{
	int i, j, k;
	int ans;
	int n;
	bool suc;

	while (scanf("%s", s) == 1) {
		n = strlen(s);
		ans = 0;
		memset(b, 0, sizeof(b));
		for (i = 0; i < n; ++i) {
			for (j = i; j - i + 1 <= n / 2 && j < n; ++j) {
				suc = false;
				if (b[i][j]) {
					continue;
				} else {
					b[i][j] = 1;
				}
				for (k = j + 1; k + j - i < n; ++k) {
					if (b[k][k + j - i]) {
						continue;
					}
					if (strncmp(s + i, s + k, j - i + 1) == 0) {
						suc = true;
						b[k][k + j - i] = 1;
					}
				}
				if (!suc) {
					break;
				} else {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}