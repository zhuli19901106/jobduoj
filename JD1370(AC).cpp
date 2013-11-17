// 652983	zhuli19901106	1370	Accepted	点击此处查看所有case的执行结果	3272KB	619B	80MS
// 201311180033
#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int tmp, ans;
	int c;
	int i, n;
	map<int, int> mm; // must count the number of appearances of every element
	
	while(scanf("%d", &n) == 1){
		mm.clear();
		scanf("%d", &ans);
		mm[ans] = 1;
		c = 1;
		for(i = 1; i < n; ++i){
			scanf("%d", &tmp);
			++mm[tmp];
			if(tmp == ans){
				++c;
			}else{
				if(c > 0){
					--c;
				}else{
					ans = tmp;
					c = 1;
				}
			}
		}
		
		if(mm[ans] > n / 2){
			printf("%d\n", ans);
		}else{
			printf("-1\n");
		}
	}
	
	return 0;
}