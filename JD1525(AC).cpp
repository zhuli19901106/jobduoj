#include <cstdio>
#include <cstring>
using namespace std;

char s[100005];
int len;
int n;

int main()
{
	int t, ti;
	int i, j;
	int k;

	while (gets(s) != NULL) {
		if (sscanf(s, "%d", &n) != 1 || n == 0) {
			break;
		}
		gets(s);
		len = strlen(s);
		i = 0;
		while (i < len) {
			j = i;
			while (j < len && s[j] == ' ') {
				++j;
			}
			if (j > i) {
				putchar(' ');
			}
			i = j;
			while (j < len && s[j] != ' ') {
				++j;
			}
			for (k = j - 1; k >= i; --k) {
				putchar(s[k]);
			}
			i = j;
		}
		putchar('\n');
	}

	return 0;
}