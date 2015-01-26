#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> a, b;
	int n, m;
	int i, j;
	int k;
	int res;
	
	while (scanf("%d", &n) == 1) {
		a.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}

		scanf("%d", &m);
		b.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &b[i]);
		}
		k = (n + m - 1) / 2;
		i = j = 0;
		while (k >= 0) {
			if (i >= n) {
				res = b[j++];
			} else if (j >= m) {
				res = a[i++];
			} else if (a[i] < b[j]) {
				res = a[i++];
			} else {
				res = b[j++];
			}
			--k;
		}
		printf("%d\n", res);
		a.clear();
		b.clear();
	}

	return 0;
}