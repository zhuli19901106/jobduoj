#include <cstdio>
#include <cstring>
using namespace std;

bool pal(const char s[])
{
	int i, len;
	
	len = strlen(s);
	for (i = 0; i < len - 1 - i; ++i) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	
	return true;
}

int main()
{
	int i;
	char s[10];
  
	for (i = 0; i <= 256; ++i) {
		sprintf(s, "%d", i * i);
		if (pal(s)) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}