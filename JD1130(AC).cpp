#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef struct Item{
	string name;
	int y, m, d;
	int hh, mm, ss, ms;
	double len;
	string str;
} Item;

bool comparator(const Item &i1, const Item &i2)
{
	if (i1.len != i2.len) {
		return i1.len < i2.len;
	} else if (i1.y != i2.y) {
		return i1.y < i2.y;
	} else if (i1.m != i2.m) {
		return i1.m < i2.m;
	} else if (i1.d != i2.d) {
		return i1.d < i2.d;
	} else if (i1.hh != i2.hh) {
		return i1.hh < i2.hh;
	} else if (i1.mm != i2.mm) {
		return i1.mm < i2.mm;
	} else if (i1.ss != i2.ss) {
		return i1.ss < i2.ss;
	} else {
		return i1.ms < i2.ms;
	}
}

int main()
{
	const int N = 500;
	int i;
	char s[N];
	char s1[100];
	vector<Item> v;
	Item item;

	while (gets(s) != NULL) {
		if (s[0] == 0) {
			break;
		}
		sscanf(s, "%s%d-%d-%d %d:%d:%d,%d %lf", &s1, &item.y, &item.m, &item.d, 
			&item.hh, &item.mm, &item.ss, &item.ms, &item.len);
		item.name = string(s1);
		item.str = string(s);
		v.push_back(item);
	}
	sort(v.begin(), v.end(), comparator);
	for (i = 0; i < (int)v.size(); ++i) {
		puts(v[i].str.data());
	}

	return 0;
}