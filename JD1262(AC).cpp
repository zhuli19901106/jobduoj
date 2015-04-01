#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10005;
int a[N];
int len[N];
vector<int> p[N];
vector<int> s;
int mlen;
int n;

void LIS()
{
	int i, j;

	mlen = 0;
	for (i = 0; i < n; ++i) {
		len[i] = 1;
		for (j = 0; j < i; ++j) {
			if (a[j] < a[i]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
		mlen = max(mlen, len[i]);
		p[len[i]].push_back(i);
	}

	s.push_back(p[mlen][0]);
	for (i = mlen - 1; i > 0; --i) {
		for (j = 0; j < p[i].size(); ++j) {
			if (a[p[i][j]] < a[s.back()]) {
				s.push_back(p[i][j]);
				break;
			}
		}
	}

	for (i = 1; i <= n; ++i) {
		p[i].clear();
	}
}

int main()
{
	int i;

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		LIS();
		printf("%d", a[s.back()]);
		for (i = s.size() - 2; i >= 0; --i) {
			printf(" %d", a[s[i]]);
		}
		printf("\n");
		
		s.clear();
	}

	return 0;
}