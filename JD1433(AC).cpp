#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Item {
	double j, f;
	double r;
} Item;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.r != i2.r) {
		return i1.r > i2.r;
	} else {
		return i1.f < i2.f;
	}
}

int main()
{
	int i, n;
	vector<Item> v;
	double f;
	double j;

	while (scanf("%d%d", &i, &n) == 2) {
		if (i == -1 && n == -1) {
			break;
		}
		f = i;
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%lf%lf", &v[i].j, &v[i].f);
			v[i].r = v[i].j / v[i].f;
		}
		sort(v.begin(), v.end(), comp);
		j = 0;
		for (i = 0; i < n; ++i) {
			if (f > v[i].f) {
				j += v[i].j;
				f -= v[i].f;
			} else {
				j += f * v[i].j / v[i].f;
				f = 0;
			}
		}
		printf("%.3f\n", j);

		v.clear();
	}

	return 0;
}