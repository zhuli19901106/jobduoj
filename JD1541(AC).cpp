#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1005;
typedef struct Node {
	int left, right;
	int parent;
	int size;
} Node;
Node a[N];
int n, m;

int calcSize(int root)
{
	if (root == -1) {
		return 0;
	}
	return a[root].size = calcSize(a[root].left) + calcSize(a[root].right) + 1;
}

int getSize(int x)
{
	return x == -1 ? 0 : a[x].size;
}

void rotate(int x)
{
	if (a[x].parent == -1) {
		return;
	}

	int p = a[x].parent;
	int par = a[p].parent;

	if (a[p].left == x) {
		a[p].left = a[x].right;
		a[x].right = p;

		a[x].size += getSize(a[p].right) + 1;
		a[p].size -= getSize(a[x].left) + 1;

		if (a[p].left != -1) {
			a[a[p].left].parent = p;
		}
		a[p].parent = x;
	} else {
		a[p].right = a[x].left;
		a[x].left = p;

		a[x].size += getSize(a[p].left) + 1;
		a[p].size -= getSize(a[x].right) + 1;

		if (a[p].right != -1) {
			a[a[p].right].parent = p;
		}
		a[p].parent = x;
	}

	a[x].parent = par;
	if (par == -1) {
		return;
	}

	if (a[par].left == p) {
		a[par].left = x;
	} else {
		a[par].right = x;
	}
}

int main()
{
	int x;
	int i;
	char str[100];

	while (scanf("%d", &n) == 1) {
		for (i = 1; i <= n; ++i) {
			a[i].parent = -1;
		}
		for (i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i].left, &a[i].right);
			if (a[i].left != -1) {
				a[a[i].left].parent = i;
			}
			if (a[i].right != -1) {
				a[a[i].right].parent = i;
			}
		}
		for (i = 1; i <= n; ++i) {
			if (a[i].parent == -1) {
				calcSize(i);
			}
		}
		scanf("%d", &m);
		for (i = 1; i <= m; ++i) {
			scanf("%s", str);
			scanf("%d", &x);
			if (strcmp(str, "rotate") == 0) {
				rotate(x);
			} else if (strcmp(str, "parent") == 0) {
				printf("%d\n", a[x].parent);
			} else if (strcmp(str, "size") == 0) {
				printf("%d\n", a[x].size);
			}
		}
	}

	return 0;
}