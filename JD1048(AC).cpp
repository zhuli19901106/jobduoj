#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int a, b, c;

	while (scanf("%d%d%d", &a, &b, &c) == 3) {
		if (a > b) {
			swap(a, b);
		}
		if (a > c) {
			swap(a, c);
		}
		if (b > c) {
			swap(b, c);
		}

		if (a * a + b * b > c* c) {
			printf("锐角三角形\n");
		} else if (a * a + b * b < c * c) {
			printf("钝角三角形\n");
		} else {
			printf("直角三角形\n");
		}
	}

	return 0;
}