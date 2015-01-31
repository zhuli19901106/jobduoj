#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void process(string &s, int &a, int &b, int &c)
{
	a = b = c = 0;
	if (s[0] != '+' && s[0] != '-') {
		s = "+" + s;
	}

	vector<string> v;
	vector<char> op;
	int i, j, len;

	i = 0;
	len = s.length();
	while (i < len) {
		op.push_back(s[i]);
		j = i + 1;
		while (j < len && s[j] != '+' && s[j] != '-') {
			++j;
		}
		v.push_back(s.substr(i + 1, j - i - 1));
		i = j;
	}

	int n = v.size();
	int val;
	for (i = 0; i < n; ++i) {
		len = v[i].length();
		if (len >= 3 && v[i][len - 3] == 'x' && v[i][len - 2] == '^' && v[i][len - 1] == '2') {
			v[i] = v[i].substr(0, len - 3);
			if (v[i].length() == 0) {
				val = 1;
			} else {
				sscanf(v[i].data(), "%d", &val);
			}
			val = op[i] == '-' ? -val : val;
			a += val;
		} else if (len >= 1 && v[i][len - 1] == 'x') {
			v[i] = v[i].substr(0, len - 1);
			if (v[i].length() == 0) {
				val = 1;
			} else {
				sscanf(v[i].data(), "%d", &val);
			}
			val = op[i] == '-' ? -val : val;
			b += val;
		} else {
			sscanf(v[i].data(), "%d", &val);
			val = op[i] == '-' ? -val : val;
			c += val;
		}
	}

	v.clear();
	op.clear();
}

int main()
{
	int i;
	int len;
	char str[100];
	string s;
	string s1, s2;
	int a1, b1, c1, a2, b2, c2;
	double x1, x2;

	while (scanf("%s", str) == 1) {
		s = string(str);
		len = s.length();
		for (i = 0; i < len; ++i) {
			if (s[i] == '=') {
				break;
			}
		}
		s1 = s.substr(0, i);
		s2 = s.substr(i + 1, len - i - 1);
		process(s1, a1, b1, c1);
		process(s2, a2, b2, c2);
		double a = a1 - a2;
		double b = b1 - b2;
		double c = c1 - c2;
		double delta = b * b - 4 * a * c;
		
		if (delta < 0) {
			printf("No Solution\n");
		} else {
			x1 = (-b + sqrt(delta)) / (2.0 * a);
			x2 = (-b - sqrt(delta)) / (2.0 * a);
			if (x1 > x2) {
				swap(x1, x2);
			}
			printf("%.2f %.2f\n", x1, x2);
		}
	}

	return 0;
}