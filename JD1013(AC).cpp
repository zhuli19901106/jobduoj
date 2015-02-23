#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string s;
	int t1, t2;
}st;

int main()
{
	char str[100];
	int n, i;
	int h, m, s;
	int t, ti;
	vector<st> v;
	int early, late;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		v.resize(n);
		early = late = -1;
		for (i = 0; i < n; ++i) {
			scanf("%s", str);
			v[i].s = string(str);
			scanf("%02d:%02d:%02d ", &h, &m, &s);
			v[i].t1 = h * 3600 + m * 60 + s;
			scanf("%02d:%02d:%02d", &h, &m, &s);
			v[i].t2 = h * 3600 + m * 60 + s;
			if (early == -1 || v[i].t1 < v[early].t1) {
				early = i;
			}
			if (late == -1 || v[i].t2 > v[late].t2) {
				late = i;
			}
		}
		printf("%s %s\n", v[early].s.data(), v[late].s.data());
		v.clear();
	}

	return 0;
}