#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<long long int> v;
	v.resize(40);
	
	v[0] = 0;
	v[1] = 1;

	int i, j;

	for (i = 2; i < 40; ++i) {
		v[i] = v[i - 1] + v[i - 2];
	}

	int n;

	while (scanf("%d", &n) == 1) {
		n = n * 2 - 1;
		for (i = 1; i <= n; i += 2) {
			printf("%d", v[0]);
			for (j = 1; j < i; ++j) {
				printf(" %d", v[j]);
			}
			printf("\n");
		}
	}

	return 0;
}