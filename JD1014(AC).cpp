#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct st {
	string id;
	int score;
} st;

bool comparator(const st &s1, const st &s2)
{
	if (s1.score != s2.score) {
		return s1.score > s2.score;
	} else {
		return s1.id < s2.id;
	}
}

int main()
{
	vector<st> v;
	vector<int> w;
	int n, m, g;
	int i, j, k;
	int val;

	while (cin >> n && n > 0) {
		v.resize(n);
		cin >> m >> g;
		w.resize(m);
		for (i = 0; i < m; ++i) {
			cin >> w[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> v[i].id >> k;
			v[i].score = 0;
			for (j = 0; j < k; ++j) {
				cin >> val;
				v[i].score += w[val - 1];
			}
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < n; ++i) {
			if (v[i].score < g) {
				break;
			}
		}
		cout << i << endl;
		for (i = 0; i < n; ++i) {
			if (v[i].score < g) {
				break;
			}
			cout << v[i].id << ' ' << v[i].score << endl;
		}
		w.clear();
		v.clear();
	}

	return 0;
}