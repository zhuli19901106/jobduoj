#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st {
	int score;
	int id;
};

bool comp(const st &s1, const st &s2)
{
	if (s1.score != s2.score) {
		return s1.score < s2.score;
	} else {
		return s1.id < s2.id;
	}
}

int main()
{
	vector<st> v;
	int n, i;

	while (scanf("%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].id, &v[i].score);
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < n; ++i) {
			printf("%d %d\n", v[i].id, v[i].score);
		}
		v.clear();
	}

	return 0;
}