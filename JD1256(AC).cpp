#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	int res;
	int n, i;
	int m1, m2;
	int bit;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		res = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
			res ^= v[i];
		}
		bit = 1;
		while (!(res & bit)) {
			bit <<= 1;
		}
		m1 = m2 = 0;
		for (i = 0; i < n; ++i) {
			if (v[i] & bit) {
				m1 ^= v[i];
			} else {
				m2 ^= v[i];
			}
		}
		if (m1 > m2) {
			swap(m1, m2);
		}
		printf("%d %d\n", m1, m2);
		v.clear();
	}

	return 0;
}