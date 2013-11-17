// 652789	zhuli19901106	1354	Accepted	点击此处查看所有case的执行结果	1032KB	787B	80MS
// 20131172038
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int x, y;
	int tmp;
	int s;
	int res_count;
	int i;
	
	while(scanf("%d", &s) == 1 && s >= 0){
		if(s < 3){
			printf("Pity!\n#\n");
			continue;
		}
		
		s *= 2;
		x = (int)sqrt(s);
		res_count = 0;
		while(x >= 2){
			if(s % x == 0){
				y = s / x;
				if(y - x + 1 > 0 && ((y - x + 1) & 0x1) == 0){
					++res_count;
					tmp = (y - x + 1) >> 1;
					printf("%d", tmp);
					for(i = tmp + 1; i < tmp + x; ++i){
						printf(" %d", i);
					}
					printf("\n");
				}
			}
			// watch out for the result order
			--x;
		}
		if(res_count <= 0){
			printf("Pity!\n");
		}
		printf("#\n");
	}
	
	return 0;
}