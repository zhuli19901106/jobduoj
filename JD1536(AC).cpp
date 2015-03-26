#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1000005;
vector<vector<int> > v;
int d[N];
int b[N];
int n;
int p1, p2;

void dfs(int idx, int dist)
{
	b[idx] = 1;
	d[idx] = dist;

	int i;
	
	for (i = 0; i < v[idx].size(); ++i) {
		if (b[v[idx][i]]) {
			continue;
		}
		dfs(v[idx][i], dist + 1);
	}
}

int main()
{
	int x, y;
	int i;
	int mx;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		memset(d, 0, sizeof(d));
		memset(b, 0, sizeof(b));
		dfs(0, 0);

		p1 = 0;
		mx = d[p1];
		for (i = 1; i < n; ++i) {
			if (d[i] > mx) {
				mx = d[i];
				p1 = i;
			}
		}

		memset(d, 0, sizeof(d));
		memset(b, 0, sizeof(b));
		dfs(p1, 0);

		p2 = 0;
		mx = d[p2];
		for (i = 1; i < n; ++i) {
			if (d[i] > mx) {
				mx = d[i];
				p2 = i;
			}
		}

		printf("%d\n", (d[p2] + 1) / 2);

		v.clear();
	}

	return 0;
}