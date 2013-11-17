// 652664	zhuli19901106	1214	Accepted	点击此处查看所有case的执行结果	1020KB	737B	10MS
// 201311171557
#include <cstdio>
using namespace std;

const int &mymin(const int &x, const int &y)
{
	return (x < y ? x : y);
}

int main()
{
	const int MAXN = 1500;
	int a[MAXN + 1];
	int p2, p3, p5;
	int r2, r3, r5;
	int minv;
	int i;
	
	a[0] = 0;
	a[1] = 1;
	p2 = p3 = p5 = 1;
	for(i = 2; i <= MAXN; ++i){
		r2 = a[p2] * 2;
		r3 = a[p3] * 3;
		r5 = a[p5] * 5;
		minv = mymin(mymin(r2, r3), r5);
		a[i] = minv;
		if(minv == r2){
			++p2;
		}
		if(minv == r3){
			++p3;
		}
		if(minv == r5){
			++p5;
		}
	}
	
	while(scanf("%d", &i) == 1){
		if(i >= 1 && i <= MAXN){
			printf("%d\n", a[i]);
		}
	}
	
	return 0;
}