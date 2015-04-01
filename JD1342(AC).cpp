#include <cstdio>
#include <cstring>
using namespace std;

char s[1000005];

int main()
{
	int ans;
	int st;
	int i;

	while (scanf("%s", s) == 1) {
		ans = 0;
		st = 0;
		for (i = 0; s[i]; ++i) {
			if (s[i] == '(') {
				++st;
			} else {
				if (st > 0) {
					ans += 2;
					--st;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}