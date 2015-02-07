#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Node{
	char key;
	struct Node *left;
	struct Node *right;

	Node(char _key = 0): key(_key), left(NULL), right(NULL) {};
}Node;

int pos;
void preorder(Node *&root, char s[])
{
	if (s[pos] == '#') {
		++pos;
		root = NULL;
		return;
	}
	root = new Node(s[pos]);
	++pos;
	preorder(root->left, s);
	preorder(root->right, s);
}

void inorder(Node *root)
{
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%c ", root->key);
	inorder(root->right);
}

int main()
{
	char s[1000];
	Node *root;

	while (scanf("%s", s) == 1) {
		root = NULL;
		pos = 0;
		preorder(root, s);
		inorder(root);
		printf("\n");
	}

	return 0;
}