// 690545	zhuli19901106	1503	Accepted	点击此处查看所有case的执行结果	1024KB	2642B	70MS
// 201402041916
//#define MY_DEBUG
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct st{
public:
	int key;
	struct st *ll;
	struct st *rr;
	st(int _key): key(_key) {}
}st;

void convertBSTtoDoubleLinkedList(st *root, st *&left_most, st *&right_most)
{
	if (root == NULL) {
		return;
	}

	if (root->ll == NULL && root->rr == NULL) {
		left_most = root;
		right_most = root;
	}

	st *pll = NULL, *plr = NULL, *prl = NULL, *prr = NULL;
	if (root->ll != NULL) {
		convertBSTtoDoubleLinkedList(root->ll, pll, plr);
	} else {
		pll = plr = root;
	}
	if (root->rr != NULL) {
		convertBSTtoDoubleLinkedList(root->rr, prl, prr);
	} else {
		prl = prr = root;
	}
	left_most = pll;
	right_most = prr;
	if (plr != root) {
		plr->rr = root;
		root->ll = plr;
	}
	if (prl != root) {
		prl->ll = root;
		root->rr = prl;
	}
}

void constructBST(st *&root)
{
	int tmp;

	scanf("%d", &tmp);
	if (tmp == 0) {
		root = NULL;
	} else {
		root = new st(tmp);
		constructBST(root->ll);
		constructBST(root->rr);
	}
}

#ifdef MY_DEBUG
void postorderTraversal(const st *root)
{
	if (root == NULL) {
		return;
	}
	postorderTraversal(root->ll);
	postorderTraversal(root->rr);
	printf("%d ", root->key);
}
#endif

st *deleteList(st *head)
{
	if (NULL == head) {
		return head;
	}
	st *ptr1, *ptr2;

	ptr1 = head;
	while (ptr1 != NULL) {
		ptr2 = ptr1;
		ptr1 = ptr1->rr;
		delete ptr2;
	}

	return NULL;
}

st *deleteTree(st *root)
{
	if (NULL == root) {
		return NULL;
	}
	if (root->ll != NULL) {
		root->ll = deleteTree(root->ll);
	}
	if (root->rr != NULL) {
		root->rr = deleteTree(root->rr);
	}
	delete root;
	return NULL;
}

int main()
{
	int cc, ci;
	st *root = NULL;
	st *left_most, *right_most, *ptr;

	while (scanf("%d", &cc) == 1) {
		for (ci = 0; ci < cc; ++ci) {
			root = NULL;
			constructBST(root);

			// used to verify the tree
			#ifdef MY_DEBUG
			postorderTraversal(root);
			printf("\n");
			#endif

			left_most = right_most = NULL;
			convertBSTtoDoubleLinkedList(root, left_most, right_most);
			ptr = left_most;
			while (ptr != NULL) {
				printf("%d ", ptr->key);
				ptr = ptr->rr;
			}
			printf("\n");
			deleteList(left_most);
			root = left_most = right_most = NULL;
		}
	}

	return 0;
}