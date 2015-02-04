#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

int maxSum(int a[], int n)
{
	int sum, msum;
	int i;

	sum = a[0];
	for (i = 1; i < n; ++i) {
		sum = max(sum, a[i]);
	}
	if (sum <= 0) {
		return sum;
	}

	sum = msum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
		if (sum > msum) {
			msum = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}

	return msum;
}

int main()
{
	int i, j, k;
	int v[N];
	int res;
	int a[N][N];
	int s[N][N];
	int n;
	
	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
			}
		}
		for (j = 0; j < n; ++j) {
			s[0][j] = a[0][j];
		}
		for (i = 1; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				s[i][j] = s[i - 1][j] + a[i][j];
			}
		}
		res = INT_MIN;
		for (i = 0; i < n; ++i) {
			for (j = i; j < n; ++j) {
				for (k = 0; k < n; ++k) {
					v[k] = i ? s[j][k] - s[i - 1][k] : s[j][k];
				}
				res = max(res, maxSum(v, n));
			}
		}
		printf("%d\n", res);
	}

	return 0;
}