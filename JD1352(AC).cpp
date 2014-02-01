// 688158	zhuli19901106	1352	Accepted	点击此处查看所有case的执行结果	4928KB	673B	1420MS
// 201401311706
#include <cstdio>
using namespace std;

const int MAXN = 1000005;
int a[MAXN];
int n;
int k;

int main()
{
	int i;
	bool suc;
	int ll, rr;
	int sum;
	
	while (scanf("%d%d", &n, &k) == 2) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		suc = false;
		ll = 0;
		rr = n - 1;
		while (ll < rr) {
			sum = a[ll] + a[rr];
			if (sum < k) {
				++ll;
			} else if (sum > k) {
				--rr;
			} else {
				suc = true;
				break;
			}
		}
		if (suc) {
			printf("%d %d\n", a[ll], a[rr]);
		} else {
			printf("-1 -1\n");
		}
	}

	return 0;
}