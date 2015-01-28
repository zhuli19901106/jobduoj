#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 104742;
int b[MAXN + 1];
vector<int> primes;

void sieve()
{
	int i, j;

	memset(b, 0, (MAXN + 1) * sizeof(int));
	b[0] = b[1] = 1;
	for (i = 2; i <= MAXN / i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= MAXN / i; ++j) {
			b[i * j] = 1;
		}
	}

	primes.clear();
	for (i = 0; i <= MAXN; ++i) {
		if (!b[i]) {
			primes.push_back(i);
		}
	}
}

int main()
{
	sieve();
	// printf("%d\n", primes.size());

	int i;
	while (scanf("%d", &i) == 1) {
		printf("%d\n", primes[i - 1]);
	}

	return 0;
}