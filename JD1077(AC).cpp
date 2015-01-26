#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<long long int> v;
	long long int sum, msum;
	int i;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &v[i]);
		}
		msum = v[0];
		for (i = 1; i < n; ++i) {
			msum = max(msum, v[i]);
		}
		if (msum <= 0) {
			printf("%d\n", msum);
			continue;
		}

		msum = sum = 0;
		for (i = 0; i < n; ++i) {
			sum += v[i];
			if (sum > msum) {
				msum = sum;
			}
			if (sum < 0) {
				sum = 0;
			}
		}
		printf("%lld\n", msum);
		v.clear();
	}

	return 0;
}
