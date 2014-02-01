// 688806	zhuli19901106	1524	Accepted	点击此处查看所有case的执行结果	1160KB	3820B	50MS
// 201402012144
#include <cstdio>
#include <map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// This code segment is copied from my leetcode problem set.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        int n;
        
        if(NULL == head){
            return NULL;
        }
        
        n = 0;
        RandomListNode *ptr;
        
        mri.clear();
        mir.clear();
        
        ptr = head;
        while(ptr != NULL){
            ++n;
            mri[ptr] = n;
            ptr = ptr->next;
        }
        
        RandomListNode *root = new RandomListNode(0), *tail;
        ptr = head;
        int i = 0;
        tail = root;
        while(ptr != NULL){
            ++i;
            tail->next = new RandomListNode(ptr->label);
            tail = tail->next;
            mir[i] = tail;
            ptr = ptr->next;
        }
        
        RandomListNode *p1, *p2;
        
        p1 = head;
        p2 = root->next;
        while(p1 != NULL){
            if(p1->random != NULL){
                p2->random = mir[mri[p1->random]];
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        head = root->next;
        delete root;
        mir.clear();
        mri.clear();
        
        return head;
    }

	RandomListNode *deleteList(RandomListNode *head) {
		RandomListNode *ptr1, *ptr2;

		if (NULL == head) {
			return NULL;
		}

		ptr1 = head;
		while (ptr1 != NULL) {
			ptr2 = ptr1->next;
			delete ptr1;
			ptr1 = ptr2;
		}

		return NULL;
	}
private:
    map<RandomListNode *, int> mri;
    map<int, RandomListNode *> mir;
};

int main()
{
	map<RandomListNode *, int> mri;
	map<int, RandomListNode *> mir;
	int n, i;
	int label;
	RandomListNode *head1, *head2, *tail, *ptr;
	Solution solution;

	while (scanf("%d", &n) == 1) {
		mri.clear();
		mir.clear();
		head1 = head2 = tail = NULL;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &label);
			if (tail == NULL) {
				head1 = tail = new RandomListNode(label);
			} else {
				tail->next = new RandomListNode(label);
				tail = tail->next;
			}
			mri[tail] = i;
			mir[i] = tail;
		}

		for (i = 1; i <= n; ++i) {
			scanf("%d", &label);
			if (label > 0) {
				ptr = mir[i];
				ptr->random = mir[label];
			}
		}

		head2 = solution.copyRandomList(head1);
		ptr = head2;
		while (ptr != NULL) {
			printf("%d ", ptr->label);
			if (ptr->random != NULL) {
				printf("%d\n", ptr->random->label);
			} else {
				printf("0\n");
			}
			ptr = ptr->next;
		}

		head1 = solution.deleteList(head1);
		head2 = solution.deleteList(head2);
	}

	return 0;
}
/*
// 688773	zhuli19901106	1524	Accepted	点击此处查看所有case的执行结果	1024KB	544B	40MS
// 201402012022
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> va, vb;
	int n, i;
	int a, b;

	while (scanf("%d", &n) == 1) {
		va.clear();
		vb.clear();
		va.push_back(0);
		vb.push_back(0);
		for (i = 1; i <= n; ++i) {
			scanf("%d", &a);
			va.push_back(a);
		}
		for (i = 1; i <= n; ++i) {
			scanf("%d", &b);
			vb.push_back(b);
		}
		for (i = 1; i <= n; ++i) {
			printf("%d %d\n", va[i], va[vb[i]]);
		}
	}

	return 0;
}
*/