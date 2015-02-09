#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	int p;
	vector<int> v;
	int i;
	bool first;

	while (scanf("%d%d", &n, &p) == 2) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			v[i] = i;
		}
		i = 0;
		first = true;
		while (n > 0) {
			i = (i + p - 1) % n;
			if (first) {
				printf("%d", v[i] + 1);
				first = false;
			} else {
				printf(" %d", v[i] + 1);
			}
			v.erase(v.begin() + i);
			if (i == n - 1) {
				i = 0;
			}
			--n;
		}
		printf("\n");
	}

	return 0;
}