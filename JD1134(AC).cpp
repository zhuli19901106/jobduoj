#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int t, ti;
	int i;
	char s[100];

	while (gets(s) !=  NULL) {
		t = atoi(s);
		for (ti = 0; ti < t; ++ti) {
			gets(s);
			for (i = 0; s[i]; ++i) {
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] = (s[i] - 'a' + 1) % 26 + 'a';
				} else if (s[i] >= 'A' && s[i] <= 'Z') {
					s[i] = (s[i] - 'A' + 1) % 26 + 'A';
				}
			}
			puts(s);
		}
	}

	return 0;
}