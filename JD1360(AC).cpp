// 689492	zhuli19901106	1360	Accepted	点击此处查看所有case的执行结果	1024KB	1230B	10MS
// 201402030320
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct st{
public:
	int x;
	int y;
	st(int _x = 0, int _y = 0): x(_x), y(_y) {};
}st;

bool comparator(const st &a, const st &b)
{
	if (a.y == b.y) {
		return a.x < b.x;
	} else {
		return a.y > b.y;
	}
}

int main()
{
	int n, m;
	int i, j, k;
	int sum;
	int a[11][81];
	vector<st> v;
	int cc;

	cc = 0;
	while (scanf("%d", &n) == 1 && n) {
		scanf("%d", &m);
		if (cc > 0) {
			printf("\n");
		}
		++cc;
		memset(a, 0, 11 * 81 * sizeof(int));
		for (i = 1; i <= m; ++i) {
			a[1][i] = 1;
		}
		sum = m;
		for (i = 2; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				for (k = i - 1; k <= (i - 1) * m; ++k) {
					a[i][k + j] += a[i - 1][k];
				}
			}
			sum *= m;
		}

		for (i = n; i <= n * m; ++i) {
			v.push_back(st(i, (int)(100.0 * a[n][i] / sum + 0.5)));
		}
		
		sort(v.begin(), v.end(), comparator);

		for (i = 0; i < 3; ++i) {
			printf("%d %.2f\n", v[i].x, v[i].y / 100.0);
		}
		v.clear();
	}

	return 0;
}