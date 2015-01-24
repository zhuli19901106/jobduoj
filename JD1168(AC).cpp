#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

char p[100];
char s[100005];
char t[100005];

bool charEqual(char c1, char c2)
{
	if (islower(c1)) {
		return c2 == c1 || c2 == c1 - 'a' + 'A';
	} else if (isupper(c1)) {
		return c2 == c1 || c2 == c1 - 'A' + 'a';
	} else {
		return c2 == c1;
	}
}

int main()
{
	int ls, lp;
	int i, j;
	int k;

	gets(p);
	lp = strlen(p);
	while (gets(s) != NULL) {
		ls = strlen(s);
		i = k = 0;
		while (i < ls) {
			if (s[i] == ' ') {
				++i;
				continue;
			}
			for (j = 0; i + j < ls && j < lp; ++j) {
				if (!charEqual(s[i + j], p[j])) {
					break;
				}
			}
			if (j == lp) {
				i += lp;
			} else {
				t[k++] = s[i++];
			}
		}
		t[k] = 0;
		puts(t);
	}

	return 0;
}