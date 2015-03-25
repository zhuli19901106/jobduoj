#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 5005;
vector<int> v;
int a[N];
int n, c1, c2;
int sum;

int main()
{
	int i, j;

	while (scanf("%d%d%d", &n, &c1, &c2) == 3) {
		if (c1 > c2) {
			swap(c1, c2);
		}

		v.resize(n);
		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			sum += v[i];
		}
		if (sum > c1 + c2) {
			printf("NO\n");
			v.clear();
			continue;
		}

		memset(a, 0, sizeof(a));
		a[0] = 1;
		for (i = 0; i < n; ++i) {
			for (j = c1; j >= v[i]; --j) {
				if (!a[j - v[i]]) {
					continue;
				}
				a[j] = 1;
			}
		}
		for (i = sum - c2; i <= c1; ++i) {
			if (a[i]) {
				break;
			}
		}
		printf(i <= c1 ? "YES\n" : "NO\n");
		
		v.clear();
	}

	return 0;
}