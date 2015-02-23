#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct BG{
	int h, l, t;
}BG;

bool comparator(const BG &b1, const BG &b2)
{
	if (b1.t != b2.t) {
		return b1.t < b2.t;
	} else if (b1.h / b1.l != b2.h / b2.l) {
		return b1.h / b1.l > b2.h / b2.l;
	} else {
		return b1.l < b2.l;
	}
}

int n;
vector<BG> v;
int ans;

void dfs(int idx, int time, int sum)
{
	if (sum > ans) {
		ans = sum;
	}

	if (idx == n) {
		return;
	}

	dfs(idx + 1, time, sum);
	if (time + v[idx].l > v[idx].t) {
		return;
	}
	dfs(idx + 1, time + v[idx].l, sum + v[idx].h);
}

int main()
{
	BG b;
	int i;

	while (scanf("%d", &n) == 1 && n >= 0) {
		if (n == 0) {
			printf("0\n");
			continue;
		}
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &b.h, &b.l, &b.t);
			if (b.l <= 0) {
				continue;
			}
			v.push_back(b);
		}
		n = v.size();
		sort(v.begin(), v.end(), comparator);
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
		v.clear();
	}

	return 0;
}