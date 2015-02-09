#include <cstdio>
using namespace std;

typedef struct Node{
	int key;
	struct Node *left, *right;

	Node(int _key = 0): key(_key), left(NULL), right(NULL) {};
}Node;

void insert(Node *&root, int val)
{
	if (root == NULL) {
		root = new Node(val);
		return;
	}

	Node *ptr = root;
	while (ptr->key != val) {
		if (val < ptr->key) {
			if (ptr->left != NULL) {
				ptr = ptr->left;
			} else {
				ptr->left = new Node(val);
				return;
			}
		} else {
			if (ptr->right != NULL) {
				ptr = ptr->right;
			} else {
				ptr->right = new Node(val);
				return;
			}
		}
	}
}

void preorder(Node *root)
{
	if (root == NULL) {
		return;
	}
	printf("%d ", root->key);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
}

void postorder(Node *root)
{
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->key);
}

void clear(Node *&root)
{
	if (root == NULL) {
		return;
	}
	clear(root->left);
	clear(root->right);
	delete root;
	root = NULL;
}

int main()
{
	Node *root = NULL;
	int n, i, val;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			insert(root, val);
		}
		preorder(root);
		printf("\n");
		inorder(root);
		printf("\n");
		postorder(root);
		printf("\n");

		clear(root);
	}

	return 0;
}