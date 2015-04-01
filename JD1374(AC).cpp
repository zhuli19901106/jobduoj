#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int val;
	int n, i, j;
	int c[100];

	while (scanf("%d", &n) == 1) {
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			++c[val];
		}
		/*
		for (i = 1; i <= 99; ++i) {
			if (c[i] > 0) {
				--c[i];
				printf("%d", i);
				break;
			}
		}
		*/
		i = 1;
		while (i <= 99) {
			for (j = 0; j < c[i]; ++j) {
				printf("%d ", i);
			}
			++i;
		}
		printf("\n");
	}

	return 0;
}