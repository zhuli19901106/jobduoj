#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50000;
int b[maxn];
int p[5000];
int pc;

int countDivisor(int n)
{
	int res;
	int i;
	int c;
	
	res = 1;
	i = 0;
	while (n / p[i] >= p[i]) {
		c = 0;
		while (n % p[i] == 0) {
			++c;
			n /= p[i];
		}
		res *= (c + 1);
		++i;
	}
	if (n > 1) {
		res *= 2;
	}
	
	return res;
}

int main()
{
	int i, j;
	
	memset(b, 0, maxn * sizeof(int));
	b[0] = b[1] = 1;
	for (i = 2; i * i < maxn; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j * i < maxn; ++j) {
			b[j * i] = 1;
		}
	}
	pc = 0;
	for (i = 0; i < maxn; ++i) {
		if (b[i] == 0) {
			p[pc++] = i;
		}
	}
	
	int n;
	int num;
	
	while (scanf("%d", &n) && n != 0) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &num);
			printf("%d\n", countDivisor(num));
		}
	}
	
	return 0;
}