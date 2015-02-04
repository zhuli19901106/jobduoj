#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[10];
	int n;
	int f;
	int i;

	while (scanf("%s", s) == 1) {
		n = strlen(s);
		sort(s, s + n);
		f = 1;
		for (i = 2; i <= n; ++i) {
			f *= i;
		}
		for (i = 0; i < f; ++i) {
			puts(s);
			next_permutation(s, s + n);
		}
		putchar('\n');
	}

	return 0;
}