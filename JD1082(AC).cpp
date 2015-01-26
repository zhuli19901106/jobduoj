#include <climits>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int n, m;
	unsigned ip;
	unsigned a, b, c, d;
	int i;
	map<unsigned, int> mm;
	map<unsigned, int>::iterator it;
	int cc;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			ip = (a << 24) + (b << 16) + (c << 8) + d;
			mm[ip] = 0;
		}
		scanf("%d", &m);
		for (i = 0; i < m; ++i) {
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			ip = (a << 24) + (b << 16) + (c << 8) + d;
			it = mm.find(ip);
			if (it != mm.end()) {
				++it->second;
			}
		}

		cc = INT_MAX;
		for (it = mm.begin(); it != mm.end(); ++it) {
			if (it->second < cc) {
				cc = it->second;
			}
		}
		if (cc > 0 && n == 1) {
			printf("-1\n");
		} else {
			printf("%d\n", cc);
		}
		mm.clear();
	}

	return 0;
}