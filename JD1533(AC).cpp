#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int LIS(vector<int> &a)
{
	int n = a.size();

	if (n < 2) {
		return n;
	}

	vector<int> s;
	int i;
	int j;

	s.push_back(a[0]);
	for (i = 1; i < n; ++i) {
		if (a[i] > s.back()) {
			s.push_back(a[i]);
			continue;
		}
		j = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
		s[j] = a[i];
	}
	j = s.size();
	s.clear();

	return j;
}

int main()
{
	vector<int> a;
	int n, i;

	while (scanf("%d", &n) == 1) {
		a.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		printf("%d\n", LIS(a));
	}

	return 0;
}