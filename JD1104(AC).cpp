#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

void Eratosthenes(vector<int> &prime, int n)
{
	// Sieve of Eratosthenes;
	vector<int> b;

	b.resize(n + 1, 0);
	b[0] = b[1] = 1;

	int i, j;
	for (i = 2; i * i <= n; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; i * j <= n; ++j) {
			b[i * j] = 1;
		}
	}

	for (i = 0; i <= n; ++i) {
		if (!b[i]) {
			prime.push_back(i);
		}
	}

	b.clear();
}

int count(int n, int p)
{
	// Count how many p are there in the factorization of n!
	// Here p is a prime number.
	int sum = 0;

	while (n > 0) {
		sum += n / p;
		n /= p;
	}

	return sum;
}

void factorize(int n, vector<int> &p, vector<int> &c, const vector<int> &prime)
{
	int i = 0;
	int cc;

	// prime[i] * prime[i] <= n
	while (n / prime[i] >= prime[i]) {
		if (n % prime[i] == 0) {
			p.push_back(prime[i]);
			cc = 0;
			while (n % prime[i] == 0) {
				n /= prime[i];
				++cc;
			}
			c.push_back(cc);
		}
		++i;
	}
	if (n > 1) {
		p.push_back(n);
		c.push_back(1);
	}
}

int main()
{
	int n, a;
	int k;
	vector<int> prime;
	vector<int> cn;
	vector<int> pa;
	vector<int> ca;

	Eratosthenes(prime, 1000);
	int i;

	while (scanf("%d%d", &n, &a) == 2) {
		factorize(a, pa, ca, prime);
		for (i = 0; i < (int)pa.size(); ++i) {
			cn.push_back(count(n, pa[i]));
		}

		k = INT_MAX;
		for (i = 0; i < (int)pa.size(); ++i) {
			k = min(k, cn[i] / ca[i]);
		}
		printf("%d\n", k);

		pa.clear();
		ca.clear();
		cn.clear();
	}
	prime.clear();

	return 0;
}