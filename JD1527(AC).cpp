#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int sum1(vector<int> &a)
{
	int sum;
	int msum;
	int n, i;

	n = a.size();
	sum = a[0];
	for (i = 1; i < n; ++i) {
		sum = max(sum, a[i]);
	}
	if (sum < 0) {
		return 0;
	}

	msum = sum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
		msum = max(msum, sum);
		if (sum < 0) {
			sum = 0;
		}
	}

	return msum;
}

int sum2(vector<int> &a)
{
	int n;
	int i;
	int sum;
	vector<int> s1, s2;

	n = a.size();
	s1.resize(n);
	s2.resize(n);

	sum = s1[0] = a[0];
	for (i = 1; i <= n - 1; ++i) {
		sum += a[i];
		s1[i] = max(sum, s1[i - 1]);
	}

	sum = s2[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; --i) {
		sum += a[i];
		s2[i] = max(sum, s2[i + 1]);
	}

	sum = s2[0];
	for (i = 1; i <= n - 1; ++i) {
		sum = max(sum, s1[i - 1] + s2[i]);
	}

	return sum;
}

int main()
{
	vector<int> a;
	int n;
	int i;

	while (scanf("%d", &n) == 1) {
		a.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		printf("%d\n", max(sum1(a), sum2(a)));
		a.clear();
	}

	return 0;
}