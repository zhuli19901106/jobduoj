// 651827	zhuli19901106	1513	Accepted	点击此处查看所有case的执行结果	1020KB	350B	80MS
// 201311151734
#include <cstdio>
using namespace std;

int main()
{
	int x;
	int res;
	int n;
	int i;
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &x);
			res = 0;
			while(x){
				x = (x & (x - 1));
				++res;
			}
			printf("%d\n", res);
		}
	}
	
	return 0;
}