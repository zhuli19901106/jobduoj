#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Record{
	int id;
	string name;
	int age;
}Record;

bool comparator(const Record &r1, const Record &r2)
{
	if (r1.age != r2.age) {
		return r1.age < r2.age;
	} else if (r1.id != r2.id) {
		return r1.id < r2.id;
	} else {
		return r1.name < r2.name;
	}
}

int main()
{
	int n;
	int i;
	vector<Record> v;

	while (cin >> n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].id >> v[i].name >> v[i].age;
		}
		sort(v.begin(), v.end(), comparator);
		int cc = min(n, 3);
		for (i = 0; i < cc; ++i) {
			cout << v[i].id << " " << v[i].name << " " << v[i].age << endl;
		}
		v.clear();
	}

	return 0;
}