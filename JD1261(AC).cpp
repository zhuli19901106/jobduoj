#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int num[11000];

int TriSearch(int *num, int n, int left, int right)
{
	int mid=0, midmid;
	
	while (left < right) {
		if(left+1 == right) {
			return max(num[left], num[right]);
		}
		mid = (left + right) / 2;
		if(mid+1 == right) {
			midmid = (mid+right)/2+1;
		} else {
			midmid = (mid + right) / 2;
		}
		if (midmid == right) {
			return max(num[left], max(num[mid], num[right]));
		}
		if (num[mid] >= num[midmid]) {
			right = midmid;
		} else {
			left = mid;
		}
	}
	return num[mid];
}
 
int main()
{
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &num[i]);
		}
		int ans = TriSearch(num, n, 0, n - 1);
		printf("%d\n", ans);
	}
}