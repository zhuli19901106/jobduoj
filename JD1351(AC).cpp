// 652741	zhuli19901106	1351	Accepted	点击此处查看所有case的执行结果	4540KB	799B	790MS
// 201311171920
#include <cstdio>
using namespace std;

int main()
{
	int *a = NULL;
	int n, i;
	int r1, r2;
	int r;
	int bit;
	
	while(scanf("%d", &n) == 1){
		if(n <= 0){
			continue;
		}
		
		a = new int[n];
		
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		r = 0;
		for(i = 0; i < n; ++i){
			r ^= a[i];
		}
		// not necessarily the lowbit, any bit with value '1' can be the pivot bit.
		bit = r & (-r);
		
		r1 = r2 = 0;
		for(i = 0; i < n; ++i){
			if((a[i] & bit) != 0){
				r1 ^= a[i];
			}else{
				r2 ^= a[i];
			}
		}
		
		if(r1 > r2){
			r1 ^= r2 ^= r1 ^= r2;
		}
		
		printf("%d %d\n", r1, r2);
		
		delete[] a;
		a = NULL;
	}
	
	return 0;
}