#include <algorithm>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main()
{
	char s[1005];
	vector<string> v;
	int minLen = INT_MAX;
	int maxLen = INT_MIN;
	int len;

	while (gets(s) != NULL) {
		v.push_back(string(s));
		len = v.back().length();
		minLen = min(minLen, len);
		maxLen = max(maxLen, len);
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		if (it->length() != minLen) {
			continue;
		}
		puts(it->data());
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		if (it->length() != maxLen) {
			continue;
		}
		puts(it->data());
	}

	v.clear();

	return 0;
}