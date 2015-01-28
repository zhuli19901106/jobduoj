#include <cstdio>
#include <set>
using namespace std;

int main()
{
	bool firstOne;
	set<int> st;
	set<int>::iterator it;
	int n, val;
	int i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			st.insert(val);
		}
		firstOne = true;
		for (it = st.begin(); it != st.end(); ++it) {
			if (firstOne) {
				printf("%d", *it);
				firstOne = false;
			} else {
				printf(" %d", *it);
			}
		}
		printf("\n");
		st.clear();
	}

	return 0;
}