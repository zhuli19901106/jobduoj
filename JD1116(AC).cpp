#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int f;
	char s[10];

	while (scanf("%d", &x) == 1) {
		scanf("%1s", s);
		if (s[0] == '!') {
			f = 1;
			for (y = 2; y <= x; ++y) {
				f *= y;
			}
			printf("%d\n", f);
			continue;
		}
		scanf("%d", &y);
		if (s[0] == '/') {
			if (y) {
				printf("%d\n", x / y);
			} else {
				printf("error\n");
			}
		} else if (s[0] == '%') {
			if (y) {
				printf("%d\n", x % y);
			} else {
				printf("error\n");
			}
		} else if (s[0] == '+') {
			printf("%d\n", x + y);
		} else if (s[0] == '-') {
			printf("%d\n", x - y);
		} else if (s[0] == '*') {
			printf("%d\n", x * y);
		}
	}

	return 0;
}