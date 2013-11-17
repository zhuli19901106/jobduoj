// 650233	zhuli19901106	1384	Accepted	点击此处查看所有case的执行结果	4968KB	813B	690MS
// 201311121726
#include <cstdio>
using namespace std;

const int MAXN = 1005;
int a[MAXN][MAXN];
int x, y;

int main()
{
	int i, j;
	int left, right, mid;
	int target;
	
	while(scanf("%d%d", &x, &y) == 2){
		scanf("%d", &target);
		for(i = 0; i < x; ++i){
			for(j = 0; j < y; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		if(x * y <= 0){
			printf("No\n");
			continue;
		}
		left = 0;
		right = x * y - 1;
		while(left <= right){
			mid = (left + right) / 2;
			i = mid / y;
			j = mid % y;
			if(target < a[i][j]){
				right = mid - 1;
			}else if(target > a[i][j]){
				left = mid + 1;
			}else{
				break;
			}
		}
		
		printf((left <= right) ? "Yes\n" : "No\n");
	}
	
	return 0;
}