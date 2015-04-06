#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
char s[N];
int next[N];
int len;
int plen;

void getNext()
{
	int i, j;

	memset(next, 0, sizeof(next));

	i = 0;
	j = -1;
	next[0] = -1;
	while (i < len) {
		if (j == -1 || s[i] == s[j]) {
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int main()
{
	int i;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		getNext();
		plen = len - next[len];
		if (len % plen != 0) {
			printf("%s1\n", s);
			continue;
		}
		plen = len / (len / plen);
		for (i = 0; i < plen; ++i) {
			putchar(s[i]);
		}
		printf("%d\n", len / plen);
	}

	return 0;
}