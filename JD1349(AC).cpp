// 652724	zhuli19901106	1349	Accepted	点击此处查看所有case的执行结果	4932KB	1913B	720MS
// 201311171831
#include <cstdio>
using namespace std;

int bsearch_left(const int a[], int n, int target)
{
	int ll, rr, mm;
	
	if(a == NULL || n <= 0){
		return -1;
	}
	
	if(target < a[0] || target > a[n - 1]){
		return -1;
	}
	
	// guarantee that a[left] < target && a[right] >= target
	if(target == a[0]){
		return 0;
	}
	
	ll = 0;
	rr = n - 1;
	while(rr - ll > 1){
		mm = (ll + rr) / 2;
		if(target > a[mm]){
			ll = mm;
		}else{
			rr = mm;
		}
	}
	
	if(a[rr] == target){
		return rr;
	}else{
		return -1;
	}
}

int bsearch_right(const int a[], int n, int target)
{
	int ll, rr, mm;
	
	if(a == NULL || n <= 0){
		return -1;
	}
	
	if(target < a[0] || target > a[n - 1]){
		return -1;
	}
	
	// guarantee that a[left] <= target && a[right] > target
	if(target == a[n - 1]){
		return n - 1;
	}
	
	ll = 0;
	rr = n - 1;
	while(rr - ll > 1){
		mm = (ll + rr) / 2;
		if(target >= a[mm]){
			ll = mm;
		}else{
			rr = mm;
		}
	}
	
	if(a[ll] == target){
		return ll;
	}else{
		return -1;
	}
}

int main()
{
	int *a = NULL;
	int i, n, m;
	int target;
	int ll, rr;
	
	while(scanf("%d", &n) == 1){
		if(n <= 0){
			continue;
		}
		a = new int[n];
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		for(i = 0; i < m; ++i){
			scanf("%d", &target);
			ll = bsearch_left(a, n, target);
			if(ll < 0){
				printf("0\n");
				continue;
			}
			rr = bsearch_right(a, n, target);
			if(rr < 0){
				printf("0\n");
				continue;
			}
			if(rr >= ll){
				printf("%d\n", rr - ll + 1);
			}else{
				printf("0\n");
			}
		}
		delete[] a;
		a = NULL;
	}
	
	return 0;
}