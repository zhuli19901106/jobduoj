#include <cstdio>
using namespace std;

int m[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
char s[10005];

int main()
{
	int i;

	while (scanf("%s", s) == 1) {
		for (i = 0; s[i]; ++i) {
			putchar(m[s[i] - 'a'] + '0');
		}
		putchar('\n');
	}

	return 0;
}