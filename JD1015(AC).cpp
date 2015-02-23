#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	int k;
	int d;
	int i;

	while (scanf("%d%d%d", &a, &b, &k) == 3) {
		if (a == 0 && b == 0) {
			break;
		}
		d = 1;
		for (i = 0; i < k; ++i) {
			d *= 10;
		}
		if (a % d == b % d) {
			printf("-1\n");
		} else {
			printf("%d\n", a + b);
		}
	}

	return 0;
}