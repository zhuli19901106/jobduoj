#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
int a[N][N][N];
int dp[N][N][N];

int main()
{
	int ni;
	int i, j, k;
	int n;
	int mi, mj, mk;
	int mx;
	
	while(scanf("%d", &n) == 1) {
		mi = mj = mk = 0;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for (ni = 1; ni <= n; ++ni) {
			scanf("%d%d%d", &i, &j, &k);
			mi = max(mi, i);
			mj = max(mj, j);
			mk = max(mk, k);
			++a[i][j][k];
		}
		for (i = 1; i <= mi; ++i) {
			for (j = 1; j <= mj; ++j) {
				for (k = 1; k <= mk; ++k) {
					mx = max(dp[i][j - 1][k], dp[i][j][k - 1]);
					mx = max(mx, dp[i - 1][j][k]);
					dp[i][j][k] = mx + a[i][j][k];
				}
			}
		}
		printf("%d\n",dp[mi][mj][mk]);
	}

	return 0;
}
/*
// Brute-force Solution
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Item {
	int x, y, z;
} Item;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.x != i2.x) {
		return i1.x < i2.x;
	} else if (i1.y != i2.y) {
		return i1.y < i2.y;
	} else {
		return i1.z < i2.z;
	}
}

const int N = 1000005;
Item a[N];
int dp[N];
int ans;
int n;

int main()
{
	int i, j;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		}
		sort(a, a + n, comp);
		
		ans = 0;
		for (i = 0; i < n; ++i) {
			dp[i] = 1;
			for (j = 0; j < i; ++j) {
				if (a[j].x <= a[i].x && a[j].y <= a[i].y && a[j].z <= a[i].z) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}
*/