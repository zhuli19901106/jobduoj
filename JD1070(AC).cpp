#include <cstdio>
using namespace std;

bool leap(int y)
{
	return !(y % 100 ? y % 4 : y % 400);
}

int main()
{
	int y, m, d;
	int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	int count;
	
	while (scanf("%d%d%d", &y, &m, &d) == 3) {
		a[2] = leap(y) ? 29 : 28;
		count = 0;
		for (i = 1; i < m; ++i) {
			count += a[i];
		}
		count += d;
		printf("%d\n", count);
	}
	
	return 0;
}