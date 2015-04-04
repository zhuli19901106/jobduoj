#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main()
{
	int i, j;
	int a[1005];
	int ac;
	set<int> s;
	int n;
	int ans;

	while (scanf("%d", &n) == 1) {
		ac = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &j);
			if (s.find(j) == s.end()) {
				s.insert(j);
				a[ac++] = j;
			}
		}
		ans = 4;
		sort(a, a + ac);
		for (i = 0; i < ac; ++i) {
			j = i + 1;
			while (j <= ac - 1 && a[j] > a[j - 1] && a[j] <= a[i] + 4) {
				++j;
			}
			--j;
			ans = min(ans, 4 - j + i);
		}
		printf("%d\n", ans);

		s.clear();
	}

	return 0;
}