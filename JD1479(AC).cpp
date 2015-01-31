#include <algorithm>
#include <cstdio>
using namespace std;

void rev(int a[], int ll, int rr)
{
	int i;

	if (ll > rr) {
		swap(ll, rr);
	}
	for (i = ll; i < ll + rr - i; ++i) {
		swap(a[i], a[ll + rr - i]);
	}
}

void rot(int a[], int n, int r)
{
	rev(a, 1, r);
	rev(a, r + 1, n);
	rev(a, 1, n);
}

int main()
{
	int n, k, r;
	int i;
	int a[1005];

	while (scanf("%d", &n) == 1 && n) {
		for (i = 1; i <= n; ++i) {
			a[i] = i;
		}
		scanf("%d", &k);
		for (i = 0; i < k; ++i) {
			scanf("%d", &r);
			rot(a, n, r);
			rev(a, 1, n / 2);
		}
		for (i = 1; i <= n; ++i) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

	return 0;
}