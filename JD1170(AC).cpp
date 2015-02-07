#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st{
	int x, y;
}st;

bool comparator(const st &s1, const st &s2)
{
	if (s1.x != s2.x) {
		return s1.x < s2.x;
	} else {
		return s1.y < s2.y;
	}
}

int main()
{
	int n, i;
	st val, minVal;

	while (scanf("%d", &n) == 1) {
		minVal.x = minVal.y = INT_MAX;
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &val.x, &val.y);
			if (comparator(val, minVal)) {
				minVal = val;
			}
		}
		printf("%d %d\n", minVal.x, minVal.y);
	}

	return 0;
}