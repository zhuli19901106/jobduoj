// 651842	zhuli19901106	1514	Accepted	点击此处查看所有case的执行结果	1020KB	795B	80MS
// 201311151751
#include <cstdio>
using namespace std;

double myexp(double x, int n)
{
	if(n == 0){
		return 1;
	}else if(n < 0){
		return myexp(1.0 / x, -n);
	}else{
		if(x < 0){
			return (n % 2 ? -1 : 1) * myexp(-x, n);
		}
		double res = myexp(x, n / 2);
		if(n % 2){
			return res * res * x;
		}else{
			return res * res;
		}
	}
}

int main()
{
	int t, ti;
	double x, res;
	int n;
	
	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lf%d", &x, &n);
			if(x == 0.0){
				if(n >= 0){
					printf("%.2ef\n", 0.0);
				}else{
					printf("INF\n");
				}
			}else{
				res = myexp(x, n);
				printf("%.2ef\n", res);
			}
		}
	}
	
	return 0;
}