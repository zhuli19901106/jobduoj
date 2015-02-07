#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int n;
	int i;
	int val;
	set<int> s;
	set<int>::iterator it;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			s.insert(val);
		}
		scanf("%d", &n);
		--n;
		for (it = s.begin(); it != s.end(); ++it) {
			if (n > 0) {
				--n;
			} else {
				break;
			}
		}
		printf("%d\n", *it);
		s.clear();
	}

	return 0;
}