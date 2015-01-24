#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> um;
	string s;
	
	um["zero"] = 0;
	um["one"] = 1;
	um["two"] = 2;
	um["three"] = 3;
	um["four"] = 4;
	um["five"] = 5;
	um["six"] = 6;
	um["seven"] = 7;
	um["eight"] = 8;
	um["nine"] = 9;

	int n1, n2, n3;
	while (cin >> s) {
		n1 = 0;
		do {
			n1 = n1 * 10 + um[s];
			cin >> s;
		} while (s != "+");
		cin >> s;
		n2 = 0;
		do {
			n2 = n2 * 10 + um[s];
			cin >> s;
		} while (s != "=");
		if (n1 == 0 && n2 == 0) {
			break;
		}
		n3 = n1 + n2;
		cout << n3 << endl;
	}

	return 0;
}