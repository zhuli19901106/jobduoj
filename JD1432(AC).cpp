#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int N = 85;
	int n;
	char a[N][N];
	char c[2];
	char s[5];
	int i, j;
	int f;
	int caseno;

	caseno = 0;
	while (scanf("%d", &n) == 1) {
		++caseno;
		if (caseno > 1) {
			puts("");
		}

		scanf("%s", s);
		c[0] = s[0];
		scanf("%s", s);
		c[1] = s[0];
		memset(a, 0, sizeof(a));

		if (n == 1) {
			printf("%c\n", c[0]);
			continue;
		}

		f = (n / 2) % 2;
		for (i = 0; i <= n / 2; ++i) {
			for (j = i; j <= n - 1 - i; ++j) {
				a[i][j] = a[n - 1 - i][j] = c[f];
			}
			for (j = i; j < n - 1 - i; ++j) {
				a[j][i] = a[j][n - 1 - i] = c[f];
			}
			f = !f;
		}

		a[0][0] = a[n - 1][0] = ' ';
		a[0][n - 1] = a[n - 1][n - 1] = ' ';
		for (i = 0; i < n; ++i) {
			puts(a[i]);
		}
	}

	return 0;
}