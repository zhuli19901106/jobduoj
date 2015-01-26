#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double p, t, g1, g2, g3, gj;
	double d12, d13, d23;
	double res;

	while (scanf("%lf%lf%lf%lf%lf%lf", &p, &t, &g1, &g2, &g3, &gj) == 6) {
		d12 = fabs(g1 - g2);
		if (d12 <= t) {
			res = (g1 + g2) / 2.0;
		} else {
			d13 = fabs(g1 - g3);
			d23 = fabs(g2 - g3);
			if (d13 <= t) {
				if (d23 <= t) {
					res = max(g1, max(g2, g3));
				} else {
					res = (g1 + g3) / 2.0;
				}
			} else {
				if (d23 <= t) {
					res = (g2 + g3) / 2.0;
				} else {
					res = gj;
				}
			}
		}
		printf("%.1f\n", res);
	}

	return 0;
}