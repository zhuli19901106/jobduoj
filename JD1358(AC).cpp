#include <cstdio>
#include <cstring>
using namespace std;

int a[15];
int ac;
int b[60];

bool check(int n)
{
	int sum = 0;
	int d;

	ac = 0;
	while (n) {
		d = n % 10;
		if (d) {
			a[ac++] = d;
			sum += d;
		}
		n /= 10;
	}

	if (sum % 2) {
		return false;
	}

	sum /= 2;
	memset(b, 0, sizeof(b));
	b[0] = 1;

	int i, j;
	for (i = 0; i < ac; ++i) {
		for (j = sum; j >= a[i]; --j) {
			if (b[j - a[i]]) {
				b[j] = 1;
			}
		}
	}

	return b[sum] != 0;
}

int main()
{
	int x, y;
	int i;
	int ans;

	while (scanf("%d%d", &x, &y) == 2) {
		ans = 0;
		for (i = x; i <= y; ++i) {
			if (check(i)) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}