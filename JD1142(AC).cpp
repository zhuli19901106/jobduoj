#include <cstdio>
using namespace std;

int main()
{
	int n;
	int p, e, i;
	int d;
	int cc;

	cc = 0;
	while (scanf("%d%d%d%d", &p, &e, &i, &d) == 4) {
		if (p == -1 && e == -1 && i == -1 && d == -1) {
			break;
		}
		++cc;
		n = d + 1;
		while (true) {
			if ((n - p) % 23) {
				++n;
				continue;
			}
			if ((n - e) % 28) {
				++n;
				continue;
			}
			if ((n - i) % 33) {
				++n;
				continue;
			}
			break;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", cc, n - d);
	}

	return 0;
}