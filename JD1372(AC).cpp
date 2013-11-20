// 653468	zhuli19901106	1372	Accepted	点击此处查看所有case的执行结果	1416KB	1021B	430MS
// 201311190100
#include <climits>
#include <cstdio>
using namespace std;

int main()
{
	int *a = NULL;
	int n, i;
	int max_v;
	int ll, rr;
	int ml, mr;
	int sum, msum;
	
	while(scanf("%d", &n) == 1 && n > 0){
		a = new int[n];
		if(a == NULL){
			return 1;
		}
		
		max_v = INT_MIN;
		ml = mr = 0;
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			if(a[i] > max_v){
				max_v = a[i];
				ml = i;
				mr = i;
			}
		}
		if(max_v <= 0){
			// no positive number in the array
			printf("%d %d %d\n", max_v, ml, mr);
		}else{
			sum = 0;
			msum = 0;
			ll = 0;
			for(i = 0; i < n; ++i){
				sum += a[i];
				if(sum < 0){
					ll = i + 1;
					sum = 0;
				}else{
					rr = i;
				}
				if(sum > msum){
					msum = sum;
					ml = ll;
					mr = rr;
				}
			}
			
			printf("%d %d %d\n", msum, ml, mr);
		}
		
		delete a;
		a = NULL;
	}
	
	return 0;
}