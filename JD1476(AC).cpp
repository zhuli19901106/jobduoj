#include <cstdio>
using namespace std;

int main()
{
	int n;
	int i;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 2; i * i <= n; ++i) {
			if (n % (i * i) == 0) {
				break;
			}
		}
		if (i * i <= n) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}