#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Term{
	int e;
	int c;
}Term;

bool comparator(const Term &x, const Term &y)
{
	return x.e > y.e;
}

int main()
{
	vector<Term> v1, v2;
	int n, m;
	vector<Term> v3;
	Term term;
	int i, j;

	while (scanf("%d", &n) == 1) {
		v1.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &v1[i].c, &v1[i].e);
		}
		sort(v1.begin(), v1.end(), comparator);
		scanf("%d", &m);
		v2.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &v2[i].c, &v2[i].e);
		}
		sort(v2.begin(), v2.end(),comparator);
		i = j = 0;
		while (i < n && j < m) {
			if (v1[i].e > v2[j].e) {
				v3.push_back(v1[i++]);
			} else if (v1[i].e < v2[j].e) {
				v3.push_back(v2[j++]);
			} else {
				if (v1[i].c + v2[j].c != 0) {
					term.e = v1[i].e;
					term.c = v1[i].c + v2[j].c;
					v3.push_back(term);
				}
				++i;
				++j;
			}
		}
		while (i < n) {
			v3.push_back(v1[i++]);
		}
		while (j < m) {
			v3.push_back(v2[j++]);
		}

		n = v3.size();
		for (i = 0; i < n; ++i) {
			printf((i ? " %d %d" : "%d %d"), v3[i].c, v3[i].e);
		}
		printf("\n");
		v1.clear();
		v2.clear();
		v3.clear();
	}

	return 0;
}