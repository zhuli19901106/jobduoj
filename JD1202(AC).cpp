#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n, i;
	vector<int> v;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		for (i = 0; i < n; ++i) {
			printf("%d ", v[i]);
		}
		printf("\n");
		v.clear();
	}

	return 0;
}