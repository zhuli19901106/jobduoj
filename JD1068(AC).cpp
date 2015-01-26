#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double x1, x2, y1, y2, z1, z2;
	const double pi = acos(-1.0);

	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &x2, &y2, &z2) == 6) {
		printf("%.3f ", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)));
		printf("%.3f\n", 4.0 / 3.0 * pi * pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2), 1.5));
	}

	return 0;
}