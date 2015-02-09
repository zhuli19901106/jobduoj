#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[1005];
	int len, i;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		for (i = 0; i < len - 1 - i; ++i) {
			if (s[i] != s[len - 1 - i]) {
				break;
			}
		}
		printf(i >= len - 1 - i ? "Yes!\n" : "No!\n");
	}

	return 0;
}