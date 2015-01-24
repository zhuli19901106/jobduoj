#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 50000;
int b[maxn];
int p[5000];
int pc;

int main()
{
	int i, j;
	
	memset(b, 0, maxn * sizeof(int));
	b[0] = b[1] = 1;
	for (i = 2; i * i < maxn; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; i * j < maxn; ++j) {
			b[i * j] = 1;
		}
	}
	
	pc = 0;
	for (i = 0; i < maxn; ++i) {
		if (b[i] == 0) {
			p[pc++] = i;
		}
	}
	
	int n;
	int count;
	
	while (scanf("%d", &n) == 1) {
		count = 0;
		i = 0;
		while (n / p[i] >= p[i]) {
			while (n % p[i] == 0) {
				++count;
				n /= p[i];
			}
			++i;
		}
		if (n > 1) {
			++count;
		}
		printf("%d\n", count);
	}
	
	return 0;
}