#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

struct st {
	int x, y;

	st(int _x = 0, int _y = 0): x(_x), y(_y) {}
};

typedef struct lessFunctor{
	bool operator () (const st &s1, const st &s2)
	{
		if (s1.x * s1.y != s2.x * s2.y) {
			return s1.x * s1.y < s2.x * s2.y;
		} else if (s1.x != s2.x) {
			return s1.x < s2.x;
		} else {
			return s1.y < s2.y;
		}
	}
} lessFunctor;

typedef long long int LL;
const int N = 105;
LL a[N][N];
LL s[N][N];
int n, m;
LL k;
set<st, lessFunctor> p;

int main()
{
	int i, j;
	set<st, lessFunctor>::iterator it;
	int r, c;

	while (scanf("%d%d%lld", &n, &m, &k) == 3) {
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				scanf("%lld", &a[i][j]);
				s[i][j] = s[i][j - 1] + s[i - 1][j] + a[i][j] - s[i - 1][j - 1];
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				p.insert(st(i, j));
			}
		}

		bool suc = false;
		LL sum;
		LL res = -1;
		for (it = p.begin(); !suc && it != p.end(); ++it) {
			r = it->x;
			c = it->y;
			for (i = 1; !suc && i + r - 1 <= n; ++i) {
				for (j = 1; !suc && j + c - 1 <= m; ++j) {
					sum = s[i + r - 1][j + c - 1] - s[i - 1][j + c - 1] - s[i + r - 1][j - 1] + s[i - 1][j - 1];
					if (sum >= k) {
						suc = true;
						res = r * c;
					}
				}
			}
		}
		printf("%lld\n", res);
		p.clear();
	}

	return 0;
}