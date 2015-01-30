#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s1[30], s2[30];
int p1[26], p2[26];
int len;
int m;

typedef struct Node {
	char letter;
	vector<Node *> child;

	Node(char _letter = 0): letter(_letter) {};
} Node;

Node *construct(int l1, int r1, int l2, int r2)
{
	Node *rt;

	rt = new Node(s1[l1]);
	if (l1 == r1) {
		return rt;
	}

	int ll1, rr1, ll2, rr2;
	Node *ch;

	ll1 = l1 + 1;
	ll2 = l2;
	rr2 = p2[s1[ll1]];
	rr1 = ll1 + rr2 - ll2;
	while (true) {
		ch = construct(ll1, rr1, ll2, rr2);
		rt->child.push_back(ch);
		if (rr1 == r1) {
			break;
		}
		ll1 = rr1 + 1;
		ll2 = rr2 + 1;
		rr2 = p2[s1[ll1]];
		rr1 = ll1 + rr2 - ll2;
	}

	return rt;
}

int comb(int n, int k)
{
	int res;
	int i;

	if (k > n / 2) {
		return comb(n, n - k);
	}

	res = 1;
	for (i = 1; i <= k; ++i) {
		res = res * (n + 1 - i) / i;
	}

	return res;
}

void preorder(Node *root, long long int &sum)
{
	int n = root->child.size();

	sum *= comb(m, n);
	int i;

	for (i = 0; i < n; ++i) {
		preorder(root->child[i], sum);
	}
}

void clearup(Node *&root)
{
	if (root == NULL) {
		return;
	}
	if (!root->child.empty()) {
		int i;

		for (i = 0; i < (int)root->child.size(); ++i) {
			clearup(root->child[i]);
		}
		root->child.clear();
	}

	delete root;
	root = NULL;
}

int main()
{
	Node *root;
	int i;
	long long int sum;

	while (scanf("%d", &m) == 1 && m) {
		scanf("%s%s", s1, s2);
		len = strlen(s1);
		for (i = 0; i < len; ++i) {
			s1[i] -= 'a';
			s2[i] -= 'a';
			p1[s1[i]] = i;
			p2[s2[i]] = i;
		}
		root = construct(0, len - 1, 0, len - 1);
		sum = 1;
		preorder(root, sum);
		printf("%lld\n", sum);
		clearup(root);
	}

	return 0;
}