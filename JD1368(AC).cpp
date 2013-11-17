// 652977	zhuli19901106	1368	Accepted	点击此处查看所有case的执行结果	1112KB	1552B	30MS
// 201311180013
#include <cstdio>
#include <vector>
using namespace std;

void dfs(const int a[][3], const int &n, int r, int sum, int target, vector<int> &path)
{
	if(r < 1 || r > n){
		return;
	}
	
	path.push_back(r);
	
	if(a[r][1] == -1 && a[r][2] == -1){
		if(sum + a[r][0] == target){
			// a valid path is found.
			printf("A path is found:");
			for(int i = 0; i < path.size(); ++i){
				printf(" %d", path[i]);
			}
			printf("\n");
		}
	}
	
	if(a[r][1] != -1){
		dfs(a, n, a[r][1], sum + a[r][0], target, path);
	}
	if(a[r][2] != -1){
		dfs(a, n, a[r][2], sum + a[r][0], target, path);
	}
	
	path.pop_back();
}

int main()
{
	const int MAXN = 10005;
	int n, i, k, r;
	int a[MAXN][3];
	int c[MAXN];
	vector<int> path;
	
	while(scanf("%d%d", &n, &k) == 2){
		for(i = 1; i <= n; ++i){
			c[i] = 0;
		}
		for(i = 1; i <= n; ++i){
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if(a[i][1] > 0){
				++c[a[i][1]];
			}
			if(a[i][2] > 0){
				++c[a[i][2]];
			}
			if(a[i][1] > 0 && a[i][2] > 0 && a[i][1] > a[i][2]){
				// do this swap to make sure the result is in lexicological order
				a[i][1] ^= a[i][2] ^= a[i][1] ^= a[i][2];
			}
		}
		r = -1;
		for(i = 1; i <= n; ++i){
			if(c[i] == 0){
				r = i;
				break;
			}
		}
		printf("result:\n");
		path.clear();
		dfs(a, n, r, 0, k, path);
		path.clear();
	}
	
	return 0;
}