#include <cmath>
#include <cstdio>
using namespace std;

const double PI = 3.14159265358979;
const double EPS = 1e-8;

double getRatio(double th)
{
	return (th - sin(th)) / (2 * PI - th + sin(th));
}

int main()
{
	double r, R;
	double th1, th2, th0;
	double r0;
	double h;

	while (scanf("%lf%lf", &R, &r) == 2) {
		th1 = 0;
		th2 = PI;
		while (fabs(th1 - th2) >= EPS) {
			th0 = th1 + (th2 - th1) * 0.5;
			r0 = getRatio(th0);
			if (r0 > r) {
				th2 = th0;
			} else {
				th1 = th0;
			}
		}
		h = sqrt(2 * R * R * (1 - cos(th0)));
		printf("%.2f\n", h);
	}

	return 0;
}