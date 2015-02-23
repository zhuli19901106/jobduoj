#include <cstdio>
using namespace std;

int main()
{
	int n;
	int c;

	while (scanf("%d", &n) == 1 && n) {
		c = 0;
		while (n != 1) {
			if (n % 2) {
				n = (3 * n + 1) / 2;
			} else {
				n = n / 2;
			}
			++c;
		}
		printf("%d\n", c);
	}

	return 0;
}