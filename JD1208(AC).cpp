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

void convert(vector<int> &a, vector<int> &b, int m, int n)
{
	int mx = (int)a.size();
	int nx = mx * 1.0 * log(m * 1.0) / log(n * 1.0) + 5;
	
	b.clear();
	r.clear();
	b.resize(nx, 0);
	r.resize(nx, 0);
	
	int i, j;
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
}

void reverse(vector<int> &v, int ll, int rr)
{
	int i;
	int tmp;
	
	for (i = ll; i < ll + rr - i; ++i) {
		tmp = v[i];
		v[i] = v[ll + rr - i];
		v[ll + rr - i] = tmp;
	}
}

int main()
{
	int i;
	int mx;
	
	while (scanf("%s", s) == 1) {
		mx = strlen(s);
		a.resize(mx, 0);
		for (i = 0; i < mx; ++i) {
			a[mx - 1 - i] = get(s[i]);
		}
		
		convert(a, b, 10, 2);
		mx = (int)b.size() - 1;
		while (mx > 0 && b[mx] == 0) {
			--mx;
		}
		reverse(b, 0, mx);
		convert(b, a, 2, 10);
		print(a);
		putchar('\n');
		
		a.clear();
		b.clear();
		r.clear();
	}
	
	return 0;
}