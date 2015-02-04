#include <cstdio>
#include <vector>
using namespace std;

int a[8][8];
vector<vector<int> > res;

void dfs(vector<int> &v, int x)
{
	if (x == 8) {
		res.push_back(v);
		return;
	}

	int i, j;
	int y;
	for (y = 0; y < 8; ++y) {
		for (j = 0; j < v.size(); ++j) {
			if (x == j || y == v[j]) {
				break;
			}
			if (x - j == y - v[j]) {
				break;
			}
			if (x + y == j + v[j]) {
				break;
			}
		}
		if (j < v.size()) {
			continue;
		}
		v.push_back(y);
		dfs(v, x + 1);
		v.pop_back();
	}
}

int main()
{
	vector<int> v;
	dfs(v, 0);
	int i, n;
	int t, ti;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d", &n);
			for (i = 0; i < 8; ++i) {
				printf("%d", res[n - 1][i] + 1);
			}
			printf("\n");
		}
	}

	return 0;
}