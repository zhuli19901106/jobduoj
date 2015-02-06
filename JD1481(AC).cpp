#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10005;
int dj[N];
int b[N];
int in[N];
int out[N];
int nc;
int out0, out1;
int caseno;

int findRoot(int x)
{
	int k, r;

	r = x;
	while (r != dj[r]) {
		r = dj[r];
	}
	k = x;
	while (x != r) {
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int x, y;
	int rx, ry;
	bool lastCase;
	bool tree;

	caseno = 0;
	lastCase = false;
	while (true) {
		memset(dj, 0, sizeof(dj));
		memset(b, 0, sizeof(b));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (x = 0; x < N; ++x) {
			dj[x] = x;
		}

		tree = true;
		nc = 0;
		while (scanf("%d%d", &x, &y) == 2) {
			if (x == -1 && y == -1) {
				lastCase = true;
				break;
			} else if (x == 0 && y == 0) {
				break;
			}

			if (!tree) {
				continue;
			}

			if (!b[x]) {
				b[x] = 1;
				++nc;
			}
			if (!b[y]) {
				b[y] = 1;
				++nc;
			}
			++in[x];
			++out[y];
			rx = findRoot(x);
			ry = findRoot(y);
			if (rx == ry) {
				// A cycle is detected
				tree = false;
			} else {
				dj[ry] = rx;
			}
		}
		if (lastCase) {
			break;
		}
		++caseno;

		if (nc == 0) {
			printf("Case %d is a tree.\n", caseno);
			continue;
		}

		out0 = out1 = 0;
		for (x = 0; x < N; ++x) {
			if (!b[x]) {
				continue;
			}
			if (out[x] == 0) {
				++out0;
			} else if (out[x] == 1) {
				++out1;
			}
		}
		if (out0 != 1 || out1 != nc - 1) {
			tree = false;
		}

		if (tree) {
			printf("Case %d is a tree.\n", caseno);
		} else {
			printf("Case %d is not a tree.\n", caseno);
		}
	}

	return 0;
}