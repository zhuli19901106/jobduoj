#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct st{
	int a, b;
}st;

bool comp(const st &a, const st &b)
{
	if (a.a == b.a) {
		return a.b < b.b;
	} else {
		return a.a< b.a;
	}
}

int main()
{
	vector<st> v;
	int n;
	int L;
	st s;
	int a, b;
	int sum;
	int i;
	
	while (scanf("%d%d", &L, &n) == 2 && (L || n)) {
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &s.a, &s.b);
			v.push_back(s);
		}
		sort(v.begin(), v.end(), comp);
		a = 0;
		b = -1;
		sum = 0;
		for (i = 0; i < n; ++i) {
			if (b < v[i].a - 1) {
				sum += (b - a + 1);
				a = v[i].a;
				b = v[i].b;
			} else if (v[i].b > b) {
				b = v[i].b;
			}
		}
		sum += (b - a + 1);
		printf("%d\n", L + 1 - sum);
		v.clear();
	}
	
	return 0;
}