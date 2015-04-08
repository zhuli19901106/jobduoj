#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000000;
char c[N + 1];
int n;
int cc;

int main()
{	
	int i;
	int val;

	while (scanf("%d", &n) == 1) {
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			if (c[val] == 0) {
				c[val] = 1;
			} else if (c[val] == 1) {
				c[val] = -1;
			}
		}

		cc = 0;
		for (i = 1; i <= N; ++i) {
			if (c[i] == 1) {
				++cc;
			}
		}

		if (cc == 0) {
			printf("0\n");
			continue;
		}

		printf("%d\n", cc);

		i = 1;
		while (i <= N && c[i] != 1) {
			++i;
		}
		printf("%d", i++);
		while (i <= N) {
			if (c[i] == 1) {
				printf(" %d", i);
			}
			++i;
		}
		printf("\n");
	}

	return 0;
}