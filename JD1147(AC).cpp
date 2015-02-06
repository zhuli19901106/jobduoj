#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int ca;
	int cb;
	int n;
	char na;
	char nb;
	int a;
	int b;
	bool success;

	while (scanf("%d%d%d", &ca, &cb, &n) == 3) {
		na = 'A';
		nb = 'B';

		if (ca > cb) {
			swap(ca, cb);
			swap(na, nb);
		}

		a = 0;
		b = 0;
		success = false;
		while (!success) {
			//Fill b
			b = cb;
			printf("fill %c\n", nb);
			if (a == n || b == n) {
				success = 1;
				break;
			}

			while (!success && b >= ca) {
				//Pour b into a
				b = b - (ca - a);
				a = ca;
				printf("pour %c %c\n", nb, na);
				if (a == n || b == n) {
					success = true;
					break;
				}

				//Empty a
				a = 0;
				printf("empty %c\n", na);
				if (a == n || b == n) {
					success = true;
					break;
				}
			}

			if (success) {
				break;
			}

			//Pour b into a
			a = b;
			b = 0;
			printf("pour %c %c\n", nb, na);
			if (a == n || b == n) {
				success = 1;
				break;
			}
		}
		printf("success\n");
	}

	return 0;
}