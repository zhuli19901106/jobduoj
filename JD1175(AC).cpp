#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int c[10];
	int st[10];
	const int SIZE = 10 * sizeof(int);
	char s[100];
	int len;
	int i, j;

	while (scanf("%s", s) == 1) {
		memset(c, 0, SIZE);
		memset(st, 0, SIZE);

		len = strlen(s);
		for (i = 0; i < len; ++i) {
			++c[s[i] - '0'];
		}
		for (i = 1; i <= 9; ++i) {
			for (j = i; j < 10 && c[j] > 0; ++j) {}
			st[i] = j - i;
		}
		scanf("%s", s);
		len = strlen(s);
		if (len < 5) {
			for (i = s[0] - '0' + 1; i <= 9; ++i) {
				if (c[i] >= len) {
					break;
				}
			}
			if (i <= 9) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			for (i = s[0] - '0' + 1; i <= 9; ++i) {
				if (st[i] >= len) {
					break;
				}
			}
			if (i <= 9) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}