#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Item {
	int id;
	int s;
} Item;
vector<Item> v;
int n, m;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.s != i2.s) {
		return i1.s > i2.s;
	} else {
		return i1.id < i2.id;
	}
}

int main()
{
	int i;

	while (cin >> n >> m) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].id >> v[i].s;
		}
		sort(v.begin(), v.end(), comp);
		m = min(m, n);
		for (i = 0; i < m; ++i) {
			cout << v[i].id << endl;
		}
		v.clear();
	}

	return 0;
}