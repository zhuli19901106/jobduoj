#include <cstdio>
#include <vector>
using namespace std;

void parse(int n, vector<int> &v)
{
	if (n == 0) {
		v.push_back(0);
		return;
	}

	while (n > 0) {
		v.push_back(n & 1);
		n >>= 1;
	}
}

bool check(vector<int> &a, vector<int> &b)
{
	if (a.size() > b.size()) {
		return check(b, a);
	}

	a.resize(b.size(), 0);
	int i, j, len;

	len = b.size();
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			if (a[j] != b[(j + i) % len]) {
				break;
			}
		}
		if (j == len) {
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> a, b;
	int na, nb;
	int t, ti;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d%d", &na, &nb);
			parse(na, a);
			parse(nb, b);
			printf(check(a, b) ? "YES\n" : "NO\n");
			a.clear();
			b.clear();
		}
	}

	return 0;
}