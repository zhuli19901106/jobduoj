// 652939	zhuli19901106	1367	Accepted	点击此处查看所有case的执行结果	1020KB	1192B	10MS
// 201311172259
#include <cstdio>
using namespace std;

bool check_postorder(const int a[], int left, int right)
{
	if(a == NULL || left < 0 || right < 0 || left > right){
		return false;
	}
	
	if(left == right){
		return true;
	}
	
	int i;
	
	i = left;
	while(i <= right - 1 && a[i] < a[right]){
		++i;
	}
	if(i == right){
		// right substree is empty
		return check_postorder(a, left, right - 1);
	}else if(i == left){
		// left substree is empty
		for(; i <= right - 1; ++i){
			if(a[i] < a[right]){
				return false;
			}
		}
		return check_postorder(a, left, right - 1);
	}else{
		int pos = i;
		for(; i <= right - 1; ++i){
			if(a[i] < a[right]){
				return false;
			}
		}
		return check_postorder(a, left, pos - 1) && check_postorder(a, pos, right - 1);
	}
}

int main()
{
	const int MAXN = 10005;
	int a[MAXN];
	int n, i;
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		if(check_postorder(a, 0, n - 1)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	return 0;
}