// 652500	zhuli19901106	1522	Accepted	点击此处查看所有case的执行结果	1024KB	872B	20MS
// 201311170256
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	int i;
	int tmp;
	vector<int> st, min_st;
	char s[10];
	
	while(scanf("%d", &n) == 1){
		st.clear();
		min_st.clear();
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			if(s[0] == 's'){
				scanf("%d", &tmp);
				st.push_back(tmp);
				if(min_st.size() <= 0 || tmp <= min_st[min_st.size() - 1]){
					min_st.push_back(tmp);
				}
			}else if(s[0] == 'o'){
				if(st.size() > 0 && min_st.size() > 0){
					if(st[st.size() - 1] <= min_st[min_st.size() - 1]){
						min_st.pop_back();
					}
					st.pop_back();
				}
			}
			
			if(min_st.size() > 0){
				printf("%d\n", min_st[min_st.size() - 1]);
			}else{
				printf("NULL\n");
			}
		}
	}
	
	return 0;
}