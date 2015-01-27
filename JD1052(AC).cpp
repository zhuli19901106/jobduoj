#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 205;
	int a[MAXN];
	int n;
	int i;
	int x;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &x);
		for (i = 0; i < n; ++i) {
			if (a[i] == x) {
				break;
			}
		}
		printf("%d\n", (i < n ? i : -1));
	}

	return 0;
}