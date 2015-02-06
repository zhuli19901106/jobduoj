#include <cstdio>
using namespace std;

int main()
{
	double n;
	double k;
	double s;
	double p;
	double r;
	int y;

	while (scanf("%lf%lf", &n, &k) == 2) {
		k /= 100;
		r = 1 + k;
		p = 200;
		s = n;
		y = 1;
		while (y <= 20) {
			if (s >= p) {
				break;
			} else {
				s += n;
				p *= r;
				++y;
			}
		}

		if (y <= 20) {
			printf("%d\n", y);
		} else {
			printf("Impossible\n");
		}
	}

	return 0;
}