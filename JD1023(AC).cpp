#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct st {
	string id;
	string name;
	int score;
} st;

bool comp1(const st &s1, const st &s2)
{
	return s1.id < s2.id;
}

bool comp2(const st &s1, const st &s2)
{
	if (s1.name != s2.name) {
		return s1.name < s2.name;
	} else {
		return s1.id < s2.id;
	}
}

bool comp3(const st &s1, const st &s2)
{
	if (s1.score != s2.score) {
		return s1.score < s2.score;
	} else {
		return s1.id < s2.id;
	}
}

int main()
{
	int n, c;
	vector<st> v;
	int i;
	int caseno;

	caseno = 0;
	while (cin >> n >> c) {
		if (n == 0) {
			break;
		}
		++caseno;
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].id >> v[i].name >> v[i].score;
		}
		if (c == 1) {
			sort(v.begin(), v.end(), comp1);
		} else if (c == 2) {
			sort(v.begin(), v.end(), comp2);
		} else if (c == 3) {
			sort(v.begin(), v.end(), comp3);
		}
		cout << "Case " << caseno << ":" << endl;
		for (i = 0; i < n; ++i) {
			cout << v[i].id << " " << v[i].name << " " << v[i].score << endl;
		}
		v.clear();
	}

	return 0;
}