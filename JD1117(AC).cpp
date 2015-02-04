#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

bool comparator(const int &x, const int &y)
{
	if (x % 2) {
		if (y % 2) {
			return x > y;
		} else {
			return true;
		}
	} else {
		if (y % 2) {
			return false;
		} else {
			return x < y;
		}
	}
}

int main()
{
	vector<int> v;
	int i;

	v.resize(10);
	while (scanf("%d", &v[0]) == 1) {
		for (i = 1; i < 10; ++i) {
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < 10; ++i) {
			printf((i ? " %d" : "%d"), v[i]);
		}
		printf("\n");
	}
	v.clear();

	return 0;
}