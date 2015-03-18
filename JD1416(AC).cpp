#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct Record {
	string s;
	int a;
	int b;
} Record;

vector<Record> v;
map<string, int> mm;
int n, m;

bool comp(const Record &r1, const Record &r2)
{
	if (r1.a != r2.a) {
		return r1.a > r2.a;
	} else {
		return r1.s < r2.s;
	}
}

int main()
{
	int i;
	int sum;
	string s;

	while (cin >> n >> m) {
		v.resize(n);

		for (i = 0; i < n; ++i) {
			cin >> v[i].s >> v[i].a >> v[i].b;
		}

		sort(v.begin(), v.end(), comp);
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum += v[i].b;
			mm[v[i].s] = sum - v[i].b + 1;
		}

		for (i = 0; i < m; ++i) {
			cin >> s;
			cout << mm[s] << endl;
		}

		v.clear();		
		mm.clear();
	}

	return 0;
}