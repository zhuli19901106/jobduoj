#include <cstdio>
using namespace std;

int rev(int n)
{
	int sum;

	sum = 0;
	while (n > 0) {
		sum = sum * 10 + n % 10;
		n /= 10;
	}

	return sum;
}

int main()
{
	int a, b;
	int n, ni;

	scanf("%d", &n);
	for (ni = 0; ni < n; ++ni) {
		scanf("%d%d", &a, &b);
		if (rev(a) + rev(b) == rev(a + b)) {
			printf("%d\n", a + b);
		} else {
			printf("NO\n");
		}
	}

	return 0;
}