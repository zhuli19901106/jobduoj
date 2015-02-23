#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	char key;
	Node *left;
	Node *right;

	Node(char _key = 0): key(_key), left(NULL), right(NULL) {};
} Node;

void insert(Node *&r, char c)
{
	if (r == NULL) {
		r = new Node(c);
		return;
	}
	Node *p;

	p = r;
	while (p->key != c) {
		if (c < p->key) {
			if (p->left == NULL) {
				p->left = new Node(c);
			}
			p = p->left;
		} else {
			if (p->right == NULL) {
				p->right = new Node(c);
			}
			p = p->right;
		}
	}
}

Node *getBST(const string &s)
{
	int len, i;
	Node *r;

	r = NULL;
	len = s.length();
	for (i = 0; i < len; ++i) {
		insert(r, s[i]);
	}

	return r;
}

bool treeEqual(Node *r1, Node *r2)
{
	if (r1 == NULL) {
		return r2 == NULL;
	}

	if (r2 == NULL || r2->key != r1->key) {
		return false;
	}

	return treeEqual(r1->left, r2->left) && treeEqual(r1->right, r2->right);
}

void clearTree(Node *&r)
{
	if (r == NULL) {
		return;
	}
	clearTree(r->left);
	clearTree(r->right);
	delete r;
	r = NULL;
}

int main()
{
	string s1, s2;
	int i, n;
	Node *r1, *r2;

	while (cin >> n && n) {
		cin >> s1;
		r1 = getBST(s1);
		for (i = 0; i < n; ++i) {
			cin >> s2;
			r2 = getBST(s2);
			cout << (treeEqual(r1, r2) ? "YES" : "NO") << endl;
			clearTree(r2);
		}
		clearTree(r1);
	}

	return 0;
}