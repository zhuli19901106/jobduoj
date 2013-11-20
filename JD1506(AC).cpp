// 653472	zhuli19901106	1506	Accepted	点击此处查看所有case的执行结果	1020KB	1606B	50MS
// 201311190134
#include <cstdio>
using namespace std;

void add2(long long int &x, long long int &y, int i, int j, long long int &res)
{
	res += (((!!(x & (1 << i))) & (!!(y & (1 << j)))) << (i + j));
}

void add1(long long int &x, long long int &y, int i, long long int &res)
{
	add2(x, y, i, 0, res);
	add2(x, y, i, 1, res);
	add2(x, y, i, 2, res);
	add2(x, y, i, 3, res);
	add2(x, y, i, 4, res);
	add2(x, y, i, 5, res);
	add2(x, y, i, 6, res);
	add2(x, y, i, 7, res);
	add2(x, y, i, 8, res);
	add2(x, y, i, 9, res);
	add2(x, y, i, 10, res);
	add2(x, y, i, 11, res);
	add2(x, y, i, 12, res);
	add2(x, y, i, 13, res);
	add2(x, y, i, 14, res);
	add2(x, y, i, 15, res);
	add2(x, y, i, 16, res);
	add2(x, y, i, 17, res);
	add2(x, y, i, 18, res);
	add2(x, y, i, 19, res);
}

int main()
{
	long long int n;
	long long int res;
	long long int x, y;
	
	while(scanf("%lld", &n) == 1){
		res = 0;
		x = n;
		y = n + 1;
		add1(x, y, 0, res);
		add1(x, y, 1, res);
		add1(x, y, 2, res);
		add1(x, y, 3, res);
		add1(x, y, 4, res);
		add1(x, y, 5, res);
		add1(x, y, 6, res);
		add1(x, y, 7, res);
		add1(x, y, 8, res);
		add1(x, y, 9, res);
		add1(x, y, 10, res);
		add1(x, y, 11, res);
		add1(x, y, 12, res);
		add1(x, y, 13, res);
		add1(x, y, 14, res);
		add1(x, y, 15, res);
		add1(x, y, 16, res);
		add1(x, y, 17, res);
		add1(x, y, 18, res);
		add1(x, y, 19, res);
		res >>= 1;
		printf("%lld\n", res);
	}

	return 0;
}