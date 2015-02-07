#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1, v2;
	int n, m, i;
	map<int, int> mm;

	while (scanf("%d", &n) == 1) {
		v1.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v1[i]);
			if (mm.find(v1[i]) == mm.end()) {
				v2.push_back(v1[i]);
				mm[v1[i]] = 0;
			}
		}
		sort(v2.begin(), v2.end());
		m = v2.size();
		for (i = 0; i < m; ++i) {
			mm[v2[i]] = i;
		}
		for (i = 0; i < n; ++i) {
			printf((i ? " %d" : "%d"), mm[v1[i]] + 1);
		}
		printf("\n");

		v1.clear();
		v2.clear();
		mm.clear();
	}

	return 0;
}