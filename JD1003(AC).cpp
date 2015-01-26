#include <cstdio>
using namespace std;

void trim(char s[])
{
	int i, j;

	i = j = 0;
	while (s[i]) {
		if (s[i] != ',') {
			s[j++] = s[i++];
		} else {
			++i;
		}
	}
	s[j] = 0;
}

int main()
{
	int a, b;
	char s[20];

	while (scanf("%s", s) == 1) {
		trim(s);
		sscanf(s, "%d", &a);
		scanf("%s", s);
		trim(s);
		sscanf(s, "%d", &b);
		printf("%d\n", a + b);
	}

	return 0;
}