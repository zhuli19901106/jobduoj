#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int t, ti;
	vector<double> p;
	int n, i;
	double v, w;
	double c;
	int num;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d%lf%lf", &n, &v, &w);
		p.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lf", &p[i]);
		}
		sort(p.begin(), p.end());
		if (p[0] > w) {
			printf("0 0.00\n");
			p.clear();
			continue;
		}
		num = 1;
		c = p[0];
		for (i = 1; i < n; ++i) {
			if ((c + p[i]) / (num + 1) > w) {
				break;
			}
			c += p[i];
			++num;
		}
		printf("%d %.2f\n", (int)(num * v), c / (num * 100));
		p.clear();
	}

	return 0;
}