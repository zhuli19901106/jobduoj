#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 10009;
const int N = 1000;
int a[N + 1][N + 1];

int main()
{
	int i, j;

	for (i = 1; i <= N; ++i) {
		a[i][1] = a[1][i] = 1;
	}
	for (i = 2; i <= N; ++i) {
		for (j = 2; j <= N; ++j) {
			a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD;
		}
	}

	while (scanf("%d%d", &i, &j) == 2) {
		if (i < 1 || j < 1) {
			puts("0");
		} else {
			printf("%d\n", a[i][j]);
		}
	}

	return 0;

}