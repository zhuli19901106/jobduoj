#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 2005;
	int a[26];
	char s[MAXN];
	int i, len;

	while (gets(s) != NULL) {
		len = strlen(s);
		memset(a, 0, sizeof(a));
		for (i = 0; i < len; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				++a[s[i] - 'A'];
			}
		}
		for (i = 0; i < 26; ++i) {
			printf("%c:%d\n", i + 'A', a[i]);
		}
	}

	return 0;
}