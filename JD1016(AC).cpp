#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 30;
int p[N] = {
	2, 3, 5, 7, 11, 
	13, 17, 19, 23, 29, 
	31, 37, 41, 43, 47, 
	53, 59, 61, 67, 71, 
	73, 79, 83, 89, 97, 
	101, 103, 107, 109, 113
};

void parse(char s[], int a[N])
{
	int len = strlen(s);
	int i;
	vector<int> v;
	int val;

	memset(a, 0, N * sizeof(int));
	i = 0;
	while (i < len) {
		sscanf(s + i, "%d", &val);
		v.push_back(val);
		while (s[i] && s[i] != ',') {
			++i;
		}
		++i;
	}
	reverse(v.begin(), v.end());
	len = v.size();
	for (i = 0; i < len; ++i) {
		a[i] = v[i];
	}
	v.clear();
}

void add(int a[N], int b[N], int c[N])
{
	int i;

	memset(c, 0, N * sizeof(int));
	for (i = 0; i < N; ++i) {
		c[i] = a[i] + b[i];
	}
	for (i = 0; i < N - 1; ++i) {
		c[i + 1] += c[i] / p[i];
		c[i] %= p[i];
	}
	c[i] %= p[i];
}

void print(int a[N])
{
	int i = N - 1;

	while (i > 0 && a[i] == 0) {
		--i;
	}
	while (i > 0) {
		printf("%d,", a[i--]);
	}
	printf("%d", a[i]);
}

int main()
{
	char sa[1000], sb[1000];
	int a[N], b[N];
	int c[N];

	while (scanf("%s%s", sa, sb) == 2) {
		if (strcmp(sa, "0") == 0 && strcmp(sb, "0") == 0) {
			break;
		}
		parse(sa, a);
		parse(sb, b);
		add(a, b, c);
		print(c);
		putchar('\n');
	}

	return 0;
}