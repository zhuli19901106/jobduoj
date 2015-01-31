#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int i;
	int n;
	int val1, val2;
	int sum;
	priority_queue<int, vector<int>, greater<int> > pq;

	while (scanf("%d", &n) == 1 && n) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val1);
			pq.push(val1);
		}
		sum = 0;
		for (i = 1; i < n; ++i) {
			val1 = pq.top();
			pq.pop();
			val2 = pq.top();
			pq.pop();
			pq.push(val1 + val2);
			sum += val1 + val2;
		}
		printf("%d\n", sum);

		while (!pq.empty()) {
			pq.pop();
		}
	}

	return 0;
}