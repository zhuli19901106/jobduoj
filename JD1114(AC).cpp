#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int n;
int cc;

void dfs(int idx, int sum)
{
	if (sum == 40) {
		++cc;
		return;
	}

	int i;
	for (i = idx; i < n; ++i) {
		if (sum + v[i] <= 40) {
			dfs(i + 1, sum + v[i]);
		}
	}
}

int main()
{
	int i;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		cc = 0;
		dfs(0, 0);
		printf("%d\n", cc);
		v.clear();
	}

	return 0;
}