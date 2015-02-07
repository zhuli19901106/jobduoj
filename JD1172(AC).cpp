#include <cstdio>
#include <queue>
using namespace std;

typedef struct Node{
	int key;
	struct Node *left, *right;

	Node(int _key = 0): key(_key), left(NULL), right(NULL) {};
}Node;

struct Functor{
	bool operator () (Node *&n1, Node *&n2)
	{
		return n1->key > n2->key;
	}
};

void calcSum(Node *root, int depth, int &sum)
{
	if (root->left == NULL && root->right == NULL) {
		sum += depth * root->key;
		return;
	}
	calcSum(root->left, depth + 1, sum);
	calcSum(root->right, depth + 1, sum);
}

void clearTree(Node *&root)
{
	if (root == NULL) {
		return;
	}
	clearTree(root->left);
	clearTree(root->right);
	delete root;
	root = NULL;
}

int main()
{
	int i, n;
	priority_queue<Node *, vector<Node *>, Functor> pq;
	int val;
	int sum;
	Node *p1, *p2, *p3;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			pq.push(new Node(val));
		}
		for (i = 1; i < n; ++i) {
			p1 = pq.top();
			pq.pop();
			p2 = pq.top();
			pq.pop();
			p3 = new Node(p1->key + p2->key);
			p3->left = p1;
			p3->right = p2;
			pq.push(p3);
		}
		p1 = pq.top();
		pq.pop();
		sum = 0;
		calcSum(p1, 0, sum);
		printf("%d\n", sum);
		clearTree(p1);
	}

	return 0;
}