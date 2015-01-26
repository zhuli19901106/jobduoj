#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int key[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
	int press[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	char s[105];
	int len;
	int i;
	int sum;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		for (i = 0; i < len; ++i) {
			s[i] -= 'a';
		}
		if (len == 0) {
			printf("0\n");
			continue;
		}
		sum = press[s[0]];
		for (i = 1; i < len; ++i) {
			sum += press[s[i]];
			if (key[s[i - 1]] == key[s[i]]) {
				sum += 2;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}