// 651819	zhuli19901106	1389	Accepted	点击此处查看所有case的执行结果	1016KB	195B	0MS
// 201311151727
#include   <cstdio>
using namespace std;

int main()
{
	int n;
	
	while(scanf("%d", &n) == 1){
		printf("%lld\n", 1LL << (n - 1));
	}
	
	return 0;
}