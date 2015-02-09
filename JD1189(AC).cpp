#include <cstdio>
using namespace std;

int main()
{
	int n, p;
	int i;
	int s;

	// while (scanf("%d%d", &n, &p) == 2) {
	n = 21;
	p = 17;
	s = 0;
	for (i = 2; i <= n; ++i) {
		s = (s + p) % i;
	}
	printf("%d\n", s + 1);
	// }

	return 0;
}