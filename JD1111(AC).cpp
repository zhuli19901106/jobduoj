#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[200];
	char w[200];
	char w1[200], w2[200];
	int len, i;
	bool first;

	while (gets(s) != NULL) {
		first = true;
		gets(w1);
		gets(w2);
		len = strlen(s);
		i = 0;
		while (i < len) {
			sscanf(s + i, "%s", w);
			if (strcmp(w, w1) == 0) {
				printf((first ? "%s" : " %s"), w2);
				first = false;
			} else {
				printf((first ? "%s" : " %s"), w);
				first = false;
			}
			++i;
			while (i < len && s[i] != ' ') {
				++i;
			}
			++i;
		}
		printf("\n");
	}

	return 0;
}