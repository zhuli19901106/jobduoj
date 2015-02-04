#include <cstdio>
using namespace std;

int main()
{
	int sum[101];
	int i;

	sum[0] = 0;
	for (i = 1; i <= 100; ++i) {
		sum[i] = sum[i - 1];
		if (i % 7 == 0) {
			continue;
		}
		if (i % 10 == 7 || (i >= 70 && i <= 79)) {
			continue;
		}
		sum[i] += i * i;
	}

	while (scanf("%d", &i) == 1) {
		printf("%d\n", sum[i]);
	}

	return 0;
}