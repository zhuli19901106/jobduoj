#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct st{
	int x, y;
	double r;
}st;

st a[1005];

bool comparator(const st &a, const st &b)
{
	if(a.r != b.r) {
		return a.r < b.r;
	} else {
		return a.y > b.y;
	}
}

char cmd[30], tmp[30];

int main()
{
	int n, k;
	int t, h;
	
	while (scanf("%d", &n) != -1) {
		k = 0;
		while (n--) {
			scanf("%s", cmd);
			if (strcmp(cmd,"Pop") == 0) {
				if (k > 0) {
					--k;
					printf("%d+i%d\nSIZE = %d\n", a[k].x, a[k].y, k);
				} else {
					printf("empty\n");
				}
			} else if(strcmp(cmd, "Insert") == 0) {
				scanf("%s", tmp);
				t = h = 0;
				while(tmp[h] != '+') {
					t = t * 10 + tmp[h] - '0';
					++h;
				}
				a[k].x = t;
				h = h + 2;
				t = 0;
				while (tmp[h]) {
					t = t * 10 + tmp[h] - '0';
					++h;
				}
				a[k].y = t;
				a[k].r = sqrt(a[k].x * a[k].x + a[k].y * a[k].y);
				++k;
				sort(a, a + k, comparator);
				printf("SIZE = %d\n", k);
			}
		}
	}   

	return 0;
}