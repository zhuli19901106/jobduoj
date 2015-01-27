#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a, n;
	int i;
	const int MAXN = 105;
	int b[MAXN];

	while (scanf("%d%d", &a, &n) == 2) {
		memset(b, 0, MAXN * sizeof(int));
		for (i = 0; i < n; ++i) {
			b[i] = a * (n - i);
		}
		for (i = 0; i < MAXN - 1; ++i) {
			b[i + 1] += b[i] / 10;
			b[i] %= 10;
		}
		b[i] %= 10;

		i = MAXN - 1;
		while (i > 0 && b[i] == 0) {
			--i;
		}
		while (i >= 0) {
			putchar(b[i] + '0');
			--i;
		}
		putchar('\n');
	}
	
	return 0;
}