// 651941	zhuli19901106	1518	Accepted	点击此处查看所有case的执行结果	1024KB	1226B	160MS
// 201311152146
#include <cstdio>
using namespace std;

struct Node{
	int val;
	struct Node *next;
	Node(int _val): val(_val), next(NULL){}
};

Node *reverse_list(Node *head)
{
	Node *root, *tail;
	
	if(head == NULL){
		return NULL;
	}
	
	root = new Node(0);
	while(head != NULL){
		tail = head->next;
		head->next = root->next;
		root->next = head;
		head = tail;
	}
	head = root->next;
	delete root;
	return head;
}

int main()
{
	Node *head, *tail, *root;
	int i, n, tmp;
	
	while(scanf("%d", &n) == 1){
		if(n <= 0){
			printf("NULL\n");
			continue;
		}
		root = new Node(0);
		tail = root;
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			tail->next = new Node(tmp);
			tail = tail->next;
		}
		head = root->next;
		head = reverse_list(head);
		root->next = head;
		printf("%d", head->val);
		tail = head->next;
		while(tail != NULL){
			printf(" %d", tail->val);
			tail = tail->next;
		}
		printf("\n");
		
		tail = root;
		while(tail != NULL){
			head = tail->next;
			delete tail;
			tail = head;
		}
	}
	
	return 0;
}