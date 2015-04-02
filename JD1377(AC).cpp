#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100000;
const int M = 10000;
int c[M + 5];
int a[N + 5];
int f[N + 5];
int n;

int main()
{
	int ll, rr;
	int i;
	
	while (scanf("%d", &n) == 1) {
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		ll = INT_MAX;
		rr = INT_MIN;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			++c[a[i]];
			ll = min(ll, a[i]);
			rr = max(rr, a[i]);
		}
		f[ll] = c[ll];
		for (i = ll + 1; i <= rr; ++i) {
			f[i] = c[i] - f[i - 1];
		}
		for (i = ll; i < rr; ++i) {
			if (f[i] <= 0) {
				break;
			}
		}
		if (i < rr || f[rr] != 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}

	return 0;
}