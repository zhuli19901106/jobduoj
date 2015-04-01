#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	typedef long long int LL;
	LL n;
	LL rt;

	while (scanf("%lld", &n) == 1) {
		n *= 2;
		rt = sqrt(1.0 * n);
		if (rt * (rt + 1) < n) {
			++rt;
		}
		printf("%d\n", rt);
	}

	return 0;
}