// 651848	zhuli19901106	1516	Accepted	点击此处查看所有case的执行结果	2056KB	602B	70MS
// 201311151819
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> b, c;
	int n, i, tmp;
	
	// this solution is O(n) both in time and space.
	while(scanf("%d", &n) == 1){
		b.clear();
		c.clear();
		for(i = 0; i < n; ++i){
			scanf("%d", &tmp);
			tmp % 2 ? b.push_back(tmp) : c.push_back(tmp);
		}
		for(i = 0; i < c.size(); ++i){
			b.push_back(c[i]);
		}
		c.clear();
		printf("%d", b[0]);
		for(i = 1; i < b.size(); ++i){
			printf(" %d", b[i]);
		}
		b.clear();
		printf("\n");
	}
	
	return 0;
}