#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10005;
int c[256];
char s[N];

int main()
{
	int ll;
	int len;
	int ans;
	int i, j;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		memset(c, -1, sizeof(c));
		c[s[0]] = 0;
		ll = 0;
		ans = 1;
		for (i = 1; i < len; ++i) {
			if (c[s[i]] != -1) {
				for (j = ll, ll = c[s[i]] + 1; j <= c[s[i]]; ++j) {
					c[s[j]] = -1;
				}
			}
			c[s[i]] = i;
			ans = max(ans, i - ll + 1);
		}
		printf("%d\n", ans);
	}

	return 0;
}