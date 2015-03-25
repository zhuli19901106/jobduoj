#include <cstdio>
#include <cstring>
using namespace std;

const int N = 101;
int a[N + 1];
int b[N + 1];
const int MOD = 20123;

void count()
{
	int i;
	int p;
	
	a[0] = 0;
	p = 1;
	for (i = 1; i <= N; ++i) {
		a[i] = (a[i - 1] * 10 + p) % MOD;
		p = p * 10 % MOD;
	}

	b[0] = 1;
	for (i = 1; i <= N; ++i) {
		b[i] = b[i - 1] * 10 % MOD;
	}
}

int f(char s[], int d)
{
	int len = strlen(s);
	int i, j;
	int sum;
	int p;

	sum = 0;
	for (i = 0; i < len; ++i) {
		sum = (sum + a[len - 1 - i] * (s[i] - '0')) % MOD;
		if (s[i] - '0' > d) {
			sum = (sum + b[len - 1 - i]) % MOD;
		} else if (s[i] - '0' == d) {
			p = 0;
			for (j = i + 1; j < len; ++j) {
				p = (p * 10 + (s[j] - '0')) % MOD;
			}
			p = (p + 1) % MOD;
			sum = (sum + p) % MOD;
		}
	}

	return sum;
}

int main()
{
	char s[1000];

	count();
	while (scanf("%s", s) == 1) {
		printf("%d\n", (f(s, 1) + f(s, 2)) % MOD);
	}

	return 0;
}