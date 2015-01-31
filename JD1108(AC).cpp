#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	char s[5];
	int val;
	stack<int> st;
	int i, n;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			if (s[0] == 'O') {
				if (!st.empty()) {
					st.pop();
				}
			} else if (s[0] == 'A') {
				if (st.empty()) {
					printf("E\n");
				} else {
					printf("%d\n", st.top());
				}
			} else if (s[0] == 'P') {
				scanf("%d", &val);
				st.push(val);
			}
		}
		printf("\n");
		while (!st.empty()) {
			st.pop();
		}
	}

	return 0;
}