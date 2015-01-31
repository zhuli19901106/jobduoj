#include <cstdio>
using namespace std;

int sum(int x)
{
	int s = 0;
	while (x != 0) {
		s += x % 10;
		x /= 10;
	}

	return s;
}

int main()
{
	int x;

	while (scanf("%d", &x) == 1 && x) {
		printf("%d %d\n", sum(x), sum(x * x));
	}

	return 0;
}