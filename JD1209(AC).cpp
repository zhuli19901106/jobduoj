#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long int LL;
bool suc;
int n;
LL m;
vector<LL> v;
int mcc;

void dfs(int idx, int cc, LL sum)
{
	if (sum == m) {
		suc = true;
		mcc = min(mcc, cc);
		return;
	}
	if (idx == n) {
		return;
	}
	int i;
	for (i = idx; i < n; ++i) {
		if (sum + v[i] > m) {
			continue;
		}
		dfs(i + 1, cc + 1, sum + v[i]);
	}
}

int main()
{
	int i;
	
	while (scanf("%lld", &m) == 1) {
		scanf("%d", &n);
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &v[i]);
		}

		suc = false;
		mcc = INT_MAX;
		dfs(0, 0, 0);
		if (suc) {
			printf("%d\n", mcc);
		} else {
			printf("0\n");
		}
		v.clear();
	}

	return 0;
}