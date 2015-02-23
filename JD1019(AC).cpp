#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	char s[1000];
	char *p;
	vector<double> a;
	vector<char> op;
	double n2;
	int idx;
	char lastop;

	while (gets(s) != NULL && strcmp(s, "0")) {
		idx = 0;
		lastop = '+';
		p = strtok(s, " ");
		do {
			++idx;
			if (idx % 2) {
				sscanf(p, "%lf", &n2);
				if (lastop == '*') {
					a.back() = a.back() * n2;
					op.pop_back();
				} else if (lastop == '/') {
					a.back() = a.back() / n2;
					op.pop_back();
				} else {
					a.push_back(n2);
				}
			} else {
				op.push_back(p[0]);
				lastop = p[0];
			}
		} while ((p = strtok(NULL, " ")) != NULL);
		double res = a[0];
		for (int i = 1; i < a.size(); ++i) {
			if (op[i - 1] == '+') {
				res += a[i];
			} else if (op[i - 1] == '-') {
				res -= a[i];
			}
		}
		printf("%.2f\n", res);
		a.clear();
		op.clear();
	}

	return 0;
}