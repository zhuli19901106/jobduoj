#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;

bool comp(const LL &x, const LL &y)
{
	return x > y;
}

int main()
{
	LL m;
	int n, i;
	int ans;
	vector<LL> v;

	while (scanf("%lld%d", &m, &n) == 2) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &v[i]);
		}
		sort(v.begin(), v.end(), comp);
		ans = 0;
		for (i = 0; i < n; ++i) {
			if (m <= 0) {
				break;
			} else {
				m -= v[i];
				++ans;
			}
		}
		if (m <= 0) {
			printf("%d\n", ans);
		} else {
			printf("impossible\n");
		}
		v.clear();
	}

	return 0;
}