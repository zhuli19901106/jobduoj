#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 1005;
	char s[MAXN];
	char c;
	int i, j;

	while (gets(s) != NULL) {
		c = getchar();
		getchar();
		i = j = 0;
		while (s[i]) {
			if (s[i] != c) {
				s[j++] = s[i++];
			} else {
				++i;
			}
		}
		s[j] = 0;
		puts(s);
	}

	return 0;
}