#include <cstdio>
using namespace std;

typedef long long int LL;

int main()
{
	const int N = 20;
	LL a[N + 1];
	int n;

	a[0] = a[1] = 0;
	a[2] = 1;
	for (n = 3; n <= N; ++n) {
		a[n] = (n - 1) * (a[n - 1] + a[n - 2]);
	}

	while (scanf("%d", &n) == 1) {
		printf("%lld\n", a[n]);
	}

	return 0;
}