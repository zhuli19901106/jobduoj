#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int i;
	int n;
	int ll;
	int mll, mrr;
	int sum, msum;

	while (scanf("%d", &n) == 1 && n) {
		v.resize(n);
		sum = INT_MIN;
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			sum = max(sum, v[i]);
		}
		if (sum < 0) {
			printf("0 %d %d\n", v[0], v[n - 1]);
			v.clear();
			continue;
		}

		msum = -1;
		sum = 0;

		mll = ll = 0;
		mrr = -1;

		for (i = 0; i < n; ++i) {
			sum += v[i];
			if (sum > msum) {
				mll = ll;
				mrr = i;
				msum = sum;
			}
			if (sum < 0) {
				ll = i + 1;
				sum = 0;
			}
		}
		printf("%d %d %d\n", msum, v[mll], v[mrr]);
		v.clear();
	}

	return 0;
}