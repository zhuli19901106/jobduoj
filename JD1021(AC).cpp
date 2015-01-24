#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int c[256];
	int i;
	char s[1000];
	char t[256];

	while (gets(t) != NULL) {
		if (strcmp(t, "#") == 0) {
			break;
		}

		gets(s);
		memset(c, 0, 256 * sizeof(int));
		for (i = 0; s[i]; ++i) {
			++c[s[i]];
		}

		for (i = 0; t[i]; ++i) {
			printf("%c %d\n", t[i], c[t[i]]);
		}
	}

	return 0;
}