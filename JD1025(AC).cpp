#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > vt;
vector<vector<double> > vp;
int n;
double quo;
double msum;

bool validReceipt(vector<int> &t, vector<double> &p)
{
	double sum;
	int i;

	sum = 0;
	for (i = 0; i < t.size(); ++i) {
		if (t[i] < 0 || t[i] > 2) {
			return false;
		}
		if (p[i] > 600) {
			return false;
		}
		sum += p[i];
		if (sum > 1000) {
			return false;
		}
	}
	return true;
}

void dfs(int idx, double s[3], double sum)
{
	if (sum > msum) {
		msum = sum;
	}

	if (idx == n) {
		return;
	}
	dfs(idx + 1, s, sum);
	int i;
	double ss[3];

	for (i = 0; i < 3; ++i) {
		ss[i] = s[i];
	}
	for (i = 0; i < vt[idx].size(); ++i) {
		ss[vt[idx][i]] += vp[idx][i];
	}
	if (ss[0] + ss[1] + ss[2] > quo) {
		return;
	}
	dfs(idx + 1, ss, ss[0] + ss[1] + ss[2]);
}

int main()
{
	vector<int> t;
	vector<double> p;
	int m;
	int i, j;
	char str[20];
	double q;

	while (scanf("%lf%d", &quo, &n) == 2 && n > 0) {
		for (i = 0; i < n; ++i) {
			t.clear();
			p.clear();
			scanf("%d", &m);
			for (j = 0; j < m; ++j) {
				scanf("%s", str);
				sscanf(str + 2, "%lf", &q);
				t.push_back(str[0] - 'A');
				p.push_back(q);
			}
			if (validReceipt(t, p)) {
				vt.push_back(t);
				vp.push_back(p);
			}
		}
		n = vt.size();
		msum = 0;
		double p[3];
		p[0] = p[1] = p[2] = 0;
		dfs(0, p, 0);
		printf("%.2f\n", msum);

		vt.clear();
		vp.clear();
	}

	return 0;
}