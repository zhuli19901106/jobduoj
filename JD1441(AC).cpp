#include <cstdio>
using namespace std;

int mypow(int x, int y, int mod)
{
	if (y == 0) {
		return 1 % mod;
	} else if (y == 1) {
		return x % mod;
	} else {
		int res = mypow(x, y / 2, mod);
		res = res * res % mod;
		return y % 2 ? res * x % mod : res;
	}
}

int main()
{
	int x, y;

	while (scanf("%d%d", &x, &y) == 2 && (x || y)) {
		printf("%d\n", mypow(x, y, 1000));
	}

	return 0;
}