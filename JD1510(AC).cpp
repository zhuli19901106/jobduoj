// 650328	zhuli19901106	1510	Accepted	点击此处查看所有case的执行结果	1336KB	440B	10MS
// 201311122105
#include <cstdio>
using namespace std;

int main()
{
	char s[100001];
	char t[300000];
	int i, j;
	
	while(fgets(s, sizeof(s) / sizeof(char), stdin) != NULL){
		i = j = 0;
		while(s[i]){
			if(s[i] == ' '){
				++i;
				t[j++] = '%';
				t[j++] = '2';
				t[j++] = '0';
			}else{
				t[j++] = s[i++];
			}
		}
		t[j] = 0;
		puts(t);
	}
	
	return 0;
}
