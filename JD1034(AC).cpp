#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	vector<int> v;
	int i;
	int val;
	int n, m;

	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &val);
			if (m > 0) {
				pq.push(val);
				--m;
			} else if (pq.top() < val) {
				pq.pop();
				pq.push(val);
			}
		}
		while (!pq.empty()) {
			v.push_back(pq.top());
			pq.pop();
		}
		m = v.size();
		for (i = m - 1; i >= 0; --i) {
			printf((i == m - 1 ? "%d" : " %d"), v[i]);
		}
		printf("\n");
		v.clear();
	}
	
	return 0;
}