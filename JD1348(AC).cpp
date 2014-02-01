// 687950	zhuli19901106	1348	Accepted	点击此处查看所有case的执行结果	1800KB	1093B	100MS
// 201401302316
#include <cstdio>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
int n;
long long int res;
int tmp[MAXN];

void merge_sort_recursive(int a[], int ll, int rr)
{
	if (ll >= rr) {
		return;
	}
	int mm;
	mm = (ll + rr) / 2;
	merge_sort_recursive(a, ll, mm);
	merge_sort_recursive(a, mm + 1, rr);

	int i, j, k;

	i = ll;
	j = mm + 1;
	k = ll;
	while (true) {
		if (i <= mm) {
			if (j <= rr) {
				if (a[i] <= a[j]) {
					tmp[k++] = a[i++];
				} else {
					tmp[k++] = a[j++];
					res += mm - i + 1;
				}
			} else {
				tmp[k++] = a[i++];
			}
		} else {
			if (j <= rr) {
				tmp[k++] = a[j++];
			} else {
				break;
			}
		}
	}
	for (i = ll; i <= rr; ++i) {
		a[i] = tmp[i];
	}
}

int main() 
{
	int i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		res = 0;
		merge_sort_recursive(a, 0, n - 1);
		printf("%lld\n", res);
	}

	return 0;
}