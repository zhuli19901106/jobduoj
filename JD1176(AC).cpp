#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int n, i;
	int d;
	int j;

	while (scanf("%d", &n) == 1) {
		v.resize(n + 1);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &v[i]);
		}
		scanf("%d", &d);
		j = 1;
		for (i = 1; i < d; ++i) {
			j *= 2;
		}
		for (i = j; i <= n && i < 2 * j; ++i) {
			printf((i == j ? "%d" : " %d"), v[i]);
		}
		printf("\n");
		v.clear();
	}

	return 0;
}