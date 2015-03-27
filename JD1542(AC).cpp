#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

unsigned int m[] = {
	0x00001, 0x00002, 0x00004, 0x00008, 
	0x00010, 0x00020, 0x00040, 0x00080, 
	0x00100, 0x00200, 0x00400, 0x00800, 
	0x01000, 0x02000, 0x04000, 0x08000, 
	0x10000, 0x20000, 0x40000, 0x80000
};
int b[1048576];
int c[1048576];
const int MX = 4;
const int MY = 5;
const unsigned int FIN = (1u << 20) - 1;

unsigned int a[20];
int d[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

void getPos()
{
	int x, y;
	int x1, y1;
	
	int i;
	
	for (x = 0; x < MX; ++x) {
		for (y = 0; y < MY; ++y) {
			a[x * MY + y] = m[x * MY + y];
			for (i = 0; i < 4; ++i) {
				x1 = x + d[i][0];
				y1 = y + d[i][1];
				if (x1 < 0 || x1 > MX - 1) {
					continue;
				}
				if (y1 < 0 || y1 > MY - 1) {
					continue;
				}
				a[x * MY + y] |= m[x1 * MY + y1];
			}
		}
	}
}

void singleBFS(unsigned int st)
{
	int i;
	unsigned int st1;
	queue<unsigned int> q;

	memset(b, 0, 1048576 * sizeof(char));
	q.push(st);
	b[st] = 1;
	while (!q.empty()) {
		st = q.front();
		q.pop();
		for (i = 0; i < MX * MY; ++i) {
			st1 = st ^ a[i];
			if (b[st1]) {
				continue;
			}
			q.push(st1);
			b[st1] = b[st] + 1;
			if (b[FIN]) {
				break;
			}
		}
		if (b[FIN]) {
			break;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	printf("%d\n", b[FIN]);
}

void doubleBFS(unsigned int st)
{
	int i;
	unsigned int st1;
	unsigned int st2;
	int ans;
	queue<unsigned int> q1;
	queue<unsigned int> q2;
	bool suc;

	if (st == FIN) {
		printf("0\n");
		return;
	}

	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	q1.push(st);
	b[st] = 1;
	q2.push(FIN);
	c[FIN] = 1;
	suc = false;
	while (!suc && !q1.empty() && !q2.empty()) {
		st = q1.front();
		q1.pop();
		for (i = 0; i < MX * MY; ++i) {
			st1 = st ^ a[i];
			if (b[st1]) {
				continue;
			}
			q1.push(st1);
			b[st1] = b[st] + 1;
		}
		st = q2.front();
		q2.pop();
		for (i = 0; i < MX * MY; ++i) {
			st2 = st ^ a[i];
			if (c[st2]) {
				continue;
			}
			q2.push(st2);
			c[st2] = c[st] + 1;
			if (b[st2]) {
				ans = b[st2] + c[st2] - 2;
				suc = true;
			}
		}
	}
	while (!q1.empty()) {
		q1.pop();
	}
	while (!q2.empty()) {
		q2.pop();
	}
	printf("%d\n", ans);
}

int main()
{
	int t, ti;

	getPos();

	char s[10];
	int i, j;
	unsigned int st;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		st = 0;
		for (i = 0; i < MX; ++i) {
			scanf("%s", s);
			for (j = 0; j < MY; ++j) {
				if (s[j] == '0') {
					continue;
				}
				st |= m[i * MY + j];
			}
		}
		doubleBFS(st);
	}

	return 0;
}
