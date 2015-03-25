#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;
	int n;
	int i, j;
	int sum;

	while (scanf("%d", &n) == 1) {
		a.resize(n);
		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a.begin(), a.end());
		if (a[0] > 1) {
			printf("1\n");
			a.clear();
			continue;
		}

		b.resize(sum + 1, 0);
		b[0] = 1;
		for (i = 0; i < n; ++i) {
			for (j = sum; j >= a[i]; --j) {
				if (!b[j - a[i]]) {
					continue;
				}
				b[j] = 1;
			}
		}

		for (i = 1; i <= sum; ++i) {
			if (!b[i]) {
				break;
			}
		}

		printf("%d\n", i);
		a.clear();
		b.clear();
	}

	return 0;
}