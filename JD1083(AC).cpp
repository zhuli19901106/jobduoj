#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int sx, sy;
	
	while (scanf("%d%d", &x, &y) == 2) {
		sx = sy = 0;
		while (x != 0) {
			sx += x % 10;
			x /= 10;
		}
		while (y != 0) {
			sy += y % 10;
			y /= 10;
		}
		printf("%d\n", sx * sy);
	}
	
	return 0;
}