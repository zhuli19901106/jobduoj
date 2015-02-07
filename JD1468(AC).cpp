#include <cstdio>
#include <map>
using namespace std;

map<int, int> mm;

int solve(int h1, int h2, int len1, int len2)
{
	if (len1 > len2) {
		return solve(h2, h1, len2, len1);
	}
	int i;
	int p1, p2;

	p2 = h2;
	for (i = len1; i < len2; ++i) {
		p2 = mm[p2];
	}

	p1 = h1;
	while (p1 != -1 && p2 != -1) {
		if (p1 == p2) {
			break;
		}
		p1 = mm[p1];
		p2 = mm[p2];
	}
	if (p1 == -1 || p2 == -1) {
		return -1;
	} else {
		return p1;
	}
}

int main()
{
	int h1, h2;
	int len1, len2;
	int i;
	int n;
	int ptr;
	int x, y;

	while (scanf("%d%d%d", &h1, &h2, &n) == 3) {
		for (i = 0; i < n; ++i) {
			scanf("%d%*s%d", &x, &y);
			mm[x] = y;
		}
		ptr = h1;
		len1 = 0;
		while (ptr != -1) {
			++len1;
			ptr = mm[ptr];
		}
		ptr = h2;
		len2 = 0;
		while (ptr != -1) {
			++len2;
			ptr = mm[ptr];
		}
		int res = solve(h1, h2, len1, len2);
		if (res != -1) {
			printf("%05d\n", res);
		} else {
			printf("-1\n");
		}
		mm.clear();
	}

	return 0;
}