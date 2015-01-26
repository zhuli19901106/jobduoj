#include <cstdio>
using namespace std;

int sum(int n)
{
	if (n <= 0) {
		return 0;
	} else {
		return n * (n + 1) / 2;
	}
}

int main()
{
	int n;

	while (scanf("%d", &n) == 1) {
		if (n >= 0) {
			printf("%d\n", sum(2 * n) - sum(n - 1));
		} else {
			printf("%d\n", sum(-n - 1) - sum(-2 * n));
		}
	}

	return 0;
}