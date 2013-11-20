// 653883	zhuli19901106	1361	Accepted	点击此处查看所有case的执行结果	1020KB	870B	50MS
// 201311192201
#include <cstdio>
#include <cstring>
using namespace std;

void reverse(char s[], int ll, int rr)
{
	int i;
	char tmp;
	
	if(s == NULL || ll < 0 || rr < 0 || ll >= rr){
		return;
	}
	i = ll;
	while(i < ll + rr - i){
		tmp = s[i];
		s[i] = s[ll + rr - i];
		s[ll + rr - i] = tmp;
		++i;
	}
}

int main()
{
	const int MAX_LEN = 50005;
	char s[MAX_LEN];
	int len;
	int i, j;
	
	// fgets() return PE, gets() return AC, why?
	while(gets(s) != NULL){
		len = strlen(s);
		reverse(s, 0, len - 1);
		i = 0;
		while(true){
			while(i < len && s[i] == ' '){
				++i;
			}
			if(i >= len){
				break;
			}
			j = i;
			while(j < len && s[j] != ' '){
				++j;
			}
			reverse(s, i, j - 1);
			i = j;
			if(i >= len){
				break;
			}
		}
		puts(s);
	}
	
	return 0;
}