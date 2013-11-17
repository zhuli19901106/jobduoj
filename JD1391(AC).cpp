// 652496	zhuli19901106	1391	Accepted	点击此处查看所有case的执行结果	4968KB	961B	520MS
// 201311170129
#include <cstdio>
using namespace std;

int m, n;
const int MAXN = 1005;
int a[MAXN][MAXN];

int main()
{
	int i, j;
	
	while(scanf("%d%d", &m, &n) == 2){
		if(m <= 0 || n <= 0){
			continue;
		}
		for(i = 0; i < m; ++i){
			for(j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		
		for(i = 0; (i <= m - 1 - i) && (i <= n - 1 - i); ++i){
			for(j = i; j <= n - 1 - i; ++j){
				printf("%d ", a[i][j]);
			}
			if(i + 1 <= m - 1 - i - 1){
				for(j = i + 1; j <= m - 1 - i - 1; ++j){
					printf("%d ", a[j][n - 1 - i]);
				}
			}
			if(i < m - 1 - i){
				for(j = n - 1 - i; j >= i; --j){
					printf("%d ", a[m - 1 - i][j]);
				}
			}
			if(i + 1 <= m - 1 - i && i < n - 1 - i){
				for(j = m - 1 - i - 1; j >= i + 1; --j){
					printf("%d ", a[j][i]);
				}
			}
		}
		printf("\n");
	}
	
	return 0;
}