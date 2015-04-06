#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100;
const int W = 100000;
int v[N * W / 2 + 1];
int a[N];
int n;
int sum;
int sum1;
int msum;

int main()
{
	int i, j;

	while (scanf("%d", &n) == 1) {
		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n);
		sum1 = sum / 2;

		memset(v, 0, sizeof(v));
		sum = 0;
		v[0] = 1;
		for (i = 0; i < n; ++i) {
			sum += a[i];
			msum = min(sum, sum1);
			for (j = msum; j >= a[i]; --j) {
				if (v[j - a[i]]) {
					v[j] = 1;
				}
			}
		}

		for (j = sum1; !v[j]; --j) {}
		printf("%d\n", sum - 2 * j);
	}

	return 0;
}