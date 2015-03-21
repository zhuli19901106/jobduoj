#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string sa, sb;
	int i;
	map<string, int> mm;
	map<string, int>::iterator it;
	int n;

	while (cin >> n && n) {
		for (i = 0; i < n; ++i) {
			cin >> sa >> sb;
			mm[sa];
			++mm[sb];
		}
		i = 0;
		for (it = mm.begin(); it != mm.end(); ++it) {
			if (it->second == 0) {
				++i;
			}
		}
		cout << (i == 1 ? "Yes" : "No") << endl;
		mm.clear();
	}

	return 0;
}