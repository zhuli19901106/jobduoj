// 651379	zhuli19901106	1385	Accepted	点击此处查看所有case的执行结果	1024KB	1256B	0MS	
// 201311142119
#include <cstdio>
#include <vector>
using namespace std;

void construct_tree(vector<int> &a, vector<int> &b, vector<int> &c, int l1, int r1, int l2, int r2)
{
	if(l1 > r1 || l2 > r2){
		return;
	}
	
	if(r1 - l1 != r2 - l2){
		return;
	}
	
	int mid;
	int nl, nr;
	
	for(mid = l2; mid <= r2; ++mid){
		if(b[mid] == a[l1]){
			nl = mid  - l2;
			nr = r2 - mid;
			if(nl > 0){
				construct_tree(a, b, c, l1 + 1, l1 + nl, l2, mid - 1);
			}
			if(nr > 0){
				construct_tree(a, b, c, r1 - nr + 1, r1, mid + 1, r2);
			}
			c.push_back(a[l1]);
			return;
		}
	}
	
}

int main()
{
	vector<int> a, b, c;
	int n;
	int tmp;
	int i;
	
	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			b.push_back(tmp);
		}
		c.clear();
		construct_tree(a, b, c, 0, n - 1, 0, n - 1);
		a.clear();
		b.clear();
		if(c.size() < n){
			printf("No\n");
		}else{
			for(i = 0; i < n; ++i){
				printf("%d ", c[i]);
			}
			printf("\n");
		}
		c.clear();
	}
	
	return 0;
}