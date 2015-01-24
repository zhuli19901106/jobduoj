#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s[100000];

int main()
{
	int len;
	int i, j;
	vector<int> wordLens;

	while (gets(s) != NULL) {
		len = strlen(s);
		s[len - 1] = 0;
		--len;

		i = 0;
		while (i < len) {
			switch (s[i]) {
			case ' ':
				while (i < len && s[i] == ' ') {
					++i;
				}
				break;
			default:
				j = i;
				while (j < len && s[j] != ' ') {
					++j;
				}
				wordLens.push_back(j - i);
				i = j;
			}
		}

		for (i = 0; i < (int)wordLens.size(); ++i) {
			printf((i == 0 ? "%d" : " %d"), wordLens[i]);
		}
		putchar('\n');
		wordLens.clear();
	}

	return 0;
}