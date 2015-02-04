#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	vector<int> res;
	int n;
	int t, ti;
	int i;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		for (i = 0; i < n; ++i) {
			if (i == 0) {
				if (v[i] != v[i + 1]) {
					res.push_back(i);
				}
			} else if (i == n - 1) {
				if (v[i - 1] != v[i]) {
					res.push_back(i);
				}
			} else if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
				res.push_back(i);
			} else if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
				res.push_back(i);
			}
		}
		n = (int)res.size();
		for (i = 0; i < n; ++i) {
			printf((i ? " %d" : "%d"), res[i]);
		}
		printf("\n");

		v.clear();
		res.clear();
	}

	return 0;
}