#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 700;
const int r = 10000;

void mul(int a[], int n)
{
	int i;
	
	for (i = 0; i < maxn; ++i) {
		a[i] *= n;
	}
	for (i = 0; i < maxn - 1; ++i) {
		a[i + 1] += a[i] / r;
		a[i] %= r;
	}
	a[maxn - 1] %= r;
}

int main()
{
	int i;
	int n;
	int a[maxn];
	
	while (scanf("%d", &n) == 1) {
		memset(a, 0, maxn * sizeof(int));
		a[0] = 1;
		for (i = 2; i <= n; ++i) {
			mul(a, i);
		}
		i = maxn - 1;
		while (i > 0 && a[i] == 0) {
			--i;
		}
		printf("%d", a[i--]);
		while (i >= 0) {
			printf("%04d", a[i--]);
		}
		printf("\n");
	}
	
	return 0;
}