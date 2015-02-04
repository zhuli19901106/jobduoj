#include <cstdio>
using namespace std;

int main()
{
	int a[21];
	int i;

	a[0] = a[1] = 1;
	for (i = 2; i <= 20; ++i) {
		a[i] = a[i - 1] + a[i - 2];
	}

	while (scanf("%d", &i) == 1) {
		printf("%d\n", a[i]);
	}

	return 0;
}