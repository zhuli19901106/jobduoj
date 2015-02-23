#include <cstdio>
using namespace std;

int b[26];
int dj[26];
int n, m;

bool check(int xx, int yy, int &dif)
{
	int x, y;
	int c;

	c = 0;
	x = xx;
	while (x != dj[x]) {
		++c;
		if (dj[x] == yy) {
			break;
		} else {
			x = dj[x];
		}
	}
	if (x != dj[x]) {
		dif = -c;
		return true;
	}

	c = 0;
	y = yy;
	while (y != dj[y]) {
		++c;
		if (dj[y] == xx) {
			break;
		} else {
			y = dj[y];
		}
	}
	if (y != dj[y]) {
		dif = c;
		return true;
	}

	return false;
}

int main()
{
	int x, y, z;
	int i, j;
	char s[10];
	int dif;

	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		for (i = 0; i < 26; ++i) {
			b[i] = 0;
			dj[i] = i;
		}
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			x = s[0] - 'A';
			b[x] = 1;
			if (s[1] != '-') {
				y = s[1] - 'A';
				b[y] = 1;
				dj[y] = x;
			}
			if (s[2] != '-') {
				z = s[2] - 'A';
				b[z] = 1;
				dj[z] = x;
			}
		}
		for (i = 0; i < m; ++i) {
			scanf("%s", s);
			if (s[0] == s[1]) {
				printf("-\n");
				continue;
			}
			x = s[0] - 'A';
			y = s[1] - 'A';
			if (!b[x] || !b[y]) {
				printf("-\n");
				continue;
			}
			if (check(x, y, dif)) {
				if (dif < 0) {
					dif = -dif;
					for (j = 0; j < dif - 2; ++j) {
						printf("great-");
					}
					if (dif == 1) {
						printf("parent\n");
					} else {
						printf("grandparent\n");
					}
				} else {
					for (j = 0; j < dif - 2; ++j) {
						printf("great-");
					}
					if (dif == 1) {
						printf("child\n");
					} else {
						printf("grandchild\n");
					}
				}
			} else {
				printf("-\n");
			}
		}
	}

	return 0;
}