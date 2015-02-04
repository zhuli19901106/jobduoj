#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
LL b[32];

int main()
{
	const int N = 100;
	char s[N];
	int a[N];
	int i, len;
	LL sum;

	b[0] = 1;
	for (i = 1; i < 32; ++i) {
		b[i] = 2 * b[i - 1] + 1;
	}

	while (gets(s) != NULL) {
		if (strcmp(s, "0") == 0) {
			break;
		}

		len = strlen(s);
		memset(a, 0, sizeof(a));
		for (i = 0; i < len; ++i) {
			a[i] = s[len - 1 - i] - '0';
		}

		i = N - 1;
		while (i > 0 && a[i] == 0) {
			--i;
		}
		sum = 0;
		while (i >= 0) {
			sum += a[i] * b[i];
			--i;
		}
		printf("%lld\n", sum);
	}

	return 0;
}