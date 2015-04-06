// Catalan Number
#include <cstdio>
using namespace std;

typedef long long int LL;
const int N = 40;
LL a[N / 2 + 1];

int main()
{
	int i, j;

	a[0] = a[1] = 1;
	for (i = 2; i <=  N / 2; ++i) {
		a[i] = 0;
		for (j = 0; j <= i - 1; ++j) {
			a[i] += a[j] * a[i - 1 - j];
		}
	}

	while (scanf("%d", &i) == 1) {
		printf("%lld\n", a[i / 2]);
	}

	return 0;
}