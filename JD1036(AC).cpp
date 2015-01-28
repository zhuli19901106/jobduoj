#include <cstdio>
using namespace std;

int main()
{
	int n, x, y, z;
	int p, q;
	bool suc;
	int val;

	while (scanf("%d", &n) == 1) {
		scanf("%d%d%d", &x, &y, &z);
		suc = false;
		for (p = 9; p >= 1; --p) {
			for (q = 9; q >= 0; --q) {
				val = (((p * 10 + x) * 10 + y) * 10 + z) * 10 + q;
				if (val % n == 0) {
					suc = true;
				}
				if (suc) {
					break;
				}
			}
			if (suc) {
				break;
			}
		}
		if (suc) {
			printf("%d %d %d\n", p, q, val / n);
		} else {
			printf("0\n");
		}
	}

	return 0;
}