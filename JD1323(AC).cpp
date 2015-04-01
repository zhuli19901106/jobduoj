#include <cstdio>
using namespace std;

int main()
{
	int i, j;
	int mi[3];
	double mx[3];
	char s[] = "WTL";
	double a[3][3];

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			scanf("%lf", &a[i][j]);
		}
		mi[i] = 0;
		mx[i] = a[i][0];
		for (j = 1; j < 3; ++j) {
			if (a[i][j] > mx[i]) {
				mx[i] = a[i][j];
				mi[i] = j;
			}
		}
	}
	printf("%c %c %c %.2f\n", s[mi[0]], s[mi[1]], s[mi[2]], (mx[0] * mx[1] * mx[2] * 0.65 - 1) * 2);

	return 0;
}