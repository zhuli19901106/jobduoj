#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int lp;
int lw;
vector<int> na;
const int MAXN = 1000005;
char word[MAXN], pat[MAXN];
	
void calcNext(char *pat) {
	int i = 0;
	int j = -1;
		
	na.resize(lp + 1);
	na[0] = -1;
	while (i < lp) {
		if (j == -1 || pat[i] == pat[j]) {
			++i;
			++j;
			na[i] = j;
		} else {
			j = na[j];
		}
	}
}
	
int kmpMatch(char *word, char *pat)
{
	int index;
	int pos;
	int cnt;
		
	index = pos = 0;
	cnt = 0;
	while (index < lw) {
		if (pos == -1 || word[index] == pat[pos]) {
			++index;
			++pos;
		} else {
			pos = na[pos];
		}
			
		if (pos == lp) {
			// the first match is found
			++cnt;
			pos = na[pos];
		}
	}
		
	return cnt;
}

int main()
{
	while (scanf("%s%s", word, pat) == 2) {
		lw = strlen(word);
		lp = strlen(pat);
		calcNext(pat);
		printf("%d\n", kmpMatch(word, pat));
		na.clear();
	}

	return 0;
}