#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int n;

	while (scanf("%d", &n) == 1) {
		n *= 3;
		for (x = 0; 14 * x + 100 <= n; ++x) {
			for (y = 0; 14 * x + 8 * y + 100 <= n; ++y) {
				printf("x=%d,y=%d,z=%d\n", x, y, 100 - x - y);
			}
		}
	}

	return 0;
}