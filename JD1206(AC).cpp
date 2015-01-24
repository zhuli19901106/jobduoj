#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 205;
	char s[MAXN], t[MAXN];
	int i, j;
	
	while (scanf("%s%s", s, t) == 2) {
		i = 0;
		while (s[i] != 0) {
			++i;
		}
		j = 0;
		while (t[j] != 0) {
			s[i++] = t[j++];
		}
		s[i++] = t[j++];

		puts(s);
	}

	return 0;
}