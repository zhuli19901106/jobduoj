#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	vector<int> a[128];
	bool b[128];
	char s[105];
	int len;
	int i, j;

	while (scanf("%s", s) == 1) {
		len = strlen(s);
		for (i = 0; i < 128; ++i) {
			a[i].clear();
			b[i] = false;
		}
		for (i = 0; i < len; ++i) {
			a[s[i]].push_back(i);
		}

		for (i = 0; i < len; ++i) {
			if (a[s[i]].size() > 1 && !b[s[i]]) {
				b[s[i]] = true;
				printf("%c:%d", s[i], a[s[i]][0]);
				for (j = 1; j < a[s[i]].size(); ++j) {
					printf(",%c:%d", s[i], a[s[i]][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}