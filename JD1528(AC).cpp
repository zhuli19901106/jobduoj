#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const char UNDEF1 = '$';
const char UNDEF2 = '#';
const int N = 200005;
char str[N];
char ss[2 * N];
int dp[2 * N];

int manacher()
{
	int len, nlen;
	int i;

	len = strlen(str);
	if (len < 2) {
		return len;
	}

	nlen = 0;
	ss[nlen++] = UNDEF1;
	for (i = 0; i < len; ++i) {
		ss[nlen++] = str[i];
		ss[nlen++] = UNDEF2;
	}
	ss[nlen] = 0;

	int mpos;
	int mi;

	mi = mpos = dp[0] = 0;
	for (i = 1; i < nlen; ++i) {
		dp[i] = 1;
		if (mpos > i) {
			// Palindromic radius
			dp[i] = dp[2 * mi - i];
			if (i + dp[i] > mpos) {
				// Look at this.
				dp[i] = mpos - i;
			}
		}
		while (ss[i - dp[i]] == ss[i + dp[i]]) {
			++dp[i];
		}
		if (i + dp[i] > mpos) {
			mpos = i + dp[i];
			mi = i;
		}
	}

	int ans = 0;
	for (i = 0; i < nlen; ++i) {
		if (i & 1) {
			ans = max(ans, (dp[i] - 1) / 2 * 2 + 1);
		} else {
			ans = max(ans, dp[i] / 2 * 2);
		}
	}

	return ans;
}

int main()
{
	while (scanf("%s", str) == 1) {
		printf("%d\n", manacher());
	}

	return 0;
}