#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Term {
	int s;
	int i;
} Term;

const int N = 100005;
Term sum[N];
int a[N];
int ans;
int n;

int myabs(int x)
{
	return x > 0 ? x : -x;
}

bool smaller(const int &x, const int &y)
{
	if (myabs(x) > myabs(y)) {
		return false;
	}
	if (myabs(x) < myabs(y)) {
		return true;
	}
	if (x > y) {
		return true;
	} else {
		return false;
	}
}

bool comp(const Term &x, const Term &y)
{
	return x.s < y.s;
}

int main()
{
	int i;
	int val;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		ans = a[0];
		sum[0].s = a[0];
		sum[0].i = 0;
		for (i = 1; i < n; ++i) {
			sum[i].s = sum[i - 1].s + a[i];
			sum[i].i = i;
			if (!smaller(ans, sum[i].s)) {
				ans = sum[i].s;
			}
		}
		sort(sum, sum + n, comp);
		for (i = 1; i < n; ++i) {
			if (sum[i - 1].i < sum[i].i) {
				val = sum[i].s - sum[i - 1].s;
			} else {
				val = sum[i - 1].s - sum[i].s;
			}
			if (!smaller(ans, val)) {
				ans = val;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}