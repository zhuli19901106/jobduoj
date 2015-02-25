#include <cstdio>
using namespace std;

const int N = 500;
const int MOD = 1000000007;
long long int a[N + 1];

int main()
{
	int i, j;

	a[0] = a[1] = 1;
	for (i = 2; i < N; ++i) {
		a[i] = 0;
		for (j = 0; j <= i - 1; ++j) {
			a[i] = (a[i] + a[j] * a[i - j - 1]) % MOD;
		}
	}

	while (scanf("%d", &i) == 1) {
		if (i % 2) {
			printf("0\n");
		} else {
			printf("%lld\n", a[i / 2]);
		}
	}
	
	return 0;
}