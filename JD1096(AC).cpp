#include <algorithm>
#include <cstdio>
using namespace std;

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool leap(int y)
{
	return y % 100 ? y % 4 == 0 : y % 400 == 0;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int i;
	int dd1;
	int dd2;
	int sum;

	dd1 = 0;
	for (i = 1; i < m1; ++i) {
		dd1 += md[i];
		if (i == 2 && leap(y1)) {
			++dd1;
		}
	}
	dd1 += d1 - 1;

	dd2 = 0;
	for (i = 1; i < m2; ++i) {
		dd2 += md[i];
		if (i == 2 && leap(y2)) {
			++dd2;
		}
	}
	dd2 += d2 - 1;

	sum = 0;
	for (i = y1; i < y2; ++i) {
		sum += (leap(i) ? 366 : 365);
	}

	return sum - dd1 + dd2;
}

int main()
{
	int n1, n2;
	int y1, y2, m1, m2, d1, d2;

	while (scanf("%8d%8d", &n1, &n2) == 2) {
		if (n1 > n2) {
			swap(n1, n2);
		}
		y1 = n1 / 10000;
		m1 = n1 / 100 % 100;
		d1 = n1 % 100;
		y2 = n2 / 10000;
		m2 = n2 / 100 % 100;
		d2 = n2 % 100;
		printf("%d\n", diff(y1, m1, d1, y2, m2, d2) + 1);
	}

	return 0;
}