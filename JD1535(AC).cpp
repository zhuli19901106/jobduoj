// A good application of KMP.
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000005;
char s[N], p[N];
int next[N];
int ls, lp;
int len;
int ans;

void getNext()
{
	int i, j;

	i = 0;
	j = -1;
	next[0] = -1;
	while (i < len) {
		if (j == -1 || p[i] == p[j]) {
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

int match(char s[], char p[])
{
	int clen;
	int i, j;

	clen = len;
	i = j = 0;
	while (i < len) {
		if (j == -1) {
			--clen;
			++i;
			++j;
		} else if (s[i] == p[j]) {
			++i;
			++j;
		} else {
			if (next[j] != -1) {
				clen = len - (i - next[j]);
			}
			j = next[j];
		}
	}

	return clen;
}

int main()
{
	while (scanf("%s%s", s, p) == 2) {
		ls = strlen(s);
		lp = strlen(p);
		if (ls > lp) {
			len = lp;
			ans = match(s + ls - lp, p);
		} else {
			len = ls;
			p[len] = 0;
			getNext();
			ans = match(s, p);
		}
		printf("%d\n", ans);
	}

	return 0;
}