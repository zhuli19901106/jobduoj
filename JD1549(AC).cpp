#include <cstdio>
using namespace std;

int main()
{
	int a[7] = {100, 50, 20, 10, 5, 2, 1};
	int c;
	int i;
	int p;

	while (scanf("%d", &p) == 1) {
		c = 0;
		for (i = 0; i <= 6; ++i) {
			c += p / a[i];
			p %= a[i];
		}
		printf("%d\n", c);
	}

	return 0;
}