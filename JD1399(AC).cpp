#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100005;

typedef long long int LL;
typedef struct Item {
	LL w, v;
} Item;

bool comp(const Item &i1, const Item &i2)
{
	if (i1.v * i2.w != i2.v * i1.w) {
		return i1.v * i2.w > i2.v * i1.w;
	} else {
		return i1.v < i2.v;
	}
}

Item a[N];
LL c;
double sum;
int n;

int main()
{
	int i;

	while (scanf("%d%lld", &n, &c) == 2) {
		for (i = 0; i < n; ++i) {
			scanf("%lld%lld", &a[i].w, &a[i].v);
		}
		sort(a, a + n, comp);
		sum = 0;
		for (i = 0; i < n; ++i) {
			if (c == 0) {
				break;
			}
			if (c > a[i].w) {
				sum += a[i].v;
				c -= a[i].w;
			} else {
				sum += 1.0 * a[i].v * c / a[i].w;
				c = 0;
			}
		}
		printf("%lld\n", (LL)(sum + 0.5));
	}

	return 0;
}