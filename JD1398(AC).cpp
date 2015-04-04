#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int a[205];
	int i;
	int mi;
	int MI;
	int n;
	int ans;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		mi = 0;
		for (i = 1; i <= n - 1; ++i) {
			if (a[i] < a[mi]) {
				mi = i;
			}
		}
		ans = mi;
		for (i = mi; i > 0; --i) {
			swap(a[i], a[i - 1]);
		}
		MI = n - 1;
		for (i = n - 2; i >= 0; --i) {
			if (a[i] > a[MI]) {
				MI = i;
			}
		}
		ans += n - 1 - MI;
		printf("%d\n", ans);
	}

	return 0;
}