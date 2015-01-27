#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a[11];
	int mv, mi;
	int val;
	int i;

	while (scanf("%d", &val) == 1) {
		memset(a, 0, sizeof(a));
		++a[val];
		for (i = 1; i < 20; ++i) {
			scanf("%d", &val);
			++a[val];
		}
		mv = 0;
		for (i = 1; i <= 10; ++i) {
			if (a[i] > mv) {
				mv = a[i];
				mi = i;
			}
		}
		printf("%d\n", mi);
	}

	return 0;
}