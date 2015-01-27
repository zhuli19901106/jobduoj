#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 1000;
	char s[2 * MAXN + 1], t[MAXN + 1];
	int i, j;

	while (scanf("%s%s", s, t) == 2) {
		i = 0;
		while (s[i]) {
			++i;
		}
		j = 0;
		while (t[j]) {
			s[i++] = t[j++];
		}
		s[i] = 0;
		puts(s);
	}

	return 0;
}