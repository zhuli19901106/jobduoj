#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int t, ti;
	string s;
	int n;

	while (scanf("%d", &t) == 1) {
		for (ti = 0; ti < t; ++ti) {
			scanf("%d", &n);
			if (n == 0) {
				printf("0\n");
				continue;
			}
			while (n > 0) {
				s.push_back((n & 1) + '0');
				n >>= 1;
			}
			reverse(s.begin(), s.end());
			puts(s.data());
			s.clear();
		}
	}

	return 0;
}