#include <cstdio>
using namespace std;

int main()
{
	int i, n;
	int val;
	int odd;

	while (scanf("%d", &n) == 1) {
		odd = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			if (val % 2) {
				++odd;
			}
		}
		printf(n - odd > odd ? "NO\n" : "YES\n");
	}

	return 0;
}