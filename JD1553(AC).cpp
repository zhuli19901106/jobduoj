#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	char s[10];
	double h, m;
	double d;

	while (scanf("%s", s) == 1) {
		sscanf(s, "%02lf:%02lf", &h, &m);
		h += m / 60;
		if (h >= 12) {
			h -= 12;
		}
		d = fabs(h * 30 - m * 6);
		if (d > 180) {
			d = 360 - d;
		}
		printf("%.2f\n", d);
	}

	return 0;
}