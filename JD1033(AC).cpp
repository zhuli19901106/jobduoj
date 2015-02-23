#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	int a[505];
	int b[1001];
	int i, j;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}

		memset(b, 0, sizeof(b));
		b[1] = 1;
		for (i = 0; i < n; ++i) {
			j = a[i];
			while (j != 1) {
				if (j % 2) {
					j = (3 * j + 1) / 2;
				} else {
					j /= 2;
				}
				if (j > 1 && j <= 1000) {
					b[j] = 1;
				}
			}
		}
		int cc = 0;
		for (i = n - 1; i >= 0; --i) {
			if (b[a[i]]) {
				continue;
			}
			printf((cc++ ? " %d" : "%d"), a[i]);
		}
		printf("\n");
	}

	return 0;
}