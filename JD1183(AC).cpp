#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	char s[50];
	int len;
	int i;

	while (scanf("%d", &n) == 1) {
		sprintf(s, "%d", n);
		len = strlen(s);
		n = n * n - n;
		for (i = 0; i < len; ++i) {
			if (n % 10) {
				break;
			} else {
				n /= 10;
			}
		}
		if (i == len) {
			printf("Yes!\n");
		} else {
			printf("No!\n");
		}
	}

	return 0;
}