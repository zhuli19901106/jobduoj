#include <cstdio>
using namespace std;

int main()
{
	int n;
	int i, j;
	
	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < 2 * (n - 1 - i); ++j) {
				putchar(' ');
			}
			for (j = 0; j < n + 2 * i; ++j) {
				putchar('*');
			}
			putchar('\n');
		}
	}
	
	return 0;
}