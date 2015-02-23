#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a[101];
	int n, i, val;

	while (scanf("%d", &n) == 1 && n) {
		memset(a, 0, sizeof(a));
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			++a[val];
		}
		scanf("%d", &val);
		if (val < 0 || val > 100) {
			printf("0\n");
		} else {
			printf("%d\n", a[val]);
		}
	}

	return 0;
}