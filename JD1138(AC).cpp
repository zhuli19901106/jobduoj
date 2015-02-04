#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool zero(const vector<int> &v)
{
	return v.empty();
}

int div2(vector<int> &v)
{
	int res = v[0] & 1;
	int len = v.size();
	int i;

	for (i = len - 1; i > 0; --i) {
		v[i - 1] += 10 * (v[i] & 1);
		v[i] >>= 1;
	}
	v[i] >>= 1;

	while (!v.empty() && v.back() == 0) {
		v.pop_back();
	}

	return res;
}

int main()
{
	vector<int> a, v;
	char s[40];
	int len, i;

	while (scanf("%s", s) == 1) {
		if (strcmp(s, "0") == 0) {
			printf("0\n");
			continue;
		}
		len = strlen(s);
		for (i = 0; i < len; ++i) {
			a.push_back(s[len - 1 - i] - '0');
		}
		while (!zero(a)) {
			v.push_back(div2(a));
		}

		len = v.size();
		for (i = len - 1; i >= 0; --i) {
			putchar(v[i] + '0');
		}
		putchar('\n');

		a.clear();
		v.clear();
	}

	return 0;
}