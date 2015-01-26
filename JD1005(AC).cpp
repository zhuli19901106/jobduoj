// What complexity!!
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 40005;
const int MAXM = 105;
const int MAXK = 5;

typedef struct st {
	int ge;
	int gi;
	int gf;
	int id;
	int pr[MAXK];
	
	bool operator < (const st &other)
	{
		if (gf != other.gf) {
			return gf < other.gf;
		} else {
			return ge < other.ge;
		}
	}

	bool operator > (const st &other)
	{
		if (gf != other.gf) {
			return gf > other.gf;
		} else {
			return ge > other.ge;
		}
	}

	bool operator == (const st &other)
	{
		return gf == other.gf && ge == other.ge;
	}
	
	bool operator <= (const st &other)
	{
		return *this < other || *this == other;
	}
	
	bool operator >= (const st &other)
	{
		return *this > other || *this == other;
	}
}st;

bool comparator(const st &s1, const st &s2)
{
	if (s1.gf != s2.gf) {
		return s1.gf > s2.gf;
	} else {
		return s1.ge > s2.ge;
	}
}

int n, m, k;
vector<vector<int> > res;
vector<st> s;
vector<int> q;
vector<int> q0;

int main()
{
	int i, j;
	vector<int> v;

	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		q.resize(m);
		q0.resize(m);
		for (i = 0; i < m; ++i) {
			scanf("%d", &q[i]);
			q0[i] = q[i];
		}
		
		s.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &s[i].ge, &s[i].gi);
			s[i].id = i;
			s[i].gf = s[i].ge + s[i].gi;
			for (j = 0; j < k; ++j) {
				scanf("%d", &s[i].pr[j]);
			}
		}
		sort(s.begin(), s.end(), comparator);
		/*
		printf("{\n");
		for (i = 0; i < n; ++i) {
			printf("%d %d %d\n", s[i].id, s[i].gf, s[i].ge);
		}
		printf("}\n");
		*/
		res.resize(m);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < k; ++j) {
				if (q[s[i].pr[j]] <= 0) {
					// insufficient quota
					if (s[i] < s[res[s[i].pr[j]][q0[s[i].pr[j]] - 1]]) {
						// the requirement is not met
						continue;
					}
				}
				res[s[i].pr[j]].push_back(i);
				--q[s[i].pr[j]];
				break;
			}
		}

		for (i = 0; i < m; ++i) {
			v.resize(res[i].size());
			for (j = 0; j < (int)res[i].size(); ++j) {
				v[j] = s[res[i][j]].id;
			}
			sort(v.begin(), v.end());
			for (j = 0; j < (int)v.size(); ++j) {
				printf((j ? " %d" : "%d"), v[j]);
			}
			putchar('\n');
			v.clear();
		}

		for (i = 0; i < m; ++i) {
			res[i].clear();
		}
		res.clear();
		s.clear();
		q.clear();
		q0.clear();
	}

	return 0;
}