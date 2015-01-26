#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a[189];

	memset(a, 0, sizeof(a));
	int i, j, k;
	int cc;

	cc = 0;
	for (i = 0; i <= 5; ++i) {
		for (j = 0; j <= 4; ++j) {
			for (k = 0; k <= 6; ++k) {
				if (a[8 * i + 10 * j + 18 * k] == 0) {
					a[8 * i + 10 * j + 18 * k] = 1;
					++cc;
				}
			}
		}
	}
	printf("%d\n", cc - 1);

	return 0;
}