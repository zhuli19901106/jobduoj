#include <cstdio>
using namespace std;

int main()
{
	long long int a[21];
	long long int i;

	a[0] = 1;
	for (i = 1; i <= 20; ++i) {
		a[i] = a[i - 1] * i;
	}

	long long int y1, y2;
	long long int n;

	while (scanf("%lld", &n) == 1) {
		y1 = y2 = 0;
		for (i = 1; i <= n; i += 2) {
			y1 += a[i];
		}
		for (i = 2; i <= n; i += 2) {
			y2 += a[i];
		}
		printf("%lld %lld\n", y1, y2);
	}

	return 0;
}