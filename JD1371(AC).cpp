// 652996	zhuli19901106	1371	Accepted	点击此处查看所有case的执行结果	1796KB	931B	950MS
// 201311180313
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	// min heap
	priority_queue<int, vector<int>, less<int> > pq;
	vector<int> vv;
	int n, k;
	int i, tmp;
	
	while(scanf("%d%d", &n, &k) == 2){
		while(!pq.empty()){
			pq.pop();
		}
		vv.clear();
		
		if(k > n){
			k = n;
		}
		for(i = 0; i < k; ++i){
			scanf("%d", &tmp);
			pq.push(tmp);
		}
		
		for(i = k; i < n; ++i){
			scanf("%d", &tmp);
			if(tmp < pq.top()){
				pq.pop();
				pq.push(tmp);
			}
		}
		
		while(!pq.empty()){
			vv.push_back(pq.top());
			pq.pop();
		}
		
		for(i = (int)vv.size() - 1; i >= 0; --i){
			if(i == (int)vv.size() - 1){
				printf("%d", vv[i]);
			}else{
				printf(" %d", vv[i]);
			}
		}
		printf("\n");
		vv.clear();
	}
	
	return 0;
}