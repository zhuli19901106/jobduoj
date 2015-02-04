#include <cstdio>
using namespace std;

int main()
{
	int i, n;
	double d, s;

	while (scanf("%d", &n) == 1) {
		s = 0;
		for (i = 0; i < n; ++i) {
			scanf("%lf", &d);
			s += d;
		}
		s /= n;
		printf("%.2f\n", s);
	}

	return 0;
}