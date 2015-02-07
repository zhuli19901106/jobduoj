#include <cstdio>
using namespace std;

typedef struct Node{
	int n;
	struct Node *l, *r;

	Node(int _n = 0): n(_n), l(NULL), r(NULL) {};
}Node;

void insert(Node *&root, int val)
{
	if (root == NULL) {
		root = new Node(val);
		printf("-1\n");
		return;
	}

	Node *par, *ptr;

	par = NULL;
	ptr = root;
	while (ptr->n != val) {
		if (val < ptr->n) {
			if (ptr->l != NULL) {
				par = ptr;
				ptr = ptr->l;
			} else {
				par = ptr;
				ptr->l = new Node(val);
				break;
			}
		} else {
			if (ptr->r != NULL) {
				par = ptr;
				ptr = ptr->r;
			} else {
				par = ptr;
				ptr->r = new Node(val);
			}
		}
	}
	printf("%d\n", (par ? par->n : -1));
}

void clearTree(Node *&root)
{
	if (root == NULL) {
		return;
	}
	clearTree(root->l);
	clearTree(root->r);
	delete root;
	root = NULL;
}

int main()
{
	Node *root;
	int n, i, val;

	while (scanf("%d", &n) == 1) {
		root = NULL;
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			insert(root, val);
		}
		clearTree(root);
	}

	return 0;
}