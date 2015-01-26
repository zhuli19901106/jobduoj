#include <cstdio>
using namespace std;

int main()
{
	long long int *a;
	const int MAXN = 1000001;
	const long long int MOD = 1000000000;

	a = new long long int[MAXN + 1];
	a[0] = 1;
	a[1] = 1;
	int i;
	for (i = 2; i < MAXN; ++i) {
		a[i] = (i & 1) ? a[i - 1] : a[i - 1] + a[i >> 1];
		a[i] %= MOD;
	}
	while (scanf("%d", &i) == 1) {
		printf("%lld\n", a[i]);
	}

	delete[] a;

	return 0;
}