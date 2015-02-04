#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;

int ctod(char c)
{
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 10;
	} else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	return 0;
}

char  dtoc(int d)
{
	if (d >= 0 && d <= 9) {
		return d + '0';
	} else if (d >= 10 && d <= 35) {
		return d - 10 + 'A';
	}
	return 0;
}

int main()
{
	int ra, rb;
	LL val;
	char s[100];
	int len;
	int i;

	while (scanf("%d%s%d", &ra, s, &rb) == 3) {
		len = strlen(s);
		i = 0;
		while (i < len && s[i] == '0') {
			++i;
		}
		val = 0;
		while (i < len) {
			val = val * ra + ctod(s[i]);
			++i;
		}
		if (val == 0) {
			printf("0\n");
			continue;
		}
		i = 0;
		while (val) {
			s[i] = dtoc(val % rb);
			val /= rb;
			++i;
		}
		s[len = i] = 0;
		reverse(s, s + len);
		puts(s);
	}

	return 0;
}