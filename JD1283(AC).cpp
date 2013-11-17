// 652691	zhuli19901106	1283	Accepted	点击此处查看所有case的执行结果	1020KB	771B	10MS
// 201311171707
#include <cstdio>
using namespace std;

int main()
{
	const int MAXN = 10005;
	int i;
	char s[MAXN];
	int c[256];
	int min_index;
	const int EMPTY = -1;
	const int DUPLICATED = -2;
	
	while(scanf("%s", s) == 1){
		i = 0;
		for(i = 0; i < 256; ++i){
			c[i] = EMPTY;
		}
		i = 0;
		while(s[i] != '\0'){
			if(c[s[i]] == EMPTY){
				c[s[i]] = i;
			}else{
				c[s[i]] = DUPLICATED;
			}
			++i;
		}
		min_index = EMPTY;
		for(i = 0; i < 256; ++i){
			if(c[i] > 0){
				if(min_index == EMPTY){
					min_index = c[i];
				}else{
					min_index = c[i] < min_index ? c[i] : min_index;
				}
			}
		}
		printf("%d\n", min_index);
	}
	
	return 0;
}