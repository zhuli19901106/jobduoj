#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 11000;
vector<int> p;
int b[N + 1];

void eratosthenes()
{
	int i, j;

	memset(b, 0, sizeof(b));
	b[0] = b[1] = 1;
	for (i = 2; i <= N/ i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= N / i; ++j) {
			b[i * j] = 1;
		}
	}
	for (i = 2; i <= N; ++i) {
		if (!b[i]) {
			p.push_back(i);
		}
	}
}

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

int countDivisor(int x)
{
	int sum = 1;
	int i;
	int c;

	i = 0;
	while (x / p[i] >= p[i]) {
		if (x % p[i] == 0) {
			c = 1;
			while (x % p[i] == 0) {
				x /= p[i];
				++c;
			}
			sum *= c;
		}
		++i;
	}
	if (x > 1) {
		sum *= 2;
	}

	return sum;
}

int main()
{
	int x, y;

	eratosthenes();

	while (scanf("%d%d", &x, &y) == 2) {
		printf("%d\n", countDivisor(gcd(x, y)));
	}

	return 0;
}