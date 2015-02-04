#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[500];
	int i;
	
	while (gets(s) != NULL) {
		if (strcmp(s, "ENDOFINPUT") == 0) {
			break;
		}
		gets(s);
		for (i = 0;s[i]; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = (s[i] - 'A' + 21) % 26 + 'A';
			}
		}
		puts(s);
		gets(s);
	}

	return 0;
}