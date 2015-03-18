#include <cstdio>
using namespace std;

typedef long long int LL;
const LL MOD = 200907;

LL mypow(LL x, LL y, LL mod)
{
	if (y == 0) {
		return 1 % mod;
	} else if (y == 1) {
		return x % mod;
	} else {
		LL res = mypow(x, y / 2, mod);
		res = res * res % mod;
		return y % 2 ? res * x % mod : res;
	}
}

int main()
{
	LL x, y, z;
	LL k;
	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld%lld%lld", &x, &y, &z, &k);
		if (y - x == z - y) {
			printf("%lld\n", (x + (y - x) * (k - 1)) % MOD);
		} else {
			printf("%lld\n", x * mypow(y / x, k - 1, MOD) % MOD);
		}
	}

	return 0;
}