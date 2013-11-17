// 652479	zhuli19901106	1521	Accepted	点击此处查看所有case的执行结果	1036KB	2022B	0MS
// 201311170020
#include <cstdio>
using namespace std;

const int MAXN = 1005;
int a[MAXN][4];
int n;
int r;
bool first_node;

void myswap(int &a, int &b)
{
	a ^= b ^= a ^= b;
}

void mirror(int a[][4], int ra)
{
	if(a == NULL){
		return;
	}
	
	if(ra < 0 || ra > n - 1){
		return;
	}
	
	if(a[ra][1] != -1){
		mirror(a, a[ra][1]);
	}
	if(a[ra][2] != -1){
		mirror(a, a[ra][2]);
	}
	myswap(a[ra][1], a[ra][2]);
}

void preorder(const int a[][4], int ra)
{
	if(a == NULL){
		return;
	}
	
	if(ra < 0 || ra > n - 1){
		return;
	}
	
	if(first_node){
		printf("%d", a[ra][0]);
		first_node = false;
	}else{
		printf(" %d", a[ra][0]);
	}
	if(a[ra][1] != -1){
		preorder(a, a[ra][1]);
	}
	if(a[ra][2] != -1){
		preorder(a, a[ra][2]);
	}
}

int main()
{
	int i;
	char s[10];
	int x, y;
	
	while(scanf("%d", &n) == 1){
		if(n <= 0){
			printf("NULL\n");
			continue;
		}
		for(i = 0; i < n; ++i){
			a[i][0] = a[i][1] = a[i][2] = -1;
			a[i][3] = 0;
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i][0]);
		}
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			if(s[0] == 'd'){
				scanf("%d%d", &x, &y);
				a[i][1] = x - 1;
				a[i][2] = y - 1;
				++a[x - 1][3];
				++a[y - 1][3];
			}else if(s[0] == 'l'){
				scanf("%d", &x);
				a[i][1] = x - 1;
				++a[x - 1][3];
			}else if(s[0] == 'r'){
				scanf("%d", &y);
				a[i][2] = y - 1;
				++a[y - 1][3];
			}
		}
		r = -1;
		for(i = 0; i < n; ++i){
			if(a[i][3] == 0){
				if(r == -1){
					r = i;
				}else{
					r = -1;
					break;
				}
			}
		}
		if(r < 0){
			// invalid tree structure
			printf("NULL\n");
			continue;
		}
		mirror(a, r);
		first_node = true;
		preorder(a, r);
		printf("\n");
	}
	
	return 0;
}