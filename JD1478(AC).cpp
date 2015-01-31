#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int a[3];

	while (scanf("%d", &a[0]) == 1 && a[0]) {
		scanf("%d%d", &a[1], &a[2]);
		sort(a, a + 3);
		printf("%d\n", a[0] + a[1] - a[2]);
	}

	return 0;
}