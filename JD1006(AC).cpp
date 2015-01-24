#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[10005];
	int zp, jp;
	int zc, jc;
	int a, b, c;
	int i;
	int len;
	
	while (scanf("%s", s) == 1) {
		len = strlen(s);

		zp = jp = -1;
		zc = jc = 0;
		for (i = 0; i < len; ++i) {
			if (s[i] == 'z') {
				zp = i;
				++zc;
			} else if (s[i] == 'j') {
				jp = i;
				++jc;
			}
		}
		if (zc != 1 || jc != 1 || zc > jc) {
			goto ERROR;
		}

		a = zp;
		b = jp - zp - 1;
		c = len - 1 - jp;

		if (b < 1) {
			goto ERROR;
		} else if (b == 1 && a != c) {
			goto ERROR;
		} else if (c != a * b) {
			goto ERROR;
		}

		printf("Accepted\n");
		continue;
ERROR:
		printf("Wrong Answer\n");
	}

	return 0;
}