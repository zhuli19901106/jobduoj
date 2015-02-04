#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int n, i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			if (x == y) {
				printf("%d\n", (x % 2 ? 2 * x - 1 : 2 * x));
			} else if (x == y + 2) {
				printf("%d\n", (x % 2 ? 2 * x - 3 : 2 * x - 2));
			} else {
				printf("No Number\n");
			}
		}
	}

	return 0;
}