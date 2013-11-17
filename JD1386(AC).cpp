// 651431	zhuli19901106	1386	Accepted	点击此处查看所有case的执行结果	1020KB	374B	660MS
// 201311142223
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int min_v, v;
	
	while(scanf("%d", &n) == 1){
		if(n <= 0){
			continue;
		}
		scanf("%d", &min_v);
		for(int i = 1; i < n; ++i){
			scanf("%d", &v);
			if(v < min_v){
				min_v = v;
			}
		}
		printf("%d\n", min_v);
	}
	
	return 0;
}