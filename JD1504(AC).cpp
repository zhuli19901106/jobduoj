// 689366	zhuli19901106	1504	Accepted	点击此处查看所有case的执行结果	1524KB	771B	270MS
// 201402022141
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> vv;
int n;

bool comparator(const string &x, const string &y)
{
	string s1, s2;

	s1 = x + y;
	s2 = y + x;
	return s1 < s2;
}

int main()
{
	string s;
	int i;

	while (cin >> n) {
		vv.clear();
		for (i = 0; i < n; ++i) {
			cin >> s;
			vv.push_back(s);
		}
		sort(vv.begin(), vv.end(), comparator);
		s = "";
		for (i = 0; i < n; ++i) {
			s = s + vv[i];
		}
		for (i = 0; i < (int)s.length() - 1; ++i) {
			if (s[i] != '0') {
				break;
			}
		}
		s = s.substr(i, s.length() - i);
		cout << s << endl;
	}

	return 0;
}