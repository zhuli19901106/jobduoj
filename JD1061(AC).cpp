#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	int grade;
	string name;
	int age;
}st;

bool comparator(const st &a, const st &b)
{
	if (a.grade != b.grade) {
		return a.grade < b.grade;
	} else if (a.name != b.name) {
		return a.name < b.name;
	} else {
		return a.age < b.age;
	}
}

int main()
{
	int i, n;
	vector<st> v;
	
	while (cin >> n) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].name >> v[i].age >> v[i].grade;
		}
		sort(v.begin(), v.end(), comparator);
		for (i = 0; i < n; ++i) {
			cout << v[i].name << ' ' << v[i].age << ' ' << v[i].grade << endl;
		}
		v.clear();
	}
	
	return 0;
}