// 651843	zhuli19901106	1515	Accepted	点击此处查看所有case的执行结果	1016KB	297B	40MS
// 201311151754
#include <cstdio>
using namespace std;

int main()
{
	int i;
	int n, N;
	
	while(scanf("%d", &n) == 1){
		N = 1;
		for(i = 0; i < n; ++i){
			N *= 10;
		}
		--N;
		for(i = 1; i <= N; ++i){
			printf("%d\n", i)
		}
	}
	
	return 0;
}