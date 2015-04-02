#include <cstdio>
#include <cstring>
using namespace std;

int a[18];
int n;
int b[5];
int c[16];

int main()
{
	int i;
	int x, y;
	int x1, y1;

	while (scanf("%d", &n) == 1) {
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] < 3) {
				++c[a[i] + 13];
			} else {
				++c[a[i]];
			}
		}
		for (i = 0; i < 5; ++i) {
			scanf("%d", &b[i]);
		}
		x = b[0] < 3 ? b[0] + 13 : b[0];
		y = b[3] < 3 ? b[3] + 13 : b[3];
		x1 = y1 = -1;
		for (i = x + 1; i <= 15; ++i) {
			if (c[i] >= 3) {
				x1 = i;
				break;
			}
		}
		for (i = 1; i <= 15; ++i) {
			if (i == x1) {
				continue;
			}
			if (c[i] >= 2) {
				y1 = i;
				break;
			}
		}
		if (x1 != -1 && y1 != -1) {
			x1 = x1 > 13 ? x1 - 13 : x1;
			y1 = y1 > 13 ? y1 - 13 : y1;
			printf("%d %d %d %d %d\n", x1, x1, x1, y1, y1);
		} else {
			printf("My God\n");
		}
	}

	return 0;
}