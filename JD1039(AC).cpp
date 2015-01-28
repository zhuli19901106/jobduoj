#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int i;
	int n;
	vector<long long int> v;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &v[i]);
		}
		reverse(v.begin(), v.end());
		for (i = 0; i < n; ++i) {
			printf((i ? " %lld" : "%lld"), v[i]);
		}
		printf("\n");
		v.clear();
	}

	return 0;
}