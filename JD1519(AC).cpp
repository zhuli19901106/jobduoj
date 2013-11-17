// 651961	zhuli19901106	1519	Accepted	点击此处查看所有case的执行结果	1024KB	1802B	230MS
// 201311152213
#include <cstdio>
using namespace std;

struct Node{
	int val;
	struct Node *next;
	Node(int _val = 0): val(_val), next(NULL){}
};

int main()
{
	int n, m;
	int i, tmp;
	struct Node *h1, *h2, *h3;
	struct Node *p1, *p2, *p3;
	struct Node *r1, *r2, *r3;
	
	while(scanf("%d%d", &n, &m) == 2){
		if(n <= 0 && m <= 0){
			printf("NULL\n");
			continue;
		}
		r1 = new Node(0);
		r2 = new Node(0);
		r3 = new Node(0);
		
		p1 = r1;
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			p1->next = new Node(tmp);
			p1 = p1->next;
		}
		h1 = r1->next;

		p2 = r2;
		for(i = 0; i < m; ++i){
			scanf("%d", &tmp);
			p2->next = new Node(tmp);
			p2 = p2->next;
		}
		h2 = r2->next;
		
		p3 = r3;
		while(h1 != NULL && h2 != NULL){
			if(h1->val < h2->val){
				p1 = h1->next;
				p3->next = h1;
				p3 = p3->next;
				p3->next = NULL;
				h1 = p1;
			}else{
				p2 = h2->next;
				p3->next = h2;
				p3 = p3->next;
				p3->next = NULL;
				h2 = p2;
			}
		}
		
		while(h1 != NULL){
			p1 = h1->next;
			p3->next = h1;
			p3 = p3->next;
			p3->next = NULL;
			h1 = p1;
		}
		
		while(h2 != NULL){
			p2 = h2->next;
			p3->next = h2;
			p3 = p3->next;
			p3->next = NULL;
			h2 = p2;
		}
		
		h3 = r3->next;
		printf("%d", h3->val);
		p3 = h3->next;
		while(p3 != NULL){
			printf(" %d", p3->val);
			p3 = p3->next;
		}
		printf("\n");
		
		while(r3->next != NULL){
			p3 = r3->next;
			r3->next = p3->next;
			delete p3;
		}
		
		delete r1;
		delete r2;
		delete r3;
		r1 = r2 = r3 = NULL;
	}
	
	return 0;
}