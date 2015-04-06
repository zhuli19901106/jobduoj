#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000005;
char str[N];
int st[N], sp;
int dp[N];
int len;
int ans;
int cc;

int main()
{
	int i;

	while (scanf("%d%s", &len, str) == 2) {
		sp = 0;
		ans = 0;
		cc = 0;
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= len; ++i) {
			if (str[i - 1] == '(') {
				st[sp++] = i;
				dp[i] = 0;
			} else {
				if (sp > 0) {
					--sp;
					dp[i] = dp[st[sp] - 1] + 2;
					if (str[i - 2] == ')') {
						dp[i] += dp[i - 1];
					}
					dp[st[sp] - 1] = dp[i];
				} else {
					dp[i] = 0;
				}
			}

			if (dp[i] > ans) {
				ans = dp[i];
				cc = 1;
			} else if (dp[i] == ans) {
				++cc;
			}
		}

		if (ans > 0) {
			printf("%d %d\n", ans, cc);
		} else {
			printf("0 1\n");
		}
	}

	return 0;
}