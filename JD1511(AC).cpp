// 650320	zhuli19901106	1511	Accepted	点击此处查看所有case的执行结果	5088KB	731B	90MS
// 201311122057
#include <cstdio>
#include <vector>
using namespace std;

class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int _val = 0) : val(_val), next(NULL){}
};

int main()
{
	ListNode *root;
	ListNode *tail;
	int n;
	vector<ListNode *> vv;
	
	root = new ListNode();
	tail = root;
	vv.clear();
	while(scanf("%d", &n) == 1 && n >= 0){
		tail->next = new ListNode(n);
		tail = tail->next;
		vv.push_back(tail);
	}
	
	while(vv.size() > 0){
		printf("%d\n", vv[vv.size() - 1]->val);
		vv.pop_back();
	}
	
	tail = root;
	while(tail != NULL){
		root = tail->next;
		delete tail;
		tail = root;
	}
	
	return 0;
}