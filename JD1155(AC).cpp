#include <cstdio>
using namespace std;

int main()
{
	int t, ti;
	int n;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d", &n);
			if (n % 2) {
				printf("0 0\n");
			} else {
				printf("%d %d\n", (n + 2) / 4, n / 2);
			}
		}
	}

	return 0;
}