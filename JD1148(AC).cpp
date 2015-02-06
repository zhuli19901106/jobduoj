#include <cstdio>
using namespace std;

int main()
{
	int i;
	double d;
	double s;

	while (scanf("%lf", &d) == 1) {
		s = d;
		for(i = 1; i < 12; i++)
		{
			scanf("%lf", &d);
			s += d;
		}
		s /= 12;
		printf("$%.2f\n", s);
	}

	return 0;
}