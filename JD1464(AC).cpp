#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 2000;
char str[MAXN];
char m[1000][1000];
int r, c;

int main()
{
	int len;
	int i, j;
	
	while (scanf("%s", str) == 1) {
		len = strlen(str);
		if (len >= MAXN) {
			while (true);
		}
		r = (len + 2) / 3;
		c = (len + 2) - 2 * r;
		memset(m, ' ', sizeof(m));

		for (i = 0; i < r; ++i) {
			m[i][c] = 0;
		}
		j = 0;
		for (i = 0; i <= r - 1; ++i) {
			m[i][0] = str[j++];
		}
		for (i = 1; i <= c - 2; ++i) {
			m[r - 1][i] = str[j++];
		}
		for (i = r - 1; i >= 0; --i) {
			m[i][c - 1] = str[j++];
		}
		for (i = 0; i < r; ++i) {
			puts(m[i]);
		}
	}

	return 0;
}