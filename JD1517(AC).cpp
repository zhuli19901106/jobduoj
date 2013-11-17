// 651911	zhuli19901106	1517	Accepted	点击此处查看所有case的执行结果	1552KB	1018B	100MS
// 201311152057
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
	int val;
	struct Node *next;
	Node(int _val = 0): val(_val), next(NULL){}
};

int main()
{
	int n, k, i;
	int tmp;
	struct Node *root = NULL;
	struct Node *tail;
	struct Node *p1, *p2;
	
	root = new Node(0);
	while(scanf("%d%d", &n, &k) == 2){
		tail = root;
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			tail->next = new Node(tmp);
			tail = tail->next;
		}
		
		if(k > n || k < 1 || root->next == NULL){
			printf("NULL\n");
			continue;
		}
		
		p1 = p2 = root->next;
		while(k > 0 && p1 != NULL){
			--k;
			p1 = p1->next;
		}
		while(p1 != NULL){
			p1 = p1->next;
			p2 = p2->next;
		}
		printf("%d\n", p2->val);
		
		while(root->next != NULL){
			tail = root->next;
			root->next = tail->next;
			delete tail;
		}
	}
	
	delete root;
	root = NULL;
	
	return 0;
}