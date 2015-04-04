#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000005;
int n;
int a[N], b[N];


int main()
{
	int i, j;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		i = j = 0;
		printf("%d", a[i] < b[j] ? a[i++] : b[j++]);
		while (i < n && j < n) {
			printf(" %d", a[i] < b[j] ? a[i++] : b[j++]);
		}
		while (i < n) {
			printf(" %d", a[i++]);
		}
		while (j < n) {
			printf(" %d", b[j++]);
		}
		printf("\n");
	}

	return 0;
}