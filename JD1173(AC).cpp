#include <cstdio>
#include <set>
using namespace std;

int main()
{
	set<int> s;
	int n;
	int val;
	int m;
	int i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			s.insert(val);
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &val);
			if (s.find(val) != s.end()) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		s.clear();
	}

	return 0;
}