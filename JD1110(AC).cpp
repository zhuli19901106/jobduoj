#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct st {
	int w;
	string s;
} st;

bool comparator(const st &x, const st &y)
{
	if (x.w != y.w) {
		return x.w > y.w;
	} else {
		return x.s < y.s;
	}
}

int main()
{
	int n;
	int i;
	vector<st> v;

	while (cin >> n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].w >> v[i].s;
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < n; ++i) {
			cout << v[i].s << endl;
		}
		v.clear();
	}

	return 0;
}