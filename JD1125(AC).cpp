#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 50;

int mod(int a[], int m)
{
	int i;
	int res;

	i = N - 1;
	res = 0;
	while (i >= 0 && a[i] == 0) {
		--i;
	}
	while (i >= 0) {
		res = (res * 10 + a[i]) % m;
		--i;
	}

	return res;
}

int main()
{
	char s[N];
	int a[N];
	int i, n;
	vector<int> v;

	while (scanf("%s", s) == 1) {
		if (strcmp(s, "-1") == 0) {
			break;
		}
		memset(a, 0, sizeof(a));

		n = strlen(s);
		for (i = 0; i < n; ++i) {
			a[i] = s[n - 1 - i] - '0';
		}
		for (i = 2; i <= 9; ++i) {
			n = mod(a, i);
			if (n == 0) {
				v.push_back(i);
			}
		}
		if (v.empty()) {
			printf("none\n");
		} else {
			for (i = 0; i < v.size(); ++i) {
				printf((i ? " %d" : "%d"), v[i]);
			}
			printf("\n");
		}

		v.clear();
	}

	return 0;
}