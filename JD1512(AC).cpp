// 651425	zhuli19901106	1512	Accepted	点击此处查看所有case的执行结果	1184KB	1415B	70MS
// 201311142215
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

class MyQueue{
public:
	MyQueue()
	{
	}
	
	~MyQueue()
	{
		while(!s1.empty()){
			s1.pop();
		}
		while(!s2.empty()){
			s1.pop();
		}
	}
	
	void push(int n)
	{
		s1.push(n);
	}
	
	int pop()
	{
		if(s1.size() <= 0 && s2.size() <= 0){
			// The queue is empty, return -1 to signal an error.
			return -1;
		}
		if(s2.size() > 0){
			int res = s2.top();
			s2.pop();
			return res;
		}else{
			int res;
			while(s1.size() > 1){
				res = s1.top();
				s1.pop();
				s2.push(res);
			}
			res = s1.top();
			s1.pop();
			return res;
		}
	}
	
	void clear()
	{
		while(s1.size() > 0){
			s1.pop();
		}
		while(s2.size() > 0){
			s2.pop();
		}
	}
	
	int size()
	{
		return s1.size() + s2.size();
	}
private:
	stack<int> s1, s2;
};

int main()
{
	char s[100];
	int n;
	int i;
	int tmp;
	MyQueue queue;
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			if(strcmp(s, "PUSH") == 0){
				scanf("%d", &tmp);
				queue.push(tmp);
			}else if(strcmp(s, "POP") == 0){
				printf("%d\n", queue.pop());
			}
		}
		queue.clear();
	}
	
	return 0;
}