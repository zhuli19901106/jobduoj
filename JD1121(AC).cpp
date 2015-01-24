#include <cstdio>
#include <cstring>
using namespace std;

inline bool isblank(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

int main()
{
	char s[1000];
	int i;
	int len;

	while (gets(s) != NULL) {
		len = strlen(s);
		i = 0;
		while (i < len) {
			switch (s[i]) {
			case ' ':
			case '\t':
			case '\r':
			case '\n':
				while (i < len && isblank(s[i])) {
					++i;
				}
				break;
			default:
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] = s[i] - 'a' + 'A';
				}
				while (i < len && !isblank(s[i])) {
					++i;
				}
			}
		}
		puts(s);
	}

	return 0;
}