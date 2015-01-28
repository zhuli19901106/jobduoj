#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> x, y, z;
	int i, j;
	int a, b, c, d;
	int t, ti;
	int n, m;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%d", &n, &m);
		x.resize(n);
		y.resize(m);
		for (i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d", &y[i]);
		}
		scanf("%d%d%d%d", &a, &b, &c, &d);
		--a;
		--b;
		--c;
		--d;
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		for (i = a; i <= b; ++i) {
			z.push_back(x[i]);
		}
		for (i = c; i <= d; ++i) {
			z.push_back(y[i]);
		}
		printf("%d\n", z[(z.size() - 1) / 2]);
		x.clear();
		y.clear();
		z.clear();
	}

	return 0;
}