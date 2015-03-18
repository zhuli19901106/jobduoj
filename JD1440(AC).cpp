#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 40000;
int b[N + 1];
vector<int> p;

int main()
{
	int i, j;
	
	memset(b, 0, sizeof(b));
	b[0] = b[1] = 1;
	for (i = 2; i <= N / i; ++i) {
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

	int n;
	int pc = p.size();
	int res;

	while (scanf("%d", &n) == 1 && n) {
		res = 0;
		for (i = 0; p[i] <= n - p[i]; ++i) {
			if (b[n - p[i]]) {
				continue;
			}
			++res;
		}
		printf("%d\n", res);
	}
	p.clear();

	return 0;
}