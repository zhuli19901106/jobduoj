#include <cstdio>
#include <vector>
using namespace std;

int res;
int m, n;
vector<int> v;

void dfs(int idx, int rem, int cc, vector<int> &v)
{

	if (rem == 0) {
		if (cc == n) {
			/*
			for (int i = 0; i < v.size(); ++i) {
				printf("%d ", v[i]);
			}
			printf("\n");
			*/
			++res;
		}
		return;
	}

	if (cc == n) {
		return;
	}

	int i;

	for (i = idx; i <= rem / (n - cc); ++i) {
		v.push_back(i);
		dfs(i, rem - i, cc + 1, v);
		v.pop_back();
	}
}

int main()
{
	int t, ti;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d%d", &m, &n);
			res = 0;
			dfs(0, m, 0, v);
			printf("%d\n", res);
		}
	}

	return 0;
}