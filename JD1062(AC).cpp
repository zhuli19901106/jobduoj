#include <cstdio>
using namespace std;

double f(double x)
{
	if (x < 0) {
		return 0.0;
	} else if (x < 2) {
		return -x + 2.5;
	} else if (x < 4) {
		return 2.0 - 1.5 * (x - 3.0) * (x - 3.0);
	} else if (x < 6) {
		return x / 2.0 - 1.5;
	} else {
		return 0.0;
	}
}

int main()
{
	double x;

	while (scanf("%lf", &x) == 1) {
		printf("%.3f\n", f(x));
	}

	return 0;
}