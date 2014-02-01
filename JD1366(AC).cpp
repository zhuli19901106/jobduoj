// 688864	zhuli19901106	1366	Accepted	点击此处查看所有case的执行结果	6504KB	916B	640MS
// 201402012335
#include <cstdio>
#include <map>
#include <stack>
using namespace std;

map<int, int> m2;
stack<int> st;
const int MAXN = 100005;
int a[MAXN];

int main()
{
	int i, j, n;
	int tmp;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			m2[tmp] = i;
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			a[i] = m2[tmp];
		}

		i = j = 0;
		while (j < n) {
			if (a[j] == i) {
				++i;
				++j;
			} else if (!st.empty() && st.top() == a[j]) {
				st.pop();
				++j;
			} else if (i < n) {
				st.push(i);
				++i;
			} else {
				break;
			}
		}
		if (i == n && j == n && st.empty()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

		while (!st.empty()) {
			st.pop();
		}
		m2.clear();
	}

	return 0;
}