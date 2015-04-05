#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int N = 305;
int n;
set<int> a[N];
vector<int> leaf;
vector<int> path;
vector<int> res;
int lc;
int b[N];
bool suc;

void findLeaf(int idx)
{
	b[idx] = 1;

	int c;
	set<int>::iterator it;

	c = 0;
	for (it = a[idx].begin(); it != a[idx].end(); ++it) {
		if (b[*it]) {
			continue;
		}
		++c;
		findLeaf(*it);
	}
	if (c == 0) {
		++lc;
	}
}

void dfs(int cur, int dst)
{
	b[cur] = 1;
	path.push_back(cur);
	if (cur == dst) {
		suc = true;
		return;
	}

	set<int>::iterator it;
	for (it = a[cur].begin(); it != a[cur].end(); ++it) {
		if (b[*it]) {
			continue;
		}
		dfs(*it, dst);
		if (suc) {
			return;
		}
	}

	path.pop_back();
	b[cur] = 0;
}

int main()
{
	int i, j;
	int x, y;

	while (scanf("%d", &n) == 1) {
		if (n == 1) {
			scanf("%d", &x);
			puts("1");
			continue;
		}

		for (i = 1; i <= n - 1; ++i) {
			scanf("%d%d", &x, &y);
			a[x].insert(y);
			a[y].insert(x);
		}

		// Count the number of leaf nodes.
		memset(b, 0, sizeof(b));
		lc = 0;
		findLeaf(1);

		leaf.push_back(1);
		for (i = 0; i < lc; ++i) {
			scanf("%d", &x);
			leaf.push_back(x);
		}
		leaf.push_back(1);
		res.push_back(1);
		for (i = 0; i < leaf.size() - 1; ++i) {
			memset(b, 0, sizeof(b));
			path.clear();
			suc = false;
			dfs(leaf[i], leaf[i + 1]);
			if (!suc) {
				break;
			}
			for (j = 1; j < path.size(); ++j) {
				a[path[j - 1]].erase(path[j]);
			}
			for (j = 1; j < path.size(); ++j) {
				res.push_back(path[j]);
			}
		}
		if (i == leaf.size() - 1) {
			printf("%d", res[0]);
			for (i = 1; i < res.size(); ++i) {
				printf(" %d", res[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}

		for (i = 1; i <= n; ++i) {
			a[i].clear();
		}
		leaf.clear();
		path.clear();
		res.clear();
	}

	return 0;
}