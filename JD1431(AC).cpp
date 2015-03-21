#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n, m;
	int i;

	while (scanf("%d%d", &n, &m) == 2) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		printf("%d", v[n - 1]);
		for (i = n - 2; i > n - 1 - m; --i) {
			printf(" %d", v[i]);
		}
		printf("\n");
		v.clear();
	}

	return 0;
}