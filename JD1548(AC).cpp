#include <algorithm>
#include <climits>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef struct Pair {
	int x, y;

	bool operator < (const Pair &other) const
	{
		if (x != other.x) {
			return x < other.x;
		} else {
			return y < other.y;
		}
	}
} Pair;

int gcd(int x, int y)
{
	return x ? gcd(y % x, x) : y;
}

void normalize(Pair &p)
{
	if (p.x == 0) {
		p.y = (p.y ? 1 : 0);
		return;
	}
	if (p.y == 0) {
		p.x = (p.x ? 1 : 0);
	}
	if (p.x < 0) {
		p.x = -p.x;
		p.y = -p.y;
	}
	int g = gcd(abs(p.x), abs(p.y));
	p.x /= g;
	p.y /= g;
}

int main()
{
	map<Pair, int> mm;
	map<Pair, int>::iterator it;
	vector<Pair> v;
	Pair tmp;
	int countZero;
	int i, j, n;
	int sum, msum;

	while (scanf("%d", &n) == 1) {
		v.resize(n);

		for (i = 0; i < n; ++i) {
			scanf("%d%d", &v[i].x, &v[i].y);
		}

		if (n == 1) {
			printf("1\n");
			v.clear();
			continue;
		}

		msum = 0;
		for (i = 0; i < n; ++i) {
			countZero = 0;
			sum = 0;
			for (j = i + 1; j < n; ++j) {
				tmp.x = v[i].x - v[j].x;
				tmp.y = v[i].y - v[j].y;
				if (tmp.x == 0 && tmp.y == 0) {
					++countZero;
					continue;
				}
				normalize(tmp);
				++mm[tmp];
			}
			for (it = mm.begin(); it != mm.end(); ++it) {
				sum = max(sum, it->second);
			}
			msum = max(msum, sum + countZero + 1);
			mm.clear();
		}
		printf("%d\n", msum);
		v.clear();
	}

	return 0;
}