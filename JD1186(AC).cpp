#include <cstdio>
using namespace std;

bool leap(int y)
{
	return y % 100 ? y % 4 == 0 : y % 400 == 0;
}

int main()
{
	int md[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int d;
	int y;
	int i;

	while (scanf("%d%d", &y, &d) == 2) {
		if (leap(y)) {
			md[2] = 29;
		} else {
			md[2] = 28;
		}
		i = 1;
		while (d > md[i]) {
			d -= md[i];
			++i;
		}
		printf("%04d-%02d-%02d\n", y, i, d);
	}

	return 0;
}