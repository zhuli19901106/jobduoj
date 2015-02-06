#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int total;
	char p1[1000];
	char p2[1000];
	char clas[1000];
	int dist;
	bool termin;

	termin = false;
	while (!termin) {
		total = 0;
		while (true) {
			if (scanf("%s", p1) != 1) {
				termin = true;
				break;
			} else if (strcmp(p1, "#") == 0) {
				termin = true;
				break;
			} else if (strcmp(p1, "0") == 0) {
				break;
			}
			scanf("%s%d%s", p2, &dist, clas);
			if (strcmp(clas, "F") == 0) {
				total += dist * 2;
			} else if (strcmp(clas, "B") == 0) {
				total += dist + (dist + 1) / 2;
			} else if (strcmp(clas, "Y") == 0) {
				if (dist < 500) {
					total += 500;
				} else {
					total += dist;
				}
			}
		}
		if(termin) {
			break;
		}
		printf("%d\n", total);
	}

	return 0;
}