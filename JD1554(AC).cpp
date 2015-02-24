#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st {
	int x, y;
	
	bool operator < (const st &other) const
	{
		if (x != other.x) {
			return x < other.x;
		} else {
			return y < other.y;
		}
	}
} st;

int binarySearch(vector<st> &v, int left, int right, int val)
{
	if (v[left].x > val || v[right].x < val) {
		return -1;
	}

	if (v[left].x == val) {
		return left;
	}

	int ll, rr, mm;

	ll = left;
	rr = right;

	while (ll + 1 < rr) {
		mm = (ll + rr) / 2;
		if (v[mm].x < val) {
			ll = mm;
		} else {
			rr = mm;
		}
	}
	return v[rr].x == val ? rr : -1;
}

int main()
{
	vector<int> v;
	vector<st> sum;
	int n, i, j;
	st ans, finalAns;
	int k;

	while (scanf("%d", &n) == 1 && n) {
		v.resize(n + 1, 0);
		sum.resize(n + 1);

		sum[0].x = 0;
		sum[0].y = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &v[i]);
			sum[i].x = sum[i - 1].x + v[i];
			sum[i].y = i;
		}
		sort(sum.begin(), sum.end());
		scanf("%d", &k);
		if (k < -100 * n || k > 100 * n) {
			printf("No\n");
			v.clear();
			sum.clear();
			continue;
		}

		finalAns.x = finalAns.y = INT_MAX;
		for (i = 1; i <= n; ++i) {
			j = binarySearch(sum, 0, i - 1, sum[i].x - k);
			if (j == -1) {
				continue;
			}
			while (j < i && sum[j].x == sum[i].x - k) {
				if (sum[j].y > sum[i].y) {
					++j;
					continue;
				} else {
					ans.y = sum[i].y;
					ans.x = sum[j].y + 1;
					finalAns = min(finalAns, ans);
					++j;
				}
			}
		}
		for (i = 1; i <= n; ++i) {
			j = binarySearch(sum, 0, i - 1, sum[i].x + k);
			if (j == -1) {
				continue;
			}
			while (j < i && sum[i].x == sum[j].x - k) {
				if (sum[j].y < sum[i].y) {
					++j;
					continue;
				} else {
					ans.y = sum[j].y;
					ans.x = sum[i].y + 1;
					finalAns = min(finalAns, ans);
					++j;
				}
			}
		}

		if (finalAns.x != INT_MAX) {
			printf("%d %d\n", finalAns.x, finalAns.y);
		} else {
			printf("No\n");
		}
		v.clear();
		sum.clear();
	}

	return 0;
}