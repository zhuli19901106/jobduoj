#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

const int MOD = 100000;
const int MAXN = 1005;
 
int pow2[1000];

void getPow(){
	int i;

	pow2[0] = 1;
	for (i = 1; i < 1000; ++i) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
}
 
int tree[MAXN];

int findRoot(int x)
{
	if (tree[x] == -1) {
		return x;
	}

	int tmp = findRoot(tree[x]);
	tree[x] = tmp;

	return tmp;
}
 
struct Edge {
	int next;
	int cost;
};
 
vector<Edge> edge[MAXN];
bool mark[MAXN];
int dist[MAXN];
 
int main(){
	int n, m;
	int i, j;
	int p, q;
	int a, b;

	getPow();

	while (scanf("%d%d", &n, &m) == 2) {
		for (i = 0; i < n; i++) {
			edge[i].clear();
			dist[i] = -1;
			tree[i] = -1;
			mark[i] = false;
		}
		for (i = 0; i < m; i++){
			scanf("%d%d", &a, &b);
			p = findRoot(a);
			q = findRoot(b);
			if (p != q) {
				tree[p] = q;
				Edge tmp;
				tmp.next = b;
				tmp.cost = pow2[i];
				edge[a].push_back(tmp);
				tmp.next = a;
				edge[b].push_back(tmp);
			}
		}
		dist[0] = 0;

		int cnt = n;
		bool flag = false;
		int l;
		while (cnt--){
			l = 1;
			while(l < n){
				if (mark[l] == true) {
					l++;
					continue;
				}
				for (j = 0; j < edge[l].size(); j++){
					if (dist[edge[l][j].next] != -1){
						dist[l] = (dist[edge[l][j].next] + edge[l][j].cost) % MOD;
						mark[l] = true;
						flag = true;
						break;
					}
				}
				if (flag) {
					flag = false;
					break;
				} else {
					l++;
				}
			}
		}
		for (int i = 1; i < n; i++)
			printf("%d\n", dist[i]);
	}

	return 0;
}