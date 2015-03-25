#include <cstdio>
using namespace std;

typedef long long int LL;

int main()
{
	const int N = 35;
	LL a[N + 1];
	
	a[0] = 0;
	a[1] = 2;
	int i;
	for (i = 2; i <= N; ++i) {
		a[i] = 3 * a[i - 1] + 2;
	}

	while (scanf("%d", &i) == 1) {
		printf("%lld\n", a[i]);
	}

	return 0;
}