#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[100];

	while (gets(s) != NULL) {
		if (strcmp(s, "!") == 0) {
			break;
		}
		for (int i = 0; s[i]; ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				putchar('a' + 'z' - s[i]);
			} else if (s[i] >= 'A' && s[i] <= 'Z') {
				putchar('A' + 'Z' - s[i]);
			} else {
				putchar(s[i]);
			}
		}
		putchar('\n');
	}

	return 0;
}