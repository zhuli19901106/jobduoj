#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef struct Item {
	string a, b;
} Item;

void lower(char str[])
{
	int i;
	int len = strlen(str);
	
	for (i = 0; i < len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
}

bool comp(const Item &i1, const Item &i2)
{
	return i1.b < i2.b;
}

int main()
{
	int n, i;
	vector<Item> v;
	char str[1000];

	while (gets(str) != NULL && sscanf(str, "%d", &n) == 1) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			gets(str);
			v[i].a = string(str);
			lower(str);
			v[i].b = string(str);
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < n; ++i) {
			puts(v[i].a.data());
		}
		v.clear();
	}

	return 0;
}