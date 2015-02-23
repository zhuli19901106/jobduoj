#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int x1, x2, y1, y2;
	bool empty;

	empty = true;
	while (scanf("%d%d", &x, &y) == 2) {
		if (x || y) {
			if (empty) {
				empty = false;
				x1 = x2 = x;
				y1 = y2 = y;
			} else {
				x1 = min(x1, x);
				y1 = min(y1, y);
				x2 = max(x2, x);
				y2 = max(y2, y);
			}
			continue;
		}

		if (x == 0 && y == 0 && empty) {
			break;
		}
		printf("%d %d %d %d\n", x1, y1, x2, y2);
		empty = true;
	}

	return 0;
}