#include <cstdio>
#include <vector>
using namespace std;

const int N = 13;
int c[N], d[2 * N - 1], cd[2 * N - 1];
int ans;
int a[N + 1];
int n;

void dfs(int idx)
{
	if (idx == n) {
		++ans;
		return;
	}
	
	int i;
	for (i = 0; i < n; ++i) {
		if (c[i] || d[idx + n - 1 - i] ||cd[idx + i]) {
			continue;
		}
		c[i] = 1;
		d[idx + n - 1 - i] = 1;
		cd[idx + i] = 1;
		dfs(idx + 1);
		c[i] = 0;
		d[idx + n - 1 - i] = 0;
		cd[idx + i] = 0;
	}
}

void solve()
{
	ans = 0;
	dfs(0);
	a[n] = ans;
}

int main()
{
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	for (n = 3; n <= 13; ++n) {
		solve();
		// printf("%d is done. %d\n", n, a[n]);
	}
	
	while (scanf("%d", &n) == 1) {
		printf("%d\n", a[n]);
	}

	return 0;
}