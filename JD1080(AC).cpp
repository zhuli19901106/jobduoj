#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> a, b, r;
char s[1005];

int get(char ch)
{
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 10;
	} else {
		return 0;
	}
}

void mul(vector<int> &a, int m, int n)
{
	int i;
	
	for (i = 0; i < (int)a.size(); ++i) {
		a[i] *= m;
	}
	for (i = 0; i < (int)a.size() - 1; ++i) {
		a[i + 1] += a[i] / n;
		a[i] %= n;
	}
	a[a.size() - 1] %= n;
}

void print(const vector<int> &b)
{
	int i;
	
	i = (int)b.size() - 1;
	while (i > 0 && b[i] == 0) {
		--i;
	}
	while (i >= 0) {
		if (b[i] >= 0 && b[i] <= 9) {
			putchar(b[i] + '0');
		} else if (b[i] >= 10 && b[i] <= 35) {
			putchar(b[i] - 10 + 'a');
		}
		--i;
	}
}

int main()
{
	int i, j;
	int m, n;
	int mx, nx;
	
	while (scanf("%d%d", &m, &n) == 2) {
		scanf("%s", s);
		mx = strlen(s);
		nx = mx * 1.0 * log(m * 1.0) / log(n * 1.0) + 5;
		a.resize(mx, 0);
		b.resize(nx, 0);
		r.resize(nx, 0);
		for (i = 0; i < mx; ++i) {
			a[mx - 1 - i] = get(s[i]);
		}
		r[0] = 1;
		for (i = 0; i < (int)a.size(); ++i) {
			for (j = 0; j < (int)b.size(); ++j) {
				b[j] += a[i] * r[j];
			}
			for (j = 0; j < b.size() - 1; ++j) {
				b[j + 1] += b[j] / n;
				b[j] %= n;
			}
			b[b.size() - 1] %= n;
			mul(r, m, n);
		}
		
		print(b);
		printf("\n");
		a.clear();
		b.clear();
		r.clear();
	}
	
	return 0;
}