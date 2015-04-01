#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Record {
	string s;
	int c;
	int p;
} Record;
vector<Record> v;
int n;

bool comp(const Record &r1, const Record &r2)
{
	if (r1.c != r2.c) {
		return r1.c > r2.c;
	} else if (r1.p != r2.p) {
		return r1.p < r2.p;
	} else {
		return r1.s < r2.s;
	}
}

int main()
{
	int i;

	while (cin >> n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].s >> v[i].c >> v[i].p;
		}
		sort(v.begin(), v.end(), comp);
		for (i = 0; i < n; ++i) {
			cout << v[i].s << endl;
		}
		v.clear();
	}

	return 0;
}