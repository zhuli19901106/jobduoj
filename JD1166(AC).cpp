#include <cstdio>
using namespace std;

int main()
{
	double x;
	double y;
	int n, i;

	while (scanf("%lf%d", &x, &n) == 2) {
		y = x;
		for (i = 0; i < n; ++i) {
			y = y * 2.0 / 3.0 + x / (3.0 * y * y);
		}
		printf("%f\n", y);
	}

	return 0;
}