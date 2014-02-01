// 688144	zhuli19901106	1369	Accepted	点击此处查看所有case的执行结果	1020KB	1032B	60MS
// 201401311639
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

void my_swap(char &x, char &y)
{
	char ch;

	ch = x;
	x = y;
	y = ch;
}

void my_reverse(char s[], int ll, int rr)
{
	if (ll >= rr) {
		return;
	}

	int i;
	for (i = ll; i < ll + rr - i; ++i) {
		my_swap(s[i], s[ll + rr - i]);
	}
}

bool my_next_permutation(char s[], int n)
{
	int i, j;

	for (i = n - 1; i > 0; --i) {
		if (s[i - 1] < s[i]) {
			break;
		}
	}
	if (i == 0) {
		return false;
	}
	--i;

	for (j = n - 1; j > i; --j) {
		if (s[i] < s[j]) {
			my_swap(s[i], s[j]);
			break;
		}
	}
	my_reverse(s, i + 1, n - 1);

	return true;
}

int main()
{
	char s[20];
	int n;

	while (scanf("%s", s) == 1) {
		n = strlen(s);
		sort(s, s + n);
		while (true) {
			puts(s);
			if(!my_next_permutation(s, n)) {
				break;
			}
		}
	}

	return 0;
}