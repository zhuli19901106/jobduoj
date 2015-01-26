#include <cstdio>
#include <cstring>
using namespace std;

void reverse(char s[])
{
	int len = strlen(s);
	int i, j;
	char ch;

	for (i = 0; i < len - 1 - i; ++i) {
		ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
	}
}

int main()
{
	char s[10];

	while (gets(s) != NULL) {
		reverse(s);
		puts(s);
	}

	return 0;
}