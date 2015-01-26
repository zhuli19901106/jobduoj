#include <cstdio>
#include <vector>
using namespace std;

int sumOfDivisors(int n)
{
	int i;
	int sum = 0;

	if (n < 2) {
		return 0;
	}

	for (i = 1; i < n ; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}

	return sum;
}

int main()
{
	int n;
	vector<int> e;
	vector<int> g;
	int sum;

	for (n = 1; n <= 60; ++n) {
		sum = sumOfDivisors(n);
		if (sum > n) {
			g.push_back(n);
		} else if (sum == n) {
			e.push_back(n);
		}
	}

	printf("E:");
	for (n = 0; n < (int)e.size(); ++n) {
		printf(" %d", e[n]);
	}
	printf("\n");
	printf("G:");
	for (n = 0; n < (int)g.size(); ++n) {
		printf(" %d", g[n]);
	}
	printf("\n");

	return 0;
}