// 坑了个爹的，此题无聊
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct st{
	int val;
	int idx;
}st;

bool comp(const st &s1, const st &s2)
{
	if (s1.val != s2.val) {
		return s1.val < s2.val;
	} else {
		return s1.idx > s2.idx;
	}
}

int main()
{
	int t, ti;
	st a[5][4];
	int i, j;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			for (i = 0; i < 4; ++i) {
				for (j = 0; j < 5; ++j) {
					scanf("%d", &a[j][i].val);
					a[j][i].idx = i;
				}
			}
			for (i = 0; i < 5; ++i) {
				sort(a[i], a[i] + 4, comp);
			}
			for (i = 0; i < 5; ++i) {
				if (a[i][3].idx < a[i][2].idx) {
					printf("%d ", a[i][3].val);
				} else {
					printf("%d ", a[i][2].val);
				}
			}
			printf("\n");
			for (i = 0; i < 5; ++i) {
				if (a[i][3].idx > a[i][2].idx) {
					printf("%d ", a[i][3].val);
				} else {
					printf("%d ", a[i][2].val);
				}
			}
			printf("\n");
		}
	}

	return 0;
}