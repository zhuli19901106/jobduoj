#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

typedef long long int LL;

char s[20];
LL a, b;

LL getVal(char s[])
{
	LL val = 0;
	int i = 0;
	while (s[i]) {
		val = val * 26 + (s[i] - 'a');
		++i;
	}

	return val;
}

void printVal(LL x)
{
	if (x == 0) {
		printf("a");
		return;
	}
	string s = "";
	while (x) {
		s.push_back(x % 26 + 'a');
		x /= 26;
	}
	reverse(s.begin(), s.end());
	printf("%s", s.data());
	s.clear();
}

int main()
{
	int t, ti;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%s", s);
		a = getVal(s);
		scanf("%s", s);
		b = getVal(s);
		printVal(a + b);
		printf("\n");
	}

	return 0;
}