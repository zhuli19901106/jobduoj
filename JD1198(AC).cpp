#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int N = 1005;

void parse(string &s, int a[])
{
	int i;
	int len = s.length();

	memset(a, 0, N * sizeof(int));
	for (i = 0; i < len; ++i) {
		a[i] = s[len - 1 - i] - '0';
	}
}

void add(int a[], int b[], int c[])
{
	int i;

	memset(c, 0, N * sizeof(int));
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
	int i;

	i = N - 1;
	while (i > 0 && a[i] == 0) {
		--i;
	}
	while (i >= 0) {
		putchar(a[i--] + '0');
	}
}

int main()
{
	string str;
	int a[N], b[N], c[N];
	
	while (cin >> str) {
		parse(str, a);
		cin >> str;
		parse(str, b);
		add(a, b, c);
		print(c);
		putchar('\n');
	}

	return 0;
}