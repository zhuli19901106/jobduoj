#include <cstdio>
#include <cstring>
using namespace std;

const int N = 50;
int a[91][N];

void add(int a[], int b[], int c[])
{
	int i;
	for (i = 0; i < N; ++i) {
		c[i] = a[i] + b[i];
	}
	for (i = 0; i < N - 1; ++i) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c[i] %= 10;
}

void print(int a[])
{
	int i = N - 1;
	while (i > 0 && a[i] == 0) {
		--i;
	}
	while (i >= 0) {
		putchar(a[i--] + '0');
	}
}

int main()
{
	memset(a, 0, sizeof(a));
	a[0][0] = 1;
	a[1][0] = 1;
	int n;
	for (n = 2; n <= 90; ++n) {
		add(a[n - 2], a[n - 1], a[n]);
	}

	while (scanf("%d", &n) == 1) {
		print(a[n]);
		putchar('\n');
	}

	return 0;
}