#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

void parse(char s[], int a[])
{
	int i, len;
	int dp;

	len = strlen(s);
	for (dp = 0; dp < len; ++dp) {
		if (s[dp] == '.') {
			break;
		}
	}
	memset(a, 0, 2 * N * sizeof(int));
	for (i = 0; i < dp; ++i) {
		a[N + i] = s[dp - 1 - i] - '0';
	}
	for (i = dp + 1; i < len; ++i) {
		a[dp + N - i] = s[i] - '0';
	}
}

void print(int a[])
{
	int i = 0;
	while (i < N && a[i] == 0) {
		++i;
	}
	if (i == N) {
		// It's an integer.
		i = 2 * N - 1;
		while (i > N && a[i] == 0) {
			--i;
		}
		while (i >= N) {
			putchar(a[i] + '0');
			--i;
		}
	} else {
		int j = i;

		i = 2 * N - 1;
		while (i > N && a[i] == 0) {
			--i;
		}
		while (i >= N) {
			putchar(a[i] + '0');
			--i;
		}
		putchar('.');
		while (i >= j) {
			putchar(a[i] + '0');
			--i;
		}
	}
}

void add(int a[], int b[], int c[])
{
	int i;

	for (i = 0; i < 2 * N; ++i) {
		c[i] = a[i] + b[i];
	}
	for (i = 0; i < 2 * N - 1; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c[i] %= 10;
}

int main()
{
	char s[300];
	int t, ti;
	int a[2 * N];
	int b[2 * N];
	int c[2 * N];

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%s", s);
			parse(s, a);
			scanf("%s", s);
			parse(s, b);
			add(a, b, c);
			print(c);
			putchar('\n');
		}
	}

	return 0;
}