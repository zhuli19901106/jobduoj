// 654348	zhuli19901106	1350	Accepted	点击此处查看所有case的执行结果	1020KB	982B	0MS
// 201311210410
#include <cstdio>
using namespace std;

int mymax(const int &a, const int &b)
{
	return a > b ? a : b;
}

int max_depth(const int a[][2], int r)
{
	if(a == NULL || r < 0){
		return 0;
	}
	
	return mymax(max_depth(a, a[r][0]), max_depth(a, a[r][1])) + 1;
}

int main()
{
	const int MAXN = 20;
	int a[MAXN][2];
	int in_degree[MAXN];
	int i, n;
	
	while(scanf("%d", &n) == 1){
		if(n < 1){
			printf("0\n");
			continue;
		}
		
		for(i = 1; i <= n; ++i){
			in_degree[i] = 0;
		}
		
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &a[i][0], &a[i][1]);
			if(a[i][0] >= 1 && a[i][0] <= n){
				++in_degree[a[i][0]];
			}
			if(a[i][1] >= 1 && a[i][1] <= n){
				++in_degree[a[i][1]];
			}
		}
		
		for(i = 1; i <= n; ++i){
			if(in_degree[i] == 0){
				break;
			}
		}
		printf("%d\n", max_depth(a, i));
	}
	
	return 0;
}