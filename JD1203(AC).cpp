#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int a[4];
	int t, ti;
	int i;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			while (scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]) == 4) {
				for (i = 0; i < 4; ++i) {
					if (a[i] < 0 || a[i] > 255) {
						break;
					}
				}
				printf(i == 4 ? "Yes!\n" : "No!\n");
			}
		}
	}

	return 0;
}