#include <cstdio>
using namespace std;

typedef long long int ll;

ll expmod(ll x, ll y, ll k)
{
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % k;
		}
		x = x * x % k;
		y >>= 1;
	}

	return res;
}

int main()
{
	ll x, y, k;
	ll res;

	while (scanf("%lld%lld%lld", &x, &y, &k) == 3) {
		res = expmod(x, y, k - 1);
		if (res == 0) {
			res = k - 1;
		}
		printf("%lld\n", res);
	}

	return 0;
}