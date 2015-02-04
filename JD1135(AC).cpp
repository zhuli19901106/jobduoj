#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

bool comparator(const string &s1, const string &s2)
{
	return s1.length() < s2.length();
}

int main()
{
	string str;
	char s[200];
	vector<string> v;
	int n, i;

	while (gets(s) != NULL) {
		sscanf(s, "%d", &n);
		for (i = 0; i < n; ++i) {
			gets(s);
			str = string(s);
			if (str == "stop") {
				break;
			}
			v.push_back(str);
		}
		sort(v.begin(), v.end(), comparator);
		n = (int)v.size();
		for (i = 0; i < n; ++i) {
			puts(v[i].data());
		}
		v.clear();
	}

	return 0;
}