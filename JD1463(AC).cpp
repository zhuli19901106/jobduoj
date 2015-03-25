#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Item {
	int x, y;
} Item;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.x != i2.x) {
		return i1.x < i2.x;
	} else {
		return i1.y < i2.y;
	}
}

int n;
vector<Item> a;
vector<int> dp;

int main()
{
	int i, j;

	while (scanf("%d", &n) == 1) {
		a.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a.begin(), a.end(), comp);
		dp.resize(n, 1);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < i; ++j) {
				if (a[j].y <= a[i].x) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		j = dp[0];
		for (i = 1; i < n; ++i) {
			j = max(j, dp[i]);
		}
		printf("%d\n", j);

		a.clear();
		dp.clear();
	}

	return 0;
}