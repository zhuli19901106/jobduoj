#include <cstdio>
#include <vector>
using namespace std;

int count(int n)
{
	int c = 0;
	while (n) {
		n = n & n - 1;
		++c;
	}

	return c;
}

void checksum(int n)
{
	int b = 64;
	int c = count(n);

	putchar(!(c & 1) + '0');
	while (b > 0) {
		if (n & b) {
			++c;
		}
		putchar(!!(n & b) + '0');
		b >>= 1;
	}
	putchar('\n');
}

int main()
{
	char s[105];
	int i;

	while (gets(s) != NULL) {
		for (i = 0; s[i]; ++i) {
			checksum(s[i]);
		}
	}

	return 0;
}