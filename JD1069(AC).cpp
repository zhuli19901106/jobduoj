#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct st{
	string id;
	string name;
	string gender;
	int age;
}st;

int main()
{
	map<string, st> um;
	map<string, st>::iterator it;
	int n, m;
	int i;
	st s1;
	
	while (cin >> n) {
		for (i = 0; i < n; ++i) {
			cin >> s1.id >> s1.name >> s1.gender >> s1.age;
			um[s1.id] = s1;
		}
		cin >> m;
		for (i = 0; i < m; ++i) {
			cin >> s1.id;
			it = um.find(s1.id);
			if (it != um.end()) {
				cout << it->second.id << ' ' << it->second.name << ' ' 
					<< it->second.gender << ' ' << it->second.age << endl;
			} else {
				cout << "No Answer!" << endl;
			}
		}
		um.clear();
	}
	
	return 0;
}