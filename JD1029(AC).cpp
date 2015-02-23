#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

char s[100000];

int main()
{
	int n, i;
	map<string, string> m1, m2;
	map<string, string>::iterator it;

	while (true) {
		gets(s);
		if (strcmp(s, "@END@") == 0) {
			break;
		}

		i = 1;
		while (s[i] != ']') {
			++i;
		}
		s[i] = 0;

		m1[string(s + 1)] = string(s + i + 2);
		m2[string(s + i + 2)] = string(s + 1);
	}
	gets(s);
	sscanf(s, "%d", &n);
	for (i = 0; i < n; ++i) {
		gets(s);
		if (s[0] == '[') {
			s[strlen(s) - 1] = 0;
			it = m1.find(string(s + 1));
			if (it != m1.end()) {
				printf("%s\n", it->second.data());
			} else {
				printf("what?\n");
			}
		} else {
			it = m2.find(string(s));
			if (it != m2.end()) {
				printf("%s\n", it->second.data());
			} else {
				printf("what?\n");
			}
		}
	}
	m1.clear();
	m2.clear();

	return 0;
}