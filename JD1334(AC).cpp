#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;
int a[N * N];
int b[N];
int ll[N];
int rr[N];
int n, m, p;


int main()
{
	int i, j, k;
	char s[10];
	int id, num;

	while (scanf("%d%d", &n, &m) == 2) {
		scanf("%d", &p);
		memset(a, -1, sizeof(a));
		memset(ll, -1, sizeof(ll));
		memset(rr, -1, sizeof(rr));
		memset(b, 0, sizeof(b));
		for (i = 1; i <= p; ++i) {
			scanf("%s", s);
			if (strcmp(s, "in") == 0) {
				scanf("%d%d", &id, &num);
				if (b[id]) {
					puts("no");
					continue;
				}
				j = 1;
				while (j <= n * n) {
					while (j <= n * n && a[j] >= 0) {
						++j;
					}
					if (j > n * n) {
						break;
					}
					k = j;
					while (k <= n * n && a[k] == -1) {
						++k;
					}
					if (k - j >= num) {
						ll[id] = j;
						rr[id] = j + num - 1;
						b[id] = 1;
						for (k = j; k < j + num; ++k) {
							a[k] = id;
						}
						puts("yes");
						break;
					}
					j = k;
				}
				if (j > n * n) {
					puts("no");
				}
			} else if (strcmp(s, "out") == 0) {
				scanf("%d", &id);
				if (!b[id]) {
					continue;
				}
				for (j = ll[id]; j <= rr[id]; ++j) {
					a[j] = -1;
				}
				ll[id] = rr[id] = -1;
				b[id] = 0;
			}
		}
	}

	return 0;
}