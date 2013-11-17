// 652502	zhuli19901106	1523	Accepted	点击此处查看所有case的执行结果	1052KB	1528B	0MS
// 201311170443
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	const int MAXN = 1005;
	queue<int> qq;
	int i;
	int n;
	int x, y;
	int r;
	int a[MAXN][3];
	int c[MAXN];
	bool first_node;
	char s[10];
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i][0]);
			c[i] = 0;
		}
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			if(s[0] == 'd'){
				scanf("%d%d", &x, &y);
				a[i][1] = x - 1;
				a[i][2] = y - 1;
				++c[x - 1];
				++c[y - 1];
			}else if(s[0] == 'l'){
				scanf("%d", &x);
				a[i][1] = x - 1;
				a[i][2] = -1;
				++c[x - 1];
			}else if(s[0] == 'r'){
				scanf("%d", &y);
				a[i][1] = -1;
				a[i][2] = y - 1;
				++c[y - 1];
			}else{
				a[i][1] = a[i][2] = -1;
			}
		}
		
		r = -1;
		for(i = 0; i < n; ++i){
			if(c[i] == 0){
				r = i;
				break;
			}
		}
		if(r < 0){
			// invalid tree structure
			continue;
		}
		
		first_node = true;
		qq.push(r);
		while(!qq.empty()){
			x = qq.front();
			qq.pop();
			if(first_node){
				printf("%d", a[x][0]);
				first_node = false;
			}else{
				printf(" %d", a[x][0]);
			}
			if(a[x][1] != -1){
				qq.push(a[x][1]);
			}
			if(a[x][2] != -1){
				qq.push(a[x][2]);
			}
		}
		printf("\n");
		
		while(!qq.empty()){
			qq.pop();
		}
	}
	
	return 0;
}