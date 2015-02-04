#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105;

int main()
{
	char s[N];
	int sum[N];
	int i;
	int len;

	memset(sum, 0, sizeof(sum));
	while (scanf("%s", s) == 1) {
		if (strcmp(s, "0") == 0) {
			break;
		}
		len = strlen(s);
		for (i = 0; i < len; ++i) {
			sum[len - 1 - i] += s[i] - '0';
		}
	}
	for (i = 0; i < N - 1; ++i) {
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	
	i = N - 1;
	while (i > 0 && sum[i] == 0) {
		--i;
	}
	while (i >= 0) {
		putchar(sum[i] + '0');
		--i;
	}
	putchar('\n');

	return 0;
}