#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> a, b;
	int n;
	int i;
	int cc;
	
	while (scanf("%d", &n) == 1 && n > 0) {
		a.resize(n);
		b.resize(n);
			
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
			
		cc = 0;
		while (true) {
			for (i = 0; i < n; ++i) {
				if (a[i] != a[(i + 1) % n]) {
					break;
				}
			}
			if (i == n) {
				break;
			}

			for (i = 0; i < n; ++i) {
				b[(i + 1) % n] = a[i] / 2;
			}
			for (i = 0; i < n; i++) {
				a[i] = (a[i] / 2 + b[i] + 1) / 2 * 2;
			}
			++cc;
		}

		printf("%d %d\n", cc, a[0]);
		a.clear();
		b.clear();
	}
	
	return 0;
}