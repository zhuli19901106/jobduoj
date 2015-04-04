#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int a[N];
char s[105];
int n;
int ans;

int main()
{
	int i, j;
	int len;
	int val;

	while (scanf("%d", &n) == 1) {
		memset(a, 0, sizeof(a));
		ans = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%s", s);
			len = strlen(s);
			j = 0;
			while (j < len - 1 && s[j] == '0') {
				++j;
			}
			if (len - j > 6) {
				++ans;
				continue;
			}
			sscanf(s, "%d", &val);
			if (val < 1 || val > n || a[val]) {
				++ans;
			} else {
				a[val] = 1;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}