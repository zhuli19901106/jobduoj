#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[100];
	int len;

	while (gets(s) != NULL) {
		len = strlen(s);
		sort(s, s + len);
		puts(s);
	}

	return 0;
}