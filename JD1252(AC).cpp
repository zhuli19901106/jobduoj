#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int pal(char s[])
{
	int i, j;
	int n;
	int mx;

	n = strlen(s);
	if (n < 2) {
		return n;
	}

	mx = 1;
	for (i = 0; i <= n - 1; ++i) {
		j = 1;
		while (i - j >= 0 && i + j <= n - 1 && s[i - j] == s[i + j]) {
			++j;
		}
		--j;
		mx = max(mx, 2 * j + 1);
	}

	for (i = 0; i < n - 1; ++i) {
		j = 0;
		while (i - j >= 0 && i + 1 + j <= n - 1 && s[i - j] == s[i + 1 + j]) {
			++j;
		}
		--j;
		mx = max(mx, 2 * j + 2);
	}

	return mx;
}

int main()
{
	char s[105];

	while (gets(s)) {
		printf("%d\n", pal(s));
	}

	return 0;
}