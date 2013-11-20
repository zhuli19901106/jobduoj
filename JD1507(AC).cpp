// 653474	zhuli19901106	1507	Accepted	点击此处查看所有case的执行结果	1020KB	1439B	10MS
// 201311190151
#include <cstdio>
using namespace std;

void cal_onebit(const int m, const int n, int i, int &carry, int &res)
{
	res = (res | 
		(
			(m & (1 << i)) ^ 
			(n & (1 << i)) ^ 
			(carry << i)
		)
	);
	carry = 
		(
			(m & (1 << i)) & 
			(n & (1 << i))
		) || 
		(
			(n & (1 << i)) & 
			(carry << i)
		) || 
		(
			(carry << i) & 
			(m & (1 << i))
		);
}

int main()
{
	int m, n;
	int res;
	int carry;
	
	while(scanf("%d%d", &m, &n) == 2){
		carry = 0;
		res = 0;
		cal_onebit(m, n, 0, carry, res);
		cal_onebit(m, n, 1, carry, res);
		cal_onebit(m, n, 2, carry, res);
		cal_onebit(m, n, 3, carry, res);
		cal_onebit(m, n, 4, carry, res);
		cal_onebit(m, n, 5, carry, res);
		cal_onebit(m, n, 6, carry, res);
		cal_onebit(m, n, 7, carry, res);
		cal_onebit(m, n, 8, carry, res);
		cal_onebit(m, n, 9, carry, res);
		cal_onebit(m, n, 10, carry, res);
		cal_onebit(m, n, 11, carry, res);
		cal_onebit(m, n, 12, carry, res);
		cal_onebit(m, n, 13, carry, res);
		cal_onebit(m, n, 14, carry, res);
		cal_onebit(m, n, 15, carry, res);
		cal_onebit(m, n, 16, carry, res);
		cal_onebit(m, n, 17, carry, res);
		cal_onebit(m, n, 18, carry, res);
		cal_onebit(m, n, 19, carry, res);
		cal_onebit(m, n, 20, carry, res);
		printf("%d\n", res);
	}
	
	return 0;
}