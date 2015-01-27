#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 105;
	int a[MAXN];
	int maxv, minv;
	int maxi, mini;
	int n;
	int i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		maxv = INT_MIN;
		minv = INT_MAX;
		for (i = 0; i < n; ++i) {
			if (a[i] > maxv) {
				maxv = a[i];
				maxi = i;
			}
			if (a[i] < minv) {
				minv = a[i];
				mini = i;
			}
		}
		swap(a[mini], a[maxi]);
		for (i = 0; i < n; ++i) {
			printf((i ? " %d" : "%d"), a[i]);
		}
		putchar('\n');
	}

	return 0;
}