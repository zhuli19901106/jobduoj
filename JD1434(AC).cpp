#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Item {
	int s, e;
} Item;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.s != i2.s) {
		return i1.s < i2.s;
	} else {
		return i1.e < i2.e;
	}
}

int main()
{
	vector<Item> v;
	vector<int> dp;
	int n, i, j;
	Item it;
	int ans;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &it.s, &it.e);
			if (it.s > it.e) {
				continue;
			}
			v.push_back(it);
			dp.push_back(1);
		}
		sort(v.begin(), v.end(), comp);

		ans = 0;
		n = v.size();
		for (i = 0; i < n; ++i) {
			for (j = 0; j < i; ++j) {
				if (v[j].e <= v[i].s) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
		
		v.clear();
		dp.clear();
	}

	return 0;
}