// 654279	zhuli19901106	1505	Accepted	点击此处查看所有case的执行结果	1024KB	2044B	70MS
// 201311202124
#include <cstdio>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int _val = 0): val(_val), next(NULL){}
};

void delete_list(ListNode *head)
{
	if(head == NULL){
		return;
	}
	
	ListNode *ptr;
	
	while(head != NULL){
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

int main()
{
	ListNode *h1, *h2, *p1, *p2, *cp1, *cp2;
	int m, n;
	int tmp;
	int i;
	
	while(scanf("%d%d", &m, &n) == 2){
		h1 = h2 = NULL;
		p1 = p2 = NULL;
		for(i = 0; i < m; ++i){
			scanf("%d", &tmp);
			if(p1 == NULL){
				h1 = new ListNode(tmp);
				p1 = h1;
			}else{
				p1->next = new ListNode(tmp);
				p1 = p1->next;
			}
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			if(p2 == NULL){
				h2 = new ListNode(tmp);
				p2 = h2;
			}else{
				p2->next = new ListNode(tmp);
				p2 = p2->next;
			}
		}
		
		if(h1 == NULL || h2 == NULL){
			printf("My God\n");
		}else{
			p1 = h1;
			p2 = h2;
			if(m < n){
				for(i = 0; i < n - m; ++i){
					p2 = p2->next;
				}
			}else{
				for(i = 0; i < m - n; ++i){
					p1 = p1->next;
				}
			}

			while(p1 != NULL && p2 != NULL && p1->val != p2->val){
				p1 = p1->next;
				p2 = p2->next;
			}
			/*
			cp1 = p1;
			cp2 = p2;
			while(cp1 != NULL && cp2 != NULL){
				if(cp1->val != cp2->val){
					break;
				}else{
					cp1 = cp1->next;
					cp2 = cp2->next;
				}
			}
			if(cp1 != NULL && cp2 != NULL){
				// mismatch found here, move forward
				p1 = cp1->next;
				p2 = cp2->next;
			}else{
				break;
			}
			*/
			
			if(p1 != NULL && p2 != NULL && p1->val == p2->val){
				printf("%d\n", p1->val);
			}else{
				printf("My God\n");
			}
		}
		
		delete_list(h1);
		h1 = NULL;
		delete_list(h2);
		h2 = NULL;
	}
	
	return 0;
}