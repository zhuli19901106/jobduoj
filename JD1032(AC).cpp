#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[105];
	int len, i;
	int c1, c2, c3;

	while (scanf("%s", s) == 1) {
		if (strcmp(s, "E") == 0) {
			break;
		}
		len = strlen(s);
		c1 = c2 = c3 = 0;
		for (i = 0; i < len; ++i) {
			if (s[i] == 'Z') {
				++c1;
			} else if (s[i] == 'O') {
				++c2;
			} else if (s[i] == 'J') {
				++c3;
			}
		}
		while (c1 || c2 || c3) {
			if (c1 > 0) {
				putchar('Z');
				--c1;
			}
			if (c2 > 0) {
				putchar('O');
				--c2;
			}
			if (c3 > 0) {
				putchar('J');
				--c3;
			}
		}
		putchar('\n');
	}

	return 0;
}