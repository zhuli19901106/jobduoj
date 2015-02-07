#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int i;
	
	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		if (n == 1) {
			printf("%d\n-1\n", v[0]);
		} else {
			printf("%d\n", v[n - 1]);
			for (i = 0; i < n - 1; ++i) {
				printf((i ? " %d" : "%d"), v[i]);
			}
			printf("\n");
		}

		v.clear();
	}

	return 0;
}