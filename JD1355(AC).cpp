// 689485	zhuli19901106	1355	Accepted	点击此处查看所有case的执行结果	1024KB	935B	0MS
// 201402030126
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100;
bool check(const vector<int> &vv, int jack)
{
	int i;
	int len = (int)vv.size();

	for (i = 0; i < len - 1; ++i) {
		if (vv[i] == vv[i + 1]) {
			// duplicate cards
			return false;
		} else {
			jack -= (vv[i +1] - vv[i] - 1);
		}
	}
	return jack >= 0;
}

int main()
{
	int jack;
	int n;
	int i;
	int tmp;
	vector<int> vv;

	while (scanf("%d", &n) == 1 && n) { 
		jack = 0;
		vv.clear();
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			if (tmp > 0) {
				vv.push_back(tmp);
			} else {
				++jack;
			}
		}
		sort(vv.begin(), vv.end());
		if (check(vv, jack)) {
			printf("So Lucky!\n");
		} else {
			printf("Oh My God!\n");
		}
	}

	return 0;
}