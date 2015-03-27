#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

typedef struct Item {
	ULL p, q;
} Item;

void solve1()
{
	ULL n;
	vector<ULL> v;
	
	scanf("%llu", &n);
	while (true) {
		v.push_back(n);
		if (n == 1) {
			break;
		}
		n /= 2;
	}

	int i;
	Item it;

	it.p = it.q = 1;
	for (i = v.size() - 1; i > 0; --i) {
		if (v[i - 1] == v[i] * 2) {
			// Go left
			it.q = it.p + it.q;
		} else {
			// Go right
			it.p = it.p + it.q;
		}
	}
	printf("%llu %llu\n", it.p, it.q);
	v.clear();
}

void solve2()
{
	Item it;
	vector<Item> v;

	scanf("%llu%llu", &it.p, &it.q);
	while (true) {
		v.push_back(it);
		if (it.p < it.q) {
			it.q -= it.p;
		} else if (it.p > it.q) {
			it.p -= it.q;
		} else {
			break;
		}
	}

	ULL n;
	int i;

	n = 1;
	for (i = v.size() - 1; i > 0; --i) {
		if (v[i - 1].p < v[i - 1].q) {
			n = n * 2;
		} else {
			n = n * 2 + 1;
		}
	}

	printf("%llu\n", n);
}

int main()
{
	int t, ti;
	int op;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &op);
		if (op == 1) {
			solve1();
		} else {
			solve2();
		}
	}

	return 0;
}