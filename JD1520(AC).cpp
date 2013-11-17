// 652327	zhuli19901106	1520	Accepted	点击此处查看所有case的执行结果	1048KB	2486B	10MS
// 201311162044
#include <cstdio>
using namespace std;

const int MAXN = 1005;
int a[MAXN][3];
int b[MAXN][3];
int c[MAXN];
int na, nb;
int ra, rb;

bool is_subtree(const int a[][3], const int b[][3], int ia, int ib)
{
	if(a == NULL || b == NULL){
		return false;
	}
	if(ia < 0 || ia > na - 1){
		return false;
	}
	if(ib < 0 || ib > nb - 1){
		return false;
	}
	
	if(a[ia][0] == b[ib][0]){
		bool ret1, ret2;
		
		if(b[ib][1] != -1){
			ret1 = is_subtree(a, b, a[ia][1], b[ib][1]);
		}else{
			ret1 = true;
		}

		if(b[ib][2] != -1){
			ret2 = is_subtree(a, b, a[ia][2], b[ib][2]);
		}else{
			ret2 = true;
		}
		
		return (ret1 && ret2);
	}else{
		return false;
	}
}

int main()
{
	int i, j;
	int x, y;
	
	while(scanf("%d%d", &na, &nb) == 2){
		for(i = 0; i < na; ++i){
			for(j = 0; j < 3; ++j){
				a[i][j] = -1;
			}
		}
		for(i = 0; i < nb; ++i){
			for(j = 0; j < 3; ++j){
				b[i][j] = -1;
			}
		}
		
		for(i = 0; i < na; ++i){
			scanf("%d", &x);
			a[i][0] = x;
			c[i] = 0;
		}
		for(i = 0; i < na; ++i){
			scanf("%d", &j);
			if(j == 1){
				scanf("%d", &x);
				a[i][1] = x - 1;
				++c[x - 1];
			}else if(j == 2){
				scanf("%d%d", &x, &y);
				a[i][1] = x - 1;
				a[i][2] = y - 1;
				++c[x - 1];
				++c[y - 1];
			}
		}
		ra = -1;
		for(i = 0; i < na; ++i){
			if(c[i] == 0){
				ra = i;
			}
		}

		for(i = 0; i < nb; ++i){
			scanf("%d", &x);
			b[i][0] = x;
			c[i] = 0;
		}
		for(i = 0; i < nb; ++i){
			scanf("%d", &j);
			if(j == 1){
				scanf("%d", &x);
				b[i][1] = x - 1;
				++c[x - 1];
			}else if(j == 2){
				scanf("%d%d", &x, &y);
				b[i][1] = x - 1;
				b[i][2] = y - 1;
				++c[x - 1];
				++c[y - 1];
			}
		}
		rb = -1;
		for(i = 0; i < nb; ++i){
			if(c[i] == 0){
				rb = i;
			}
		}
		
		// you can't put this if() up front, if na > 0 && nb == 0, then the input data for a is ignored
		if(na <= 0 || nb <= 0){
			printf("NO\n");
			continue;
		}
		
		if(ra == -1 || rb == -1){
			// there is at least one invalid tree
			printf("NO\n");
			continue;
		}
		
		for(i = 0; i < na; ++i){
			if(is_subtree(a, b, i, rb)){
				break;
			}
		}
		if(i < na){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}