#include <cstdio>
#include <cstring>
using namespace std;

char s1[30];
char s2[30];
int p2[26];
int tr[30][2];

void fun(int l1, int r1, int l2, int r2)
{
	int rp2 = p2[s1[l1] - 'A'];
	
	if (rp2 > l2) {
		// left subtree
		tr[s1[l1] - 'A'][0] = s1[l1 + 1] - 'A';
		fun(l1 + 1, l1 + rp2 - l2, l2, rp2 - 1);
	}
	if (rp2 < r2) {
		// right subtree
		tr[s1[l1] - 'A'][1] = s1[l1 + rp2 - l2 + 1] - 'A';
		fun(l1 + rp2 - l2 + 1, r1, rp2 + 1, r2);
	}
}

void pos(int root)
{
	if (tr[root][0] != -1) {
		pos(tr[root][0]);
	}
	if (tr[root][1] != -1) {
		pos(tr[root][1]);
	}
	putchar(root + 'A');
}

int main()
{
	int i;
	int n;
	int root;
	
	while (scanf("%s%s", s1, s2) == 2) {
		n = strlen(s1);
		for (i = 0; i < n; ++i) {
			p2[s2[i] - 'A'] = i;
		}
		root = s1[0] - 'A';
		for (i = 0; i < n; ++i) {
			tr[s1[i] - 'A'][0] = tr[s1[i] - 'A'][1] = -1;
		}
		fun(0, n - 1, 0, n - 1);
		pos(root);
		putchar('\n');
	}
	
	return 0;
}