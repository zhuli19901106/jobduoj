#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int N = 1000005;
int n, m;
int c[32];
unsigned int mk[32];

int main()
{
	int i, j;
	unsigned int val;

	mk[0] = 1;
	for (i = 1; i < 32; ++i) {
		mk[i] = mk[i - 1] << 1;
	}

	while (scanf("%d%d", &m, &n) == 2) {
		for (i = 0; i < 32; ++i) {
			c[i] = 0;
		}
		for (i = 0; i < n; ++i) {
			scanf("%u", &val);
			for (j = 0; j < 32; ++j) {
				if (val & mk[j]) {
					++c[j];
				}
			}
		}
		val = 0;
		for (i = 0; i < 32; ++i) {
			if (c[i] % m) {
				val |= mk[i];
			}
		}
		printf("%u\n", val);
	}

	return 0;
}