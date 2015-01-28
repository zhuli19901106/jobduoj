#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string fun(int n)
{
	if (n <= 0) {
		return "0";
	} else if (n == 1) {
		return "2(0)";
	} else if (n == 2) {
		return "2";
	}

	int i = 15;
	string str;
	while (i >= 0) {
		if ((1 << i) > n) {
			--i;
			continue;
		}
		
		if ((1 << i) & n) {
			if (i > 1) {
				str = str + "2(" + fun(i) + ")+";
			} else {
				str = str + fun(1 << i) + "+";
			}
		}
		--i;
	}
	str.erase(str.length() - 1);
	return str;
}

int main()
{
	int n;

	while (cin >> n) {
		cout << fun(n) << endl;
	}

	return 0;
}